#include "ui_tienda.h"
#include "ui_ui_tienda.h"
#include "ui_tienda_agregar.h"
#include "ui_vitrina_agregar.h"
#include "ui_item_posicion.h"
#include "vitrina/ui_almacen.h"
#include "empresa.h"
//#include "ui_datos_empresa.h"
#include "ui_agregar_empresa.h"
//#include "sesion.h"
#include "mainwindow.h"
#include <QtGui>
#include "vitrina/tienda.h"
#include "vitrina/object_Empresa.h"
#include <QInputDialog>
#include <QMessageBox>
class c_tienda;
ui_tienda::ui_tienda(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_tienda)
{
    ui->setupUi(this);    
    actualizar_combo_empresa();    
    caso=false;    toVitrina=false;
    habilitar_botones();    
    //actual=Empresa;
    ui->pushButton_aceptar_traspaso->hide();    
    ui->pushButton_reponer->setEnabled(false);
    ui->lineEdit_cod_reponer->setEnabled(false);
    ui->label_cod->setEnabled(false);
}

ui_tienda::~ui_tienda()
{
    delete ui;
}
void ui_tienda::actualizar_combo_empresa()
{
    flag = false;
    object_Empresa empresas;    
    QSqlQueryModel* model = empresas.mf_show();
    ui->comboBox_empresa->clear();

    for(int i=0;i<model->rowCount();i++)
    {
        ui->comboBox_empresa->addItem(model->record(i).value(1).toString());
        Empresas[model->record(i).value(1).toString()] = model->record(i).value(0).toString();
    }

    flag = true;
    if(model->rowCount()>0)
    {
        idEmpresa = Empresas[ui->comboBox_empresa->currentText()];
        this->actualizar_combo_tienda(idEmpresa);
    }


}

void ui_tienda::actualizar_combo_tienda(QString empresa)
{

    if(empresa.size() > 0)
    {
        flag = false;
        ui->comboBox_tienda->clear();
        object_Tienda tienda;
        QSqlQueryModel* model = tienda.mf_show(empresa);        

        for(int i=0;i<model->rowCount();i++)
        {
            ui->comboBox_tienda->addItem(model->record(i).value(1).toString());
            Tiendas[model->record(i).value(1).toString()] = model->record(i).value(0).toString();
        }


        flag = true;
        if(model->rowCount()>0)
        {
            idTienda = Tiendas[ui->comboBox_tienda->currentText()];
            this->actualizar_combo_vitrina(idTienda);
        }
    }

}

void ui_tienda::actualizar_grilla_productos()
{
    actualizar_grilla();
}

void ui_tienda::remove_producto()
{
    //BORRANDO CELDA
    QString key = QString::number(current_index.row()+1)+"-"+QString::number(current_index.column()+1);
    object_Producto_has_Vitrina producto_vitrina;
    producto_vitrina.mf_set_idProducto_has_Vitrina(idVitrina_Producto[key]);
    if(!producto_vitrina.mf_remove())
    {
        QMessageBox msgBox;
        msgBox.setText("No se logro retirar");
        msgBox.exec();
        return;
     }

    actualizar_grilla();
    ui->pushButton_aceptar_traspaso->hide();

}

void ui_tienda::actualizar_combo_vitrina(QString vitrin)
{
    flag = false;
    ui->comboBox_vitrina->clear();
    QSqlQuery query;
    query.prepare("SELECT Ubicacion_idUbicacion,nombre FROM Vitrina WHERE Tienda_idTienda=?");
    query.bindValue(0,vitrin);
    query.exec();
    int c = 0;
    while(query.next())
    {
        Vitrinas[query.value(1).toString()] = query.value(0).toString();
        ui->comboBox_vitrina->insertItem(c++,query.value(1).toString());
    }
    flag = true;
    if(c>0)
    {
        idVitrina = Vitrinas[ui->comboBox_vitrina->currentText()];
        this->actualizar_combo_niveles(idVitrina);
    }
}

void ui_tienda::actualizar_combo_niveles(QString vitrin)
{
    flag = false;
    ui->comboBox_niveles->clear();
    QSqlQuery query;
    query.prepare("SELECT numeroNivel FROM Vitrina WHERE Ubicacion_idUbicacion=?");
    query.bindValue(0,vitrin);
    query.exec();
    query.next();

    int niveles = query.value(0).toInt();
    for(int i=0;i<niveles;i++)
    {
       //c=i+1;
        QString str;
        ui->comboBox_niveles->insertItem(i,str.append(QString("%1").arg(i+1)));
    }
    flag = true;
    this->on_comboBox_niveles_currentIndexChanged(0);

}

void ui_tienda::limpiar_grilla()
{
    ui->grilla->clear();
}

void ui_tienda::set_dimension_grilla()      //podria recibir de frente filas y columnas
{
    limpiar_grilla();
    QSqlQuery query;
    query.prepare("SELECT numeroFila,numeroColumna FROM Vitrina WHERE Ubicacion_idUbicacion=?");
    query.bindValue(0,idVitrina);
    query.exec();    query.next();

    int fila = query.value(0).toInt();
    int columna = query.value(1).toInt();

    ui->grilla->setColumnCount(columna);
    ui->grilla->setRowCount(fila);
}

