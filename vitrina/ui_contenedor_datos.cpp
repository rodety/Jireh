#include "ui_contenedor_datos.h"
#include "ui_ui_contenedor_datos.h"
#include <QSqlQuery>
#include <QDebug>
#include "contenedor.h"
#include <QMessageBox>
#include <QSqlError>
#include "ui_tienda.h"

ui_contenedor_datos::ui_contenedor_datos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_contenedor_datos)
{
    ui->setupUi(this);
    flag = false;
}


ui_contenedor_datos::~ui_contenedor_datos()
{
    delete ui;
}

QString ui_contenedor_datos::get_idContenedor()         {return idContenedor;}
void ui_contenedor_datos::set_idContenedor(QString c)   {idContenedor = c;}
ui_almacen* ui_contenedor_datos::get_ui_almacen_parent(){return ui_almacen_parent;}
void ui_contenedor_datos::set_ui_almacen_parent(ui_almacen * al){ui_almacen_parent = al;}
int ui_contenedor_datos::get_behavior()                 {return behavior;}
void ui_contenedor_datos::set_behavior(int b)           {behavior = b;}
void ui_contenedor_datos::set_idProducto(QString tmp)   {ui->lineEdit_codigoProducto->setText(tmp);}
bool ui_contenedor_datos::add_Product()                 {return on_pushButton_addProducto_clicked();}
void ui_contenedor_datos::set_fila(int f)       {fila = f;}
void ui_contenedor_datos::set_columna(int c)    {columna = c;}

void ui_contenedor_datos::clear_widget_list_productos()
{

}

void ui_contenedor_datos::update_table_list_productos()
{
    object_Contenedor_has_Producto contenedor_has_producto;
    contenedor_has_producto.mf_set_idContenedor(idContenedor);
    ui->tableView_datos->setModel(contenedor_has_producto.mf_show());
}

void ui_contenedor_datos::update_form()
{    
    ui->lineEdit_nombre->clear();
    ui->lineEdit_descripcion->clear();

    QSqlQuery query;
    query.prepare("SELECT nombre,descripcion,posFila,posColumna FROM Contenedor WHERE idContenedor=?");
    query.bindValue(0,idContenedor);
    query.exec();

    query.next();

    QString nombre = query.value(0).toString();
    QString descripcion = query.value(1).toString();
    int pos_fila = query.value(2).toInt();
    int pos_columna = query.value(3).toInt();

    ui->lineEdit_nombre->setText(nombre);
    ui->lineEdit_descripcion->setText(descripcion);

    update_table_list_productos();
}

void ui_contenedor_datos::on_pushButton_salir_clicked()
{
    close();
}