void ui_tienda::actualizar_grilla()
{
    ui->grilla->clear();
    idProductos.clear();
    idVitrina_Producto.clear();
    estado.clear();
    comentario.clear();
    cod_producto.clear();
    descripcion.clear();
    marca.clear();
    costo.clear();

    QSqlQuery query;
    query.prepare("SELECT Producto_idProducto,fila,columna,idProducto_has_Vitrina,estado,comentario,codigo,descripcion,precioVenta,Marca.nombre FROM Producto_has_Vitrina INNER JOIN Producto INNER JOIN Marca WHERE Producto_has_Vitrina.Producto_idProducto = Producto.idProducto AND Vitrina_Ubicacion_idUbicacion=? AND nivel=? AND Producto.Marca_idMarca = Marca.idMarca");
    query.bindValue(0,idVitrina);
    query.bindValue(1,actual_nivel);
    query.exec();

    while(query.next())
    {
        QString idproducto = query.value(0).toString();
        int pos_fila = query.value(1).toInt();
        int pos_columna = query.value(2).toInt();
        QString state = query.value(4).toString();
        QString key = QString::number(pos_fila)+"-"+QString::number(pos_columna);
        idProductos[key] = idproducto;    
        idVitrina_Producto[key] = query.value(3).toString();
        estado[key] = state;
        comentario[key] = query.value(5).toString();       
        QString codigo=query.value(6).toString();
        cod_producto[key] = codigo;
        QString act_descripcion=query.value(7).toString();
        descripcion[key]=act_descripcion;
        costo[key] = query.value(8).toString();
        marca[key] = query.value(9).toString();
        if(state == "P"){
            ui->grilla->setItem(pos_fila-1,pos_columna-1,new QTableWidgetItem(codigo+"-"+act_descripcion));

        }
        if(state == "V"){
            ui->grilla->setItem(pos_fila-1,pos_columna-1,new QTableWidgetItem("Vendido"));

        }
    }
}

void ui_tienda::habilitar_botones()
{
    if(caso)
    {
        /*ui->btnAgregar->close();
        ui->btnDeshabilitar->close();
        ui->btnEditar->close();*/
        ui->btnImprimir->close();
        ui->pushButton_traspaso->close();
        ui->button_traspaso_almacen->close();
        ui->pushButton_etiqueta->setEnabled(false);
    }

}

//ACCION CUANDO CAMBIA LOS COMBOS
void ui_tienda::changeActual(lbls num)
{
    /*
    if(flag)
    {
        switch(ui_tienda::actual)
        {
            case Empresa:
                ui->lblEmpresa->setStyleSheet("QLabel { color:black }"); break;

            case Tienda:
                ui->lblTienda->setStyleSheet("QLabel { color:black }");  break;

            case Vitrina:
                ui->lblVitrina->setStyleSheet("QLabel { color:black }"); break;
        }

        ui_tienda::actual=num;
        switch(ui_tienda::actual)
        {
            case Empresa:
                ui->lblEmpresa->setStyleSheet("QLabel { color:red }"); break;

            case Tienda:
                ui->lblTienda->setStyleSheet("QLabel { color:red }");  break;

            case Vitrina:
                ui->lblVitrina->setStyleSheet("QLabel { color:red }"); break;
        }
    }*/
}

void ui_tienda::on_comboBox_empresa_currentIndexChanged(const QString &arg1)
{
    if(flag)
    {
        set_idEmpresa(Empresas[arg1]);
        actualizar_combo_tienda(get_idEmpresa());
    }
}

void ui_tienda::on_comboBox_tienda_currentIndexChanged(const QString &arg1)
{
    if(flag)
    {
        set_idTienda(Tiendas[arg1]);
        actualizar_combo_vitrina(get_idTienda());
    }
}

void ui_tienda::on_comboBox_vitrina_currentIndexChanged(const QString &arg1)
{
    if(flag)
    {
        set_idVitrina(Vitrinas[arg1]);
        actualizar_combo_niveles(get_idVitrina());
    }
}


void ui_tienda::on_comboBox_niveles_currentIndexChanged(int index)
{
    if(flag)
    {
        set_actual_nivel(index+1);
        set_dimension_grilla();
        actualizar_grilla();
    }
}


//BOTONES DE TIENDA
void ui_tienda::agregarTienda(bool b)
{

    //BOOL FALSE EDITAR, TRUE NUEVA TIENDA
    if(get_idEmpresa().compare("")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("Debe seleccionarse una Empresa válida!");
        msgBox->exec();
    }
    else
    {

        tienda_agregar = new ui_tienda_agregar;
        connect(tienda_agregar,SIGNAL(actualizarParent(QString)),this,SLOT(actualizar_combo_tienda(QString)));
        tienda_agregar->set_idEmpresa(get_idEmpresa());
        tienda_agregar->set_idTienda(idTienda);
        if(b)
            tienda_agregar->setWindowTitle("Agregar Tienda");
        else
            tienda_agregar->setWindowTitle("Editar Tienda");
        tienda_agregar->set_caso(b);

        tienda_agregar->show();
    }
}

void ui_tienda::deshabilitarTienda()
{
    if(get_idTienda().compare("")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("Debe seleccionarse una Tienda válida!");
        msgBox->exec();
    }
    else
    {
        /*tienda*del=new tienda(get_idTienda(),"","","","","","");

        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Confirmar");
        msgBox->setText("Desea eliminar la Tienda?");
        msgBox->setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setButtonText(QMessageBox::Cancel,"Cancelar");

        int ret = msgBox->exec();

        switch(ret)
        {
            case QMessageBox::Ok:
                del->eliminar();
                actualizar_combo_tienda(idEmpresa);
                break;
            case QMessageBox::Cancel:
                break;
        }*/
    }
}



//BOTONES DE VITRINA
void ui_tienda::agregarVitrina(bool b)
{
    if(get_idTienda().compare("")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("Debe seleccionarse una Vitrina válida!");
        msgBox->exec();
    }
    else
    {
        ui_vitrina_agregar * vitrina_agregar=new ui_vitrina_agregar;
        vitrina_agregar->set_idTienda(get_idTienda());
        vitrina_agregar->set_ui_tienda_actual(this);
        vitrina_agregar->set_caso(b);
        vitrina_agregar->setWindowTitle("Vitrina");
        vitrina_agregar->show();
    }
}

void ui_tienda::deshabilitarVitrina()
{
    if(get_idVitrina().compare("")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("Debe seleccionarse una Vitrina válida!");
        msgBox->exec();
    }
    else
    {
        vitrina*del=new vitrina(get_idVitrina(),"","",0,0,0,0);
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Confirmar");
        msgBox->setText("Desea eliminar la Vitrina?");
        msgBox->setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setButtonText(QMessageBox::Cancel,"Cancelar");

        int ret = msgBox->exec();

        switch(ret)
        {
            case QMessageBox::Ok:
                del->eliminar();
                actualizar_combo_vitrina(idTienda);
                break;
            case QMessageBox::Cancel:
                break;
        }
    }
}

void ui_tienda::agregarEmpresa(bool b)
{
    add_empresa = new ui_agregar_empresa;
    connect(add_empresa,SIGNAL(actualizarParent()),this,SLOT(actualizar_combo_empresa()));
    add_empresa->show();    
    add_empresa->set_behavior(b);

    if (!b)
    {
        add_empresa->setWindowTitle("Editar Empresa");
        add_empresa->set_idEmpresa(get_idEmpresa());
        add_empresa->update_form();

    }
    else
        add_empresa->setWindowTitle("Agregar Empresa");
    add_empresa->show();
}
void ui_tienda::deshabilitarEmpresa()
{
    if(get_idEmpresa().compare("")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("Debe seleccionarse una empresa");
        msgBox->exec();
    }
    else
    {
        empresa *del=new empresa;
        del->setId(get_idEmpresa());
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Confirmar");
        msgBox->setText("Desea eliminar la empresa?");
        msgBox->setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setButtonText(QMessageBox::Cancel,"Cancelar");

        int ret = msgBox->exec();

        switch(ret)
        {
            case QMessageBox::Ok:
                del->eliminar();
                actualizar_combo_empresa();
                break;
            case QMessageBox::Cancel:
                break;
        }
    }

}

bool ui_tienda::actualizar_cantidad_vitrina(int cant, QString id)
{
    object_Producto producto;
    producto.mf_set_idProducto(id);
    if(!producto.mf_update_cant_vitrina(cant))
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("No se logro actualizar cantidad en vitrina de este producto");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return false;
    }
    return true;
}

bool ui_tienda::actualizar_cantidad_almacen(int cant, QString id)
{
    object_Producto producto;
    producto.mf_set_idProducto(id);
    if(!producto.mf_update_cant_almacen(cant))
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("No se logro actualizar cantidad en almacen de este producto");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return false;
    }
    return true;
}

void ui_tienda::setComportamiento(int tem)
{
    comportamiento = tem;
}

void ui_tienda::setMovimiento(int mov)
{
    movimiento = mov;
    /**
     *1 VITRINA A VITRINA
     *2 VITRINA A ALMACEN
     *3 ALMACEN A VITRINA
     *4 PRODUCTOS A VITRINA
     *
    */
}

int ui_tienda::getMovimiento()
{
    return movimiento;
}



void ui_tienda::on_grilla_cellDoubleClicked(int row, int column)
{
    /*ui_item_posicion* posicion_agregar = new ui_item_posicion;
    posicion_agregar->set_ui_tienda_actual(this);
    if(toVitrina)
    {
       return;
    }
    if(idItem.isEmpty())
    {
        posicion_agregar->set_caso(true);
        posicion_agregar->setWindowTitle("Nueva Posicion");
        posicion_agregar->set_posicion(row+1,column+1,actual_nivel);
        posicion_agregar->habilitar();

    }else   //deshabilitar ciertos botones
    {
        posicion_agregar->set_iditem(get_idItem());
        posicion_agregar->set_caso(false);
        posicion_agregar->actualizar();
        posicion_agregar->setWindowTitle("Editar Posicion");
        posicion_agregar->set_posicion(row+1,column+1,actual_nivel);
        posicion_agregar->deshabilitar();

    }
    posicion_agregar->show();*/
}