bool ui_contenedor_datos::on_pushButton_addProducto_clicked()
{
    QString codigo=ui->lineEdit_codigoProducto->text();
    if(codigo.compare("")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Informacion");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("Debe escribir un codigo primero.");
        msgBox->exec();

        close();
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT idProducto FROM Producto WHERE codigo=?");
    query.bindValue(0,codigo);
    query.exec();   query.next();
    QString id=query.value(0).toString();

    if(toAlmacen)
    {
        montura* m=new montura;
        m->setIdProducto(id);
        if(m->addToAlmacen(cantidadProducto))
            insert_Product();
    }
    else
    {
        bool ok;
        cantidadProducto = QInputDialog::getInt(this,tr("Ingrese Cantidad"),tr("Cantidad"),1,0,1000,1,&ok);

        if(ok)
        {
            montura* m=new montura;
            m->setIdProducto(id);
            if(m->addToAlmacen(cantidadProducto))
                insert_Product();
        }
        else
            return false;
    }
}

bool ui_contenedor_datos::insert_Product()
{
    QString producto_codigo = ui->lineEdit_codigoProducto->text(); //verificar si el producto existe;

    QSqlQuery query;
    query.prepare("SELECT idProducto FROM Producto WHERE codigo=?");
    query.bindValue(0,producto_codigo);
    query.exec();
    if(!query.next())
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("El producto asociado al código que ingreso no existe!");
        msgBox->exec();
    }
    else
    {
        QString idProducto = query.value(0).toString();

        query.prepare("SELECT * from Contenedor_has_Producto WHERE Producto_idProducto=?");
        query.bindValue(0,idProducto);
        query.exec();

        if(query.next())
        {
            QString idCont=query.value(1).toString();
            query.prepare("SELECT nombre,Andamio_idAndamio from Contenedor WHERE idContenedor=?");
            query.bindValue(0,idCont);
            query.exec();   query.next();

            QString contenedorName=query.value(0).toString(), idAndamio=query.value(1).toString();

            query.prepare("SELECT nombre,Almacen_idAlmacen from Andamio WHERE idAndamio=?");
            query.bindValue(0,idAndamio);
            query.exec();   query.next();

            QString andamioName=query.value(0).toString(), idAlmacen=query.value(1).toString();

            query.prepare("SELECT nombre,Tienda_idTienda from Almacen WHERE idAlmacen=?");
            query.bindValue(0,idAlmacen);
            query.exec();   query.next();

            QString almacenName=query.value(0).toString(), idTienda=query.value(1).toString();

            query.prepare("SELECT nombre FROM Tienda WHERE IdTienda=?");
            query.bindValue(0,idTienda);
            query.exec();   query.next();

            QString tiendaName=query.value(0).toString();

            QMessageBox *msgBox =new QMessageBox;
            msgBox->setIcon(QMessageBox::Warning);
            msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
            msgBox->setWindowTitle("Informacion");
            msgBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            msgBox->setText("El producto ya esta asignado a otro contenedor : Tienda:'"+tiendaName+"', Almacen:'"+almacenName+"', Andamio:'"+andamioName+"', Contenedor:'"+contenedorName+"' ¿Aun desea asignarlo en esta posicion? ");
            int op=msgBox->exec();
            Sesion* s=Sesion::getSesion();
            switch(op)
            {
                case QMessageBox::Ok:

                    if(idCont.compare(idContenedor)==0)
                    {
                        query.prepare("SELECT cantidadProducto FROM Contenedor_has_Producto WHERE Contenedor_idContenedor=?");
                        query.bindValue(0,idContenedor);
                        query.exec();   query.next();
                        cantidadProducto+=query.value(0).toInt();

                        query.prepare("UPDATE Contenedor_has_Producto SET cantidadProducto=? WHERE Contenedor_idContenedor=?");
                        query.bindValue(0,cantidadProducto);
                        query.bindValue(1,idContenedor);
                        query.exec();

                        return true;
                    }
                    else
                    {   query.prepare("INSERT INTO Contenedor_has_Producto(Contenedor_idContenedor,Producto_idProducto,fecha,Colaborador_Persona_idPersona,cantidadProducto) VALUES(?,?,now(),?,?)");
                        query.bindValue(0,idContenedor);
                        query.bindValue(1,idProducto);
                        query.bindValue(2,s->getIdColaborador());
                        query.bindValue(3,cantidadProducto);

                        if(query.exec())
                        {
                            //algo con historial de almacen
                            return true;
                        }
                        else return false;
                    }
                    break;

                case QMessageBox::Cancel:
                    return false;
                    break;
            }
        }
        else
        {
            Sesion* s=Sesion::getSesion();

            query.prepare("INSERT INTO Contenedor_has_Producto(Contenedor_idContenedor,Producto_idProducto,fecha,Colaborador_Persona_idPersona,cantidadProducto) VALUES(?,?,now(),?,?)");
            query.bindValue(0,idContenedor);
            query.bindValue(1,idProducto);
            query.bindValue(2,s->getIdColaborador());
            query.bindValue(3,cantidadProducto);

            if(query.exec())
            {
                //algo con historial de almacen
                return true;
            }
            else return false;
        }
    }
}