void ui_tienda::on_grilla_itemSelectionChanged()
{
    QString fila = QString::number(ui->grilla->currentRow()+1);

    QString columna = QString::number(ui->grilla->currentColumn()+1);

    QString pos = fila+"-"+columna;

    set_idItem(idProductos[pos]);
}

void ui_tienda::on_pushButton_traspaso_clicked()
{
    if(!idItem.isEmpty())
    {

        QString key = QString::number(current_index.row()+1)+"-"+QString::number(current_index.column()+1);
        QString codigo = idProductos[key];
        this->set_idTraspaso(codigo);
        this->set_traspaso(false);
        this->habilitar_botones();
        this->enableButtonAceptar();
        this->comportamiento = 1;
        this->movimiento = 1;
        //GUARDANDO ID A BORRAR
        idVitrina_Producto_old = idVitrina_Producto[key];
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Seleccione un producto");
        msgBox.exec();
    }
}

void ui_tienda::on_pushButton_aceptar_traspaso_clicked()
{    
    if(current_index.row() < 0 || current_index.column() < 0 )
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Seleccione una posicion al que desea mover");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }

//PENDIENTE DE SOLUCION EL END WITH
    QString key = QString::number(current_index.row()+1)+"-"+QString::number(current_index.column()+1);
    if(estado[key] == "P")
    {
        QMessageBox msgBox;
        msgBox.setText("La posicion actual esta ocupada por otro producto");
        msgBox.exec();
        return;
    }
    int row=ui->grilla->currentRow()+1;
    int col=ui->grilla->currentColumn()+1;
    int level=actual_nivel;
    object_Producto_has_Vitrina producto_vitrina;
    producto_vitrina.mf_set_Producto_idProducto(idTraspaso);
    producto_vitrina.mf_set_Vitrina_Ubicacion_idUbicacion(idVitrina);
    producto_vitrina.mf_set_Colaborador_Persona_idPersona(QString::number(Sesion::getIdColaborador()));
    producto_vitrina.mf_set_fila(QString::number(row));
    producto_vitrina.mf_set_columna(QString::number(col));
    producto_vitrina.mf_set_nivel(QString::number(level));
    producto_vitrina.mf_set_fecha(QDate::currentDate().toString(Qt::ISODate));    
    producto_vitrina.mf_set_estado("P");//ESTADOS: P = PRESENTE, V = VENDIDO
    producto_vitrina.mf_set_comentario("Presente");


    if(movimiento == 4) // DE PRODUCTOS A VITRINA
    {
        if(estado[key] == "")
        {
            //aki va traspaso de almacen a vitrina

            if(!producto_vitrina.mf_add())
            {
                QMessageBox msgBox;
                msgBox.setText("No se logro agregar la ubicacion");
                msgBox.exec();
                return;
            }
            actualizar_cantidad_vitrina(1,idTraspaso);
            close();
        }
        else
        {
            QString key = QString::number(row)+"-"+QString::number(col);
            producto_vitrina.mf_set_idProducto_has_Vitrina(idVitrina_Producto[key]);
            if(!producto_vitrina.mf_update())
            {
                QMessageBox msgBox;
                msgBox.setText("No se logro actualizar la ubicacion");
                msgBox.exec();
                return;
            }
            actualizar_cantidad_vitrina(1,idTraspaso);
            close();
        }
        emit actualizar_lista_productos();
    }
    if(movimiento == 1) // DE VITRINA A VITRINA
    {        

        if(estado[key] == "")
        {
            if(!producto_vitrina.mf_add())
            {
                QMessageBox msgBox;
                msgBox.setText("No se logro agregar la ubicacion");
                msgBox.exec();
                return;
            }
        }
        else
        {            
            producto_vitrina.mf_set_idProducto_has_Vitrina(idVitrina_Producto[key]);
            if(!producto_vitrina.mf_update())
            {
                QMessageBox msgBox;
                msgBox.setText("No se logro actualizar la ubicacion");
                msgBox.exec();
                return;
            }

        }

        //BORRANDO CELDA        
        object_Producto_has_Vitrina producto_vitrina;
        producto_vitrina.mf_set_idProducto_has_Vitrina(idVitrina_Producto_old);
        if(!producto_vitrina.mf_remove())
        {
            QMessageBox msgBox;
            msgBox.setText("No se logro retirar");
            msgBox.exec();
            return;
         }
         actualizar_grilla();
         ui->pushButton_aceptar_traspaso->hide();
     }
    if(movimiento == 3) // DE ALMACEN A VITRINA
    {
        if(estado[key] == "")//NUEVO
        {
            //aki va traspaso de almacen a vitrina

            if(!producto_vitrina.mf_add())
            {
                QMessageBox msgBox;
                msgBox.setText("No se logro agregar la ubicacion");
                msgBox.exec();
                return;
            }
        }
        else//ACTUALIZAR
        {
            QString key = QString::number(row)+"-"+QString::number(col);
            producto_vitrina.mf_set_idProducto_has_Vitrina(idVitrina_Producto[key]);
            if(!producto_vitrina.mf_update())
            {
                QMessageBox msgBox;
                msgBox.setText("No se logro actualizar la ubicacion");
                msgBox.exec();
                return;
            }
        }

        actualizar_cantidad_vitrina(1,idTraspaso);
        emit actualizar_lista_productos();        
        actualizar_grilla();
        close();
     }

}

void ui_tienda::on_button_traspaso_almacen_clicked()
{
    if(!idItem.isEmpty())
    {

        QString key = QString::number(current_index.row()+1)+"-"+QString::number(current_index.column()+1);
        ui_almacen* traspaso_almacen=new ui_almacen;
        traspaso_almacen->set_currentCode(idProductos[key]);        
        traspaso_almacen->enable_push_button_aceptar();
        traspaso_almacen->set_cantidad(1);
        traspaso_almacen->set_comportamiento(2);
        connect(traspaso_almacen,SIGNAL(actualizar_grilla_vitrina()),this,SLOT(actualizar_grilla_productos()));
        connect(traspaso_almacen,SIGNAL(actualizar_grilla_vitrina()),this,SLOT(remove_producto()));

        traspaso_almacen->show();        
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Seleccione un producto");
        msgBox.exec();
    }
}




void ui_tienda::on_comboBox_vitrina_activated(int index)
{
    changeActual(Vitrina);
}

void ui_tienda::on_comboBox_empresa_activated(const QString &arg1)
{
    changeActual(Empresa);
}

void ui_tienda::on_comboBox_tienda_activated(const QString &arg1)
{
    changeActual(Tienda);
}

void ui_tienda::on_lineEdit_estado_returnPressed()
{
    if(current_index.row() < 0 || current_index.column() < 0 )
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Seleccione una posicion al que desea etiquetar");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }

    QString key = QString::number(current_index.row()+1)+"-"+QString::number(current_index.column()+1);
    object_Producto_has_Vitrina producto_vitrina;
    producto_vitrina.mf_set_idProducto_has_Vitrina(idVitrina_Producto[key]);
    producto_vitrina.mf_set_comentario(ui->lineEdit_estado->text());

    if(!producto_vitrina.mf_update_comentario())
    {
        QMessageBox msgBox;
        msgBox.setText("No se logro actualizar estado del producto");
        msgBox.exec();
        return;
     }
    comentario[key] = ui->lineEdit_estado->text();
}

void ui_tienda::enableButtonAceptar()
{
    ui->pushButton_aceptar_traspaso->show();
}

void ui_tienda::on_grilla_clicked(const QModelIndex &index)
{
    current_index = index;
    QString key = QString::number(current_index.row()+1)+"-"+QString::number(current_index.column()+1);
    ui->lineEdit_estado->setText(comentario[key]);
    if(estado[key] == "P")
    {
        ui->pushButton_reponer->setEnabled(false);
        ui->lineEdit_cod_reponer->setEnabled(false);
        ui->label_cod->setEnabled(false);
        ui->pushButton_etiqueta->setEnabled(true);
    }
    else
    {
        ui->pushButton_reponer->setEnabled(true);
        ui->lineEdit_cod_reponer->setEnabled(true);
        ui->lineEdit_cod_reponer->setText(cod_producto[key]);
        ui->label_cod->setEnabled(true);
        ui->pushButton_etiqueta->setEnabled(false);
    }

}

void ui_tienda::on_pushButton_quitar_clicked()
{
    if(current_index.row() < 0 || current_index.column() < 0 )
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Seleccione una posicion al que desea mover");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }

    QString texto = current_index.data().toString();
    QString key = QString::number(current_index.row()+1)+"-"+QString::number(current_index.column()+1);

    QMessageBox box;
    box.setIcon(QMessageBox::Question);
    box.setWindowTitle("Advertencia");
    box.setText("Va a retirar el producto "+texto);
    box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    box.setDefaultButton(QMessageBox::Ok);
    int ret=box.exec();
    if(ret == QMessageBox::Ok)
    {
        object_Producto_has_Vitrina producto_vitrina;        
        producto_vitrina.mf_set_idProducto_has_Vitrina(idVitrina_Producto[key]);        

        if(!producto_vitrina.mf_remove())
        {
            QMessageBox msgBox;
            msgBox.setText("No se logro retirar");
            msgBox.exec();
            return;
        }
        actualizar_cantidad_vitrina(-1,idProductos[key]);
        actualizar_grilla();
    }

}