void ui_contenedor_datos::on_pushButton_saveContenedor_clicked()
{
    QString idAndamio = ui_almacen_parent->get_currentIdAndamio();
    QString nombre = ui->lineEdit_nombre->text();
    QString descripcion = ui->lineEdit_descripcion->text();
    QString pos_fila = QString::number(fila);
    QString pos_columna = QString::number(columna);
//    QString capacidad = ui->spinBox_capacidad->text();

    contenedor *contenedor_data;

    QMessageBox *msgBox =new QMessageBox;
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
    msgBox->setWindowTitle("Resultado");
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setButtonText(QMessageBox::Ok,"Aceptar");

    if(nombre.compare("")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("El nombre de un contenedor no puede quedar en blanco!");
        msgBox->exec();
    }
    else
    {
        switch(behavior)
        {
            case 0:
                contenedor_data = new contenedor("0",idAndamio,nombre,descripcion,pos_fila,pos_columna);
                contenedor_data->agregar();
                //ui_almacen_parent->set_currentIdContenedor((pos_fila.toInt()-1)+"-"+(pos_columna.toInt()-1));
                ui_almacen_parent->update_widget_Contenedores();
                close();

                msgBox->setText("Contenedor creado correctamente.");
                //ui_almacen_parent->clear_widget_Contenedores();

                break;
            case 1:
                contenedor_data = new contenedor(idContenedor,idAndamio,nombre,descripcion,pos_fila,pos_columna);
                contenedor_data->actualizar();
                ui_almacen_parent->update_widget_Contenedores();
                close();

                msgBox->setText("Datos actualizados correctamente.");
                break;
        }

        msgBox->exec();
    }
}

void ui_contenedor_datos::on_pushButton_deleteContenedor_clicked()
{
    contenedor *any_contenedor = new contenedor(idContenedor,"","","","","");

    QMessageBox *msgBox =new QMessageBox;
    msgBox->setIcon(QMessageBox::Warning);
    msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
    msgBox->setWindowTitle("Confirmar");
    msgBox->setText("Desea elminiar el contenedor?");
    msgBox->setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
    msgBox->setButtonText(QMessageBox::Cancel,"Cancelar");

    int ret = msgBox->exec();

    switch(ret)
    {
        case QMessageBox::Ok:

            any_contenedor->eliminar();
            ui_almacen_parent->set_dimension_widget_Contenedores();
            ui_almacen_parent->update_widget_Contenedores();
            close();
            break;
        case QMessageBox::Cancel:
            break;
    }
}

void ui_contenedor_datos::on_pushButton_deleteProducto_clicked()
{
    if(indice.row() < 0 || indice.column() < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Seleccione un producto");
        msgBox.exec();
        return;
    }    

    bool ok;
    int cant = QInputDialog::getInt(this,tr("Ingrese Cantidad"),tr("Cantidad"),1,1,max_numero_mover,1,&ok);
    if(ok)
    {
        actualizar_productos_cant(-cant,idProducto);
    }
}

void ui_contenedor_datos::on_traspaso_clicked()
{
    if(indice.row() < 0 || indice.column() < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Seleccione un producto");
        msgBox.exec();
        return;
    }
    ui_tienda* tienda= new ui_tienda;
    tienda->set_idTraspaso(idProducto);
    tienda->set_traspaso(true);
    tienda->habilitar_botones();
    tienda->enableButtonAceptar();    
    tienda->setMovimiento(3);
    //CONECTANDO LAS SENALES
    connect(tienda,SIGNAL(actualizar_lista_productos()),this,SLOT(traspaso_vitrina()));
    tienda->show();
}


void ui_contenedor_datos::on_tableView_datos_clicked(const QModelIndex &index)
{
    indice = index;
    max_numero_mover = ui->tableView_datos->model()->data(ui->tableView_datos->model()->index(index.row(),2)).toInt();
    idProducto = ui->tableView_datos->model()->data(ui->tableView_datos->model()->index(index.row(),0)).toString();
}