void ui_tienda::on_grilla_doubleClicked(const QModelIndex &index)
{
    QString key = QString::number(index.row()+1)+"-"+QString::number(index.column()+1);
    QString codigo = idProductos[key];
    QString idUbicacion = idVitrina_Producto[key];
    QString descripcion;
    object_Producto myProducto;
    myProducto.mf_load(codigo);
    //1 LUNA, 2 MONTURA, 3 LENTE DE CONTACTO, 4 OTROS, 5 TRABAJOS EXTRAS 6 ACCESORIOS
    //Signals codigo,descripcion,precioVenta,Descuento,cant,IdUbicacion,tipo de Producto,Stock del Producto,Precio Compra por lo del Kardex
    if(comportamiento == 1) //1  COMPORTAMIENTO VENTA
    {
        if(myProducto.mf_get_tipo() == "1")
        {
            object_Luna myLuna;
            myLuna.mf_load(codigo);
            object_Tratamiento myTratamiento;
            myTratamiento.mf_load(myLuna.mf_get_Tratamiento_idTratamiento());
            descripcion += myProducto.mf_get_descripcion()+", "+myProducto.mf_get_observaciones()+", "+myTratamiento.mf_get_nombre();

        }
        if(myProducto.mf_get_tipo() == "2")
        {
            object_Montura myMontura;
            myMontura.mf_load(codigo);
            object_Calidad myCalidad;
            myCalidad.mf_load(myMontura.mf_get_Calidad_idCalidad());
            object_Color myColor;
            myColor.mf_load(myMontura.mf_get_Color_idColor());
            descripcion += myProducto.mf_get_codigo()+", "+myProducto.mf_get_descripcion()+", "+myCalidad.mf_get_nombre()+", "+myColor.mf_get_nombre()+", Acces. "+myProducto.mf_get_accesorios();
        }
        if(myProducto.mf_get_tipo() == "3")
        {
            object_LenteContacto myLenteContacto;
            myLenteContacto.mf_load(codigo);
            object_Marca myMarca;
            myMarca.mf_load(myProducto.mf_get_Marca_idMarca());
            object_TiempoUso myTiempoUso;
            myTiempoUso.mf_load(myLenteContacto.mf_get_TiempoUso_idTiempoUso());
            object_TipoLente myTipoLente;
            myTipoLente.mf_load(myLenteContacto.mf_get_TipoLente_idTipoLente());
            descripcion += myProducto.mf_get_codigo()+", "+myMarca.mf_get_nombre()+", "+myTiempoUso.mf_get_valor()+", "+myTipoLente.mf_get_nombre()+", Acces. "+myProducto.mf_get_accesorios();

        }
        if(myProducto.mf_get_tipo() == "4")
        {
            object_Otros myOtros;
            myOtros.mf_load(codigo);
            object_TipoOtros myTipoOtros;
            myTipoOtros.mf_load(myOtros.mf_get_TipoOtros_idTipoOtros());
            object_Calidad myCalidad;
            myCalidad.mf_load(myOtros.mf_get_Calidad_idCalidad());
            object_Marca myMarca;
            myMarca.mf_load(myProducto.mf_get_Marca_idMarca());
            object_Color myColor;
            myColor.mf_load(myOtros.mf_get_Color_idColor());
            descripcion += myProducto.mf_get_codigo()+", "+myTipoOtros.mf_get_nombre()+", "+myCalidad.mf_get_nombre()+", "+myMarca.mf_get_nombre()+", "+myColor.mf_get_nombre();
        }
        if(myProducto.mf_get_tipo() == "6")
        {
            object_Accesorios_n myAccesorios;
            myAccesorios.mf_load(codigo);
            object_Marca myMarca;
            myMarca.mf_load(myProducto.mf_get_Marca_idMarca());
            object_Calidad myCalidad;
            myCalidad.mf_load(myAccesorios.mf_get_Calidad_idCalidad());
            object_Color myColor;
            myColor.mf_load(myAccesorios.mf_get_Color_idColor());
            descripcion += myProducto.mf_get_codigo()+", "+myMarca.mf_get_nombre()+", "+myCalidad.mf_get_nombre()+", "+myColor.mf_get_nombre();

        }
        emit sentProductoVenta(codigo,descripcion,myProducto.mf_get_precioVenta(),myProducto.mf_get_precioDescuento(),1,idUbicacion,myProducto.mf_get_tipo().toInt(),myProducto.mf_get_stock().toInt(),myProducto.mf_get_precioCompra());
        this->close();
    }

}

void ui_tienda::on_btnAgregar_empresa_clicked()
{
    agregarEmpresa(true);
}

void ui_tienda::on_btnEditar_empresa_clicked()
{
    agregarEmpresa(true);
}

void ui_tienda::on_btnDeshabilitar_empresa_clicked()
{
    deshabilitarEmpresa();
}

void ui_tienda::on_btnAgregar_tienda_clicked()
{
    agregarTienda(true);
}

void ui_tienda::on_btnEditar_tienda_clicked()
{
    agregarTienda(false);
}

void ui_tienda::on_btnDeshabilitar_tienda_clicked()
{
    deshabilitarTienda();
}

void ui_tienda::on_btnAgregar_vitrina_clicked()
{
    agregarVitrina(true);
}

void ui_tienda::on_btnEditar_vitrina_clicked()
{
    agregarVitrina(false);
}

void ui_tienda::on_btnDeshabilitar_vitrina_clicked()
{
    deshabilitarVitrina();
}

void ui_tienda::on_btnImprimir_clicked()
{

}
void ui_tienda::on_pushButton_reponer_clicked()
{

    //Verificando stock del producto

    object_Producto myProducto;
    if(ui->lineEdit_cod_reponer->text().size() <= 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Escriba el codigo de producto que desea agregar");
        msgBox.exec();
        ui->lineEdit_cod_reponer->setCursor(this->cursor());
        return;
    }
    if(!myProducto.mf_load_code(ui->lineEdit_cod_reponer->text()))
    {
        QMessageBox msgBox;
        msgBox.setText("No se encontro el producto con codigo "+ui->lineEdit_cod_reponer->text());
        msgBox.exec();
        return;
    }
    int cant_stock,cant_vitri,cant_alma;
    cant_stock = myProducto.mf_get_stock().toInt();
    cant_vitri = myProducto.mf_get_cantidadVitrina().toInt();
    cant_alma = myProducto.mf_get_cantidadAlmacen().toInt();

    if(cant_stock <= (cant_vitri+cant_alma))
    {
        QMessageBox msgBox;
        msgBox.setText("No hay suficiente stock libre del producto");
        msgBox.exec();
        return;
    }
    QString key = QString::number(current_index.row()+1)+"-"+QString::number(current_index.column()+1);

    object_Producto_has_Vitrina producto_vitrina;
    producto_vitrina.mf_set_estado("P");//ESTADOS: P = PRESENTE, V = VENDIDO
    producto_vitrina.mf_set_comentario("Presente");
    producto_vitrina.mf_set_idProducto_has_Vitrina(idVitrina_Producto[key]);

    if(estado[key] == "V")
    {
        if(!producto_vitrina.mf_update_estado())
        {
            QMessageBox msgBox;
            msgBox.setText("No se pudo actualizar estado en vitrina");
            msgBox.exec();
            return;
        }
        if(!myProducto.mf_update_cant_vitrina(1))
        {
            QMessageBox msgBox;
            msgBox.setText("No se pudo actualizar cantidad vitrina");
            msgBox.exec();
            return;
        }
    }
    if(estado[key] == "")
    {
        int row=ui->grilla->currentRow()+1;
        int col=ui->grilla->currentColumn()+1;
        int level=actual_nivel;
        producto_vitrina.mf_set_Vitrina_Ubicacion_idUbicacion(idVitrina);
        producto_vitrina.mf_set_Colaborador_Persona_idPersona(QString::number(Sesion::getIdColaborador()));
        producto_vitrina.mf_set_fila(QString::number(row));
        producto_vitrina.mf_set_columna(QString::number(col));
        producto_vitrina.mf_set_nivel(QString::number(level));
        producto_vitrina.mf_set_fecha(QDate::currentDate().toString(Qt::ISODate));

        if(!producto_vitrina.mf_add())
        {
            QMessageBox msgBox;
            msgBox.setText("No se logro agregar la ubicacion");
            msgBox.exec();
            return;
        }

        if(!myProducto.mf_update_cant_vitrina(1))
        {
            QMessageBox msgBox;
            msgBox.setText("No se logro agregar actualizar cantidad ubicacion");
            msgBox.exec();
            return;
        }
    }
    actualizar_grilla();

}

/*void ui_tienda::on_pushButton_print_clicked()
{
    //validaciones
    //Mensaje


}*/

void ui_tienda::on_pushButton_etiqueta_clicked()
{
    agregar_etiqueta(current_index);
}

void ui_tienda::agregar_etiqueta(const QModelIndex &model)
{
    QString key = QString::number(current_index.row()+1)+"-"+QString::number(current_index.column()+1);

    etiqueta t;
    QString act_codigo,act_descripcion,act_marca,act_precio,act_ubicacion;

    //BUSCANDO SI ESTA REPETIDO
    for(int i=0;i<etiquetas.size();i++)
        if(etiquetas[i].getCodigo()==act_codigo)
        {
            QMessageBox box;
            box.setIcon(QMessageBox::Question);
            box.setWindowTitle("Advertencia");
            box.setText("Ya existe este producto!\nDesea etiquetarlo de igual manera?");
            box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            box.setDefaultButton(QMessageBox::Ok);
            int ret=box.exec();
            switch(ret)
            {
                case QMessageBox::Ok:
                    break;
                case QMessageBox::Cancel:
                    return;
                default:
                    break;
            }
            break;
        }

    act_codigo = cod_producto[key];
    act_descripcion = descripcion[key];
    act_marca = marca[key];
    act_precio = costo[key];
    act_ubicacion = QString::number(current_index.row()+1)+","+QString::number(current_index.column()+1)+","+QString::number(actual_nivel);

    t.setCodigo(act_codigo);
    t.setDescripcion(act_descripcion);
    t.setMarca(act_marca);
    t.setPrecio(act_precio);
    t.setUbicacion(act_ubicacion);
    etiquetas.append(t);
    ui->tableView_etiquetas->insertRow(ui->tableView_etiquetas->rowCount());
    ui->tableView_etiquetas->setItem(ui->tableView_etiquetas->rowCount()-1,0,new QTableWidgetItem(act_codigo));
    ui->tableView_etiquetas->setItem(ui->tableView_etiquetas->rowCount()-1,1,new QTableWidgetItem(act_descripcion));
    ui->tableView_etiquetas->setItem(ui->tableView_etiquetas->rowCount()-1,2,new QTableWidgetItem(act_marca));
    ui->tableView_etiquetas->setItem(ui->tableView_etiquetas->rowCount()-1,3,new QTableWidgetItem(act_precio));
    ui->tableView_etiquetas->setItem(ui->tableView_etiquetas->rowCount()-1,4,new QTableWidgetItem(act_ubicacion));

}