void ui_contenedor_datos::actualizar_productos_cant(int cant, QString codigo)
{
    if(indice.row() < 0 || indice.column() < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Seleccione un producto");
        msgBox.exec();
        return;
    }
    object_Contenedor_has_Producto contenedor_producto;
    contenedor_producto.mf_set_Producto_idProducto(codigo);
    contenedor_producto.mf_set_Contenedor_idContenedor(idContenedor);
    contenedor_producto.mf_set_cantidadProducto(QString::number(cant));
    contenedor_producto.mf_set_Colaborador_Persona_idPersona(QString::number(Sesion::getIdColaborador()));
    contenedor_producto.mf_set_fecha(QDate::currentDate().toString(Qt::ISODate));
    if(abs(cant) >= max_numero_mover) //BORRARLO TODO
    {
        if(!contenedor_producto.mf_remove())
        {
            QMessageBox msgBox;
            msgBox.setText("No se logro remover producto del contenedor");
            msgBox.exec();
            return;
        }
    }
    else
    {
        if(!contenedor_producto.mf_update())
        {
            QMessageBox msgBox;
            msgBox.setText("No se logro actualizar cantidad del producto en contenedor");
            msgBox.exec();
            return;
        }
    }
    //Si se trata de Moviemiento entre contenedores
    if(!flag)
    {
        object_Producto producto;
        producto.mf_set_idProducto(codigo);
        if(!producto.mf_update_cant_almacen(cant))
        {
            QMessageBox msgBox;
            msgBox.setText("No se logro remover producto del contenedor");
            msgBox.exec();
            return;
        }
        update_table_list_productos();
    }
    else
    {
        this->close();
    }
}

void ui_contenedor_datos::show_controls_product(bool c)
{
    if(c)
    {
        ui->traspaso_Almacen->show();
        ui->traspaso->show();
        ui->pushButton_deleteProducto->show();
        ui->lineEdit_codigoProducto->show();
        ui->pushButton_addProducto->show();
    }
    else
    {
        ui->traspaso_Almacen->hide();
        ui->traspaso->hide();
        ui->pushButton_deleteProducto->hide();
        ui->lineEdit_codigoProducto->hide();
        ui->pushButton_addProducto->hide();
    }
}

void ui_contenedor_datos::on_traspaso_Almacen_clicked()
{
    bool ok;
    int cant = QInputDialog::getInt(this,tr("Ingrese Cantidad"),tr("Cantidad"),1,1,max_numero_mover,1,&ok);
    if(ok)
    {
        ui_almacen_parent->setToAlmacen(true);
        ui_almacen_parent->set_currentCode(idProducto);
        ui_almacen_parent->set_cantidad(cant);
        ui_almacen_parent->enable_push_button_aceptar();
        ui_almacen_parent->set_comportamiento(3);
        //CONECTANDO LAS SENALES
        connect(ui_almacen_parent,SIGNAL(traspaso_almacen(int)),this,SLOT(traspaso_contenedor(int)));
        /**
         * Activando el Flag para cuando reciba la senal se cierre la ventana
         **/
        this->showMinimized();
        flag = true;
    }
}

void ui_contenedor_datos::traspaso_vitrina()
{
    //ACTUALIZANDO CANTIDADES
    actualizar_productos_cant(-1,idProducto);
}

void ui_contenedor_datos::traspaso_contenedor(int cant)
{
    actualizar_productos_cant(-cant,idProducto);
}

void ui_contenedor_datos::on_lineEdit_codigoProducto_cursorPositionChanged(int arg1, int arg2)
{
    ui->lineEdit_codigoProducto->text().clear();
}

void ui_contenedor_datos::on_tableView_datos_doubleClicked(const QModelIndex &index)
{
    int maximo = ui->tableView_datos->model()->data(ui->tableView_datos->model()->index(index.row(),2)).toInt();
    idProducto = ui->tableView_datos->model()->data(ui->tableView_datos->model()->index(index.row(),0)).toString();
    bool ok;
    int cant = QInputDialog::getInt(this,tr("Ingrese Cantidad"),tr("Cantidad"),0,0,maximo,1,&ok);
    if(ok)
    {
       //id_Contenedor_has_Producto = "0";
        if(cant > 0)
        {
            object_Producto myProducto;
            myProducto.mf_load(idProducto);
            ui_almacen_parent->sendProducto(idProducto,myProducto.mf_get_descripcion(),myProducto.mf_get_precioVenta(),myProducto.mf_get_precioDescuento(),cant,idContenedor,myProducto.mf_get_tipo().toInt(),myProducto.mf_get_stock().toInt(),myProducto.mf_get_precioCompra());
            close();
        }

    }
}