void ui_tienda::on_pushButton_previsualizar_clicked()
{
    for(int i=0;i<etiquetas.size();i++){
        etiquetas[i].etiquetar();
    }

    QPixmap pm(ui->draw_label->width()*4,ui->draw_label->height()*4);
    pm.fill(Qt::white);
    QPainter p;
    //QFont font("times",16);
    QFont font("times",8);
    p.begin(&pm);
    p.setFont(font);

    int j=0;
    int k=0;
    pag=0;
    QString num;

    for(int i=0;i<etiquetas.size();i++)
    {
        QImage tmp("etiquetas/imagenes/"+etiquetas[i].getCodigo()+".png");
        //QImage imagen=tmp.scaledToHeight(60);
        //Escalando Imagen
        QImage imagen=tmp.scaled(130,40,Qt::IgnoreAspectRatio,Qt::FastTransformation);
        p.drawImage((200*k)+60,(100*j)+30,imagen);
        p.drawText((200*k)+60,(100*j)+90,etiquetas[i].getDescripcion());
        p.drawText((200*k)+130,(100*j)+90,etiquetas[i].getMarca());
        p.drawText((200*k)+60,(100*j)+106,etiquetas[i].getUbicacion());
        p.drawText((200*k)+130,(100*j)+106,"S/."+etiquetas[i].getPrecio());
        /*p.drawImage((500*k)+220,(100*j)+30,imagen);
        p.drawText((500*k)+440,(100*j)+46,etiquetas[i].getCodigo());
        p.drawText((500*k)+440,(100*j)+62,etiquetas[i].getColor());
        p.drawText((500*k)+510,(100*j)+62,etiquetas[i].getCalidad());
        p.drawText((500*k)+440,(100*j)+78,etiquetas[i].getUbicacion());
        p.drawText((500*k)+510,(100*j)+78,"S/."+etiquetas[i].getPrecio());*/

        if(k==1)
        {
            k=-1;
            j++;
        }
        k++;
        if(j==17 || (i+1)==etiquetas.size())
        {
            j=0;
            pm.save("etiquetas/"+num.setNum(pag)+".png");
            pm.fill(Qt::white);
            pag++;
        }
    }

    if(pag!=0)
    {
        ui->lineEdit_pag->setText("1/"+num.setNum(pag));
        this->act=0;
        ui->pushButton_siguiente->setEnabled(1);
        if(this->act==0)
            ui->pushButton_anterior->setDisabled(1);
        if(this->act+1==pag)
            ui->pushButton_siguiente->setDisabled(1);
        QImage act("etiquetas/0.png");
        p.drawImage(0,0,act);
    }
    else
    {
        ui->lineEdit_pag->setText("0/0");
        ui->pushButton_anterior->setDisabled(1);
        ui->pushButton_anterior->setDisabled(1);
        pm.fill(Qt::white);
    }
    ui->draw_label->setPixmap(pm.scaled(ui->draw_label->width(),ui->draw_label->height()));
}

void ui_tienda::on_pushButton_imprimir_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setFullPage(QPrinter::A4);
    printer.setOutputFileName("etiquetas.pdf");
    QPainter painter;
    if (! painter.begin(&printer))
        qWarning("failed to open file, is it writable?");
    QImage act("etiquetas/0.png");
    act=act.scaledToWidth(9000);
    painter.drawImage(0,0,act);
    painter.end();
    QTextEdit parent;
    QPrintDialog*dlg = new QPrintDialog(&printer,&parent);
    dlg->setWindowTitle(QObject::tr("Print Document"));

    if(dlg->exec() == QDialog::Accepted) {
        parent.print(&printer);
    }
    delete dlg;
}

void ui_tienda::on_pushButton_anterior_clicked()
{
    if(pag!=0 && act>0)
    {
        QPixmap pm(ui->draw_label->width()*4,ui->draw_label->height()*4);
        pm.fill(Qt::white);
        QPainter p;
        p.begin(&pm);
        QString num;
        QImage act("etiquetas/"+num.setNum(--this->act)+".png");
        ui->lineEdit_pag->setText(num.setNum(this->act+1)+"/"+num.setNum(pag));
        p.drawImage(0,0,act);
        ui->draw_label->setPixmap(pm.scaled(ui->draw_label->width(),ui->draw_label->height()));

        ui->pushButton_siguiente->setEnabled(1);
        if(this->act==0)
            ui->pushButton_anterior->setDisabled(1);
    }
}

void ui_tienda::on_pushButton_siguiente_clicked()
{
    if(pag!=0 && (act+1)<pag)
    {
        QPixmap pm(ui->draw_label->width()*4,ui->draw_label->height()*4);
        pm.fill(Qt::white);
        QPainter p;
        p.begin(&pm);
        QString num;
        QImage act("etiquetas/"+num.setNum(++this->act)+".png");
        ui->lineEdit_pag->setText(num.setNum(this->act+1)+"/"+num.setNum(pag));
        p.drawImage(0,0,act);
        ui->draw_label->setPixmap(pm.scaled(ui->draw_label->width(),ui->draw_label->height()));

        ui->pushButton_anterior->setEnabled(1);
        if(this->act+1==pag)
            ui->pushButton_siguiente->setDisabled(1);
    }
}
