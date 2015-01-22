#include "ui_almacen.h"
#include "ui_ui_almacen.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

#include "almacen_datos.h"
#include "ui_andamio_datos.h"
#include "ui_contenedor_datos.h"
#include "share_typedef.h"
#include "almacen.h"
#include "andamio.h"
#include "contenedor.h"
#include "share_include.h"
#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"
#include <QFileDialog>


ui_almacen::ui_almacen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_almacen)
{
    ui->setupUi(this);
    fromVitrina=false;  toAlmacen=false;
    update_comboBox_Empresa();
    ui->pushButton_aceptar->hide();

    if(Sesion::getSesion()->get_Usuario()->get_tipoUsuario()==2)
    {
        ui->pushButton_addAlmacen->hide();
        ui->pushButton_addAndamio->hide();
        ui->pushButton_deleteAlmacen->hide();
        ui->pushButton_deleteAndamio->hide();
        ui->pushButton_editAlmacen->hide();
        ui->pushButton_editAndamio->hide();
    }
    //Ubicacion
    ui->comboBox_Empresa->setCurrentIndex(Sesion::getUbicacion().first-1);
}

ui_almacen::~ui_almacen()
{
    delete ui;
}

void ui_almacen::enable_push_button_aceptar()
{
    ui->pushButton_aceptar->show();
}

QString ui_almacen::get_currentIdEmpresa()    {return currentIdEmpresa;}
QString ui_almacen::get_currentIdTienda()     {return currentIdTienda;}
QString ui_almacen::get_currentIdAlmacen()    {return currentIdAlmacen;}
QString ui_almacen::get_currentIdAndamio()    {return currentIdAndamio;}
QString ui_almacen::get_currentIdContenedor() {return currentIdContenedor;}

int ui_almacen::get_comportamiento()
{
    return comportamiento;
}

void ui_almacen::setFromVitrina(bool b) {fromVitrina=b;}
void ui_almacen::setToAlmacen(bool b)   {toAlmacen=b;}

void ui_almacen::set_currentIdEmpresa(QString e)     {currentIdEmpresa = e;}
void ui_almacen::set_currentIdTienda(QString t)      {currentIdTienda = t;}
void ui_almacen::set_currentIdAlmacen(QString al)    {currentIdAlmacen = al;}
void ui_almacen::set_currentIdAndamio(QString an)    {currentIdAndamio = an;}
void ui_almacen::set_currentIdContenedor(QString c)  {currentIdContenedor = c;}
void ui_almacen::set_currentCode(QString cod)        {currentCod=cod;}
void ui_almacen::set_query(QSqlQuery query)          { sqlQuery=query;}
/**
 * @brief ui_almacen::set_comportamiento
 * @param com Comportamiento
 *1 PRODUCTO A ALMACEN
 *2 VITRINA A ALMACEN
 *3 ALMACEN A ALMACEN
 */
void ui_almacen::set_comportamiento(int com)
{
    comportamiento =  com;
}


void ui_almacen::update_comboBox_Empresa()
{
    ui->comboBox_Empresa->clear();

    QSqlQuery query;
    query.prepare("SELECT idEmpresa,razonSocial FROM Empresa");
    query.exec();

    int c = 0;

    while(query.next())
    {
        QString idempresa = query.value(0).toString();
        QString raz_social = query.value(1).toString();

        Empresas[raz_social] = idempresa;
        ui->comboBox_Empresa->insertItem(c++,raz_social);
    }
}

void ui_almacen::update_comboBox_Tienda(QString idEmpresa)
{
    ui->comboBox_Tienda->clear();

    QSqlQuery query;
    query.prepare("SELECT idTienda,nombre FROM Tienda WHERE Empresa_idEmpresa=?");
    query.bindValue(0,idEmpresa);
    query.exec();

    int c = 0;

    while(query.next())
    {
        QString idtienda = query.value(0).toString();
        QString alias = query.value(1).toString();

        Tiendas[alias] = idtienda;

        ui->comboBox_Tienda->insertItem(c++,alias);
    }
    //Ubicacion
    ui->comboBox_Tienda->setCurrentIndex(Sesion::getUbicacion().second-1);
}

void ui_almacen::update_comboBox_Almacen(QString idTienda)
{
    ui->comboBox_Almacen->clear();

    QSqlQuery query;
    query.prepare("SELECT idAlmacen,nombre FROM Almacen WHERE Tienda_idTienda=?");
    query.bindValue(0,idTienda);
    query.exec();

    int c = 0;

    while(query.next())
    {
        QString idalmacen = query.value(0).toString();
        QString nombre = query.value(1).toString();
        Almacenes[nombre] = idalmacen;

        ui->comboBox_Almacen->insertItem(c,nombre);
        c++;
    }

}
void ui_almacen::update_comboBox_Andamio(QString idAlmacen)
{
    ui->comboBox_Andamio->clear();

    QSqlQuery query;
    query.prepare("SELECT idAndamio,nombre FROM Andamio WHERE Almacen_idAlmacen=?");
    query.bindValue(0,idAlmacen);
    query.exec();

    int c = 0;

    while(query.next())
    {
        QString idandamio = query.value(0).toString();
        QString nombre = query.value(1).toString();

        Andamios[nombre] = idandamio;

        ui->comboBox_Andamio->insertItem(c,nombre);

        c++;
    }
}

void ui_almacen::clear_widget_Contenedores()
{
    ui->tableWidget_griContenedores->clear();
}

void ui_almacen::set_dimension_widget_Contenedores()
{
    clear_widget_Contenedores();

    QSqlQuery query;
    query.prepare("SELECT fila,columna FROM Andamio WHERE idAndamio=?");
    query.bindValue(0,currentIdAndamio);
    query.exec();

    query.next();

    int fila = query.value(0).toInt();
    int columna = query.value(1).toInt();

    ui->tableWidget_griContenedores->setRowCount(fila);
    ui->tableWidget_griContenedores->setColumnCount(columna);
}

void ui_almacen::update_widget_Contenedores()
{
    Contenedor.clear();
    QSqlQuery query;
    query.prepare("SELECT nombre,descripcion,posFila,posColumna,idContenedor FROM Contenedor WHERE Andamio_idAndamio=?");
    query.bindValue(0,currentIdAndamio);
    query.exec();

    while(query.next())
    {
        QString nombre = query.value(0).toString();
        QString descripcion = query.value(1).toString();
        int pos_fila = query.value(2).toInt();
        int pos_columna = query.value(3).toInt();
        QString idcontenedor = query.value(4).toString();

        QString key = QString::number(pos_fila)+"-"+QString::number(pos_columna);
        Contenedor[key] = idcontenedor;

        ui->tableWidget_griContenedores->setItem(pos_fila-1,pos_columna-1,new QTableWidgetItem(nombre));
    }
}

void ui_almacen::sendProducto(QString idProducto, QString descripcion, QString precio_Venta, QString descuento, int cantidad, QString idUbicacion, int tipoProducto, int stockProducto, QString precioCompra)
{
    emit sendProductoVenta(idProducto,descripcion ,precio_Venta,descuento,cantidad ,idUbicacion,tipoProducto,stockProducto,precioCompra);
    close();
}

void ui_almacen::on_comboBox_Empresa_currentIndexChanged(const QString &arg1)
{
    set_currentIdEmpresa(Empresas[arg1]);
    update_comboBox_Tienda(get_currentIdEmpresa());
}

void ui_almacen::on_comboBox_Tienda_currentIndexChanged(const QString &arg1)
{
    set_currentIdTienda(Tiendas[arg1]);
    update_comboBox_Almacen(get_currentIdTienda());
}

void ui_almacen::on_comboBox_Almacen_currentIndexChanged(const QString &arg1)
{
    set_currentIdAlmacen(Almacenes[arg1]);
    update_comboBox_Andamio(get_currentIdAlmacen());
}

void ui_almacen::on_comboBox_Andamio_currentIndexChanged(const QString &arg1)
{
    set_currentIdAndamio(Andamios[arg1]);

    set_dimension_widget_Contenedores();
    update_widget_Contenedores();

}

void ui_almacen::on_pushButton_addAlmacen_clicked()
{
    if(get_currentIdTienda().compare("")==0)
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
        almacen_datos *new_almacen_form =  new almacen_datos;
        new_almacen_form->set_idTienda(get_currentIdTienda());
        new_almacen_form->set_ui_almacen_parent(this);
        new_almacen_form->set_behavior(0);
        new_almacen_form->setWindowTitle("Nuevo Almacen");
        new_almacen_form->show();
    }
}

void ui_almacen::on_pushButton_editAlmacen_clicked()
{
    if(get_currentIdAlmacen().compare("")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("Debe seleccionarse una Almacen válido!");
        msgBox->exec();
    }
    else
    {
        almacen_datos *edit_almacen_form = new almacen_datos;
        edit_almacen_form->set_idTienda(get_currentIdTienda());
        edit_almacen_form->set_ui_almacen_parent(this);
        edit_almacen_form->set_behavior(1);
        edit_almacen_form->update_form();
        edit_almacen_form->setWindowTitle("Editar Almacen");
        edit_almacen_form->show();
    }
}

void ui_almacen::on_pushButton_deleteAlmacen_clicked()
{
    if(get_currentIdAlmacen().compare("")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("Debe seleccionarse un Almacen válido!");
        msgBox->exec();
    }
    else
    {
        almacen *any_almacen = new almacen(get_currentIdAlmacen(),"","","");

        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Confirmar");
        msgBox->setText("Desea eliminar el almacen?");
        msgBox->setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setButtonText(QMessageBox::Cancel,"Cancelar");

        int ret = msgBox->exec();

        switch(ret)
        {
            case QMessageBox::Ok:

                any_almacen->eliminar();
                update_comboBox_Almacen(currentIdTienda);
                break;
            case QMessageBox::Cancel:
                break;
        }
    }
}

void ui_almacen::on_pushButton_addAndamio_clicked()
{
    if(get_currentIdAlmacen().compare("")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("Debe seleccionarse un Almacen válido!");
        msgBox->exec();
    }
    else
    {
        ui_andamio_datos* new_andamio_form = new ui_andamio_datos;
        new_andamio_form->set_idAlmacen(get_currentIdAlmacen());
        new_andamio_form->set_ui_almacen_parent(this);
        new_andamio_form->set_behavior(0);
        new_andamio_form->setWindowTitle("Nuevo Andamio");
        new_andamio_form->show();
    }
}


void ui_almacen::on_pushButton_editAndamio_clicked()
{
    if(get_currentIdAndamio().compare("")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("Debe seleccionarse un Andamio válido!");
        msgBox->exec();
    }
    else
    {
        ui_andamio_datos* edit_andamio_form = new ui_andamio_datos;
        edit_andamio_form->set_idAlmacen(get_currentIdAlmacen());
        edit_andamio_form->set_ui_almacen_parent(this);
        edit_andamio_form->set_behavior(1);
        edit_andamio_form->update_form();
        edit_andamio_form->setWindowTitle("Editar Andamio");
        edit_andamio_form->show();
    }
}

void ui_almacen::on_pushButton_deleteAndamio_clicked()
{
    if(get_currentIdAndamio().compare("")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("Debe seleccionarse un Andamio válido!");
        msgBox->exec();
    }
    else
    {
        andamio *any_andamio = new andamio(get_currentIdAndamio(),"","","","","");

        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Confirmar");
        msgBox->setText("Desea eliminar el andamio?");
        msgBox->setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setButtonText(QMessageBox::Cancel,"Cancelar");

        int ret = msgBox->exec();

        switch(ret)
        {
            case QMessageBox::Ok:
                any_andamio->eliminar();
                update_comboBox_Andamio(currentIdAndamio);
                break;
            case QMessageBox::Cancel:
                break;
        }
    }
}

void ui_almacen::on_tableWidget_griContenedores_cellDoubleClicked(int row, int column)
{
    QString fila = QString::number(row+1);
    QString columna = QString::number(column+1);
    QString pos = fila+"-"+columna;
    set_currentIdContenedor(Contenedor[pos]);

    ui_contenedor_datos* contenedor_form = new ui_contenedor_datos;
    contenedor_form->set_idContenedor(Contenedor[pos]);
    contenedor_form->set_ui_almacen_parent(this);

    if(currentIdContenedor.isEmpty())
    {
        contenedor_form->set_behavior(0);
        contenedor_form->setWindowTitle("Nuevo Contenedor");
        contenedor_form->set_fila(row+1);
        contenedor_form->set_columna(column+1);
        contenedor_form->show_controls_product(false);
    }
    else
    {
        /*if(toAlmacen)
        {
            contenedor_form->set_idContenedor(currentIdContenedor);
            contenedor_form->set_behavior(1);
            contenedor_form->update_form();
            contenedor_form->setWindowTitle("Contenedor");
            contenedor_form->set_idProducto(currentCod);
            contenedor_form->setToAlmacen(true);
            contenedor_form->setCantidadProducto(cantidadProducto);
            contenedor_form->add_Product();
            contenedor_form->close();
            close();
        }
        if(fromVitrina)
        {
            QString idProducto=sqlQuery.value(0).toString();
            int fila  =sqlQuery.value(2).toInt(),
                col   =sqlQuery.value(3).toInt(),
                nivel =sqlQuery.value(4).toInt();

            QSqlQuery query;
            query.prepare("SELECT codigo FROM Producto WHERE idProducto=?");
            query.bindValue(0,idProducto);
            query.exec();   query.next();
            QString cod=query.value(0).toString();

            contenedor_form->set_idContenedor(currentIdContenedor);
            contenedor_form->set_behavior(1);
            contenedor_form->update_form();
            contenedor_form->setWindowTitle("Editar Contenedor");
            contenedor_form->set_idProducto(cod);
            bool add=contenedor_form->add_Product();
            if(add)
            {
                query.prepare("DELETE FROM Producto_has_Vitrina WHERE Producto_idProducto=? and fila=? and columna=? and nivel=?");
                query.bindValue(0,idProducto);
                query.bindValue(1,fila);
                query.bindValue(2,col);
                query.bindValue(3,nivel);
                query.exec();

            }
        }
        else*/
        {
            contenedor_form->set_idContenedor(currentIdContenedor);
            contenedor_form->set_behavior(1);
            contenedor_form->update_form();
            contenedor_form->setWindowTitle("Editar Contenedor");
        }
    }

    contenedor_form->show();
}

void ui_almacen::on_tableWidget_griContenedores_itemSelectionChanged()
{

}

void ui_almacen::on_botonGenerarReporte_clicked()
{
    NCReport *report = new NCReport();
    report->setReportFile( "ReporteContenedores.ncr" );
    //report->runReportToPDF( "reporteContenedoresProductos.pdf" );

    NCReportOutput *output=0;

    output = new NCReportPreviewOutput();
    output->setAutoDelete( false );
    report->setOutput( output );


    /*QString fileName = QFileDialog::getSaveFileName(this, tr("Save PDF File"),
    "report.pdf", tr("Pdf files (*.pdf)"));
    if ( fileName.isEmpty() )
        delete report;*/


    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    report->runReport();
    //report->runReportToPreview();
    bool error = report->hasError();
    QString err = report->lastErrorMsg();
    QApplication::restoreOverrideCursor();

    if ( error )
        QMessageBox::information( 0, "Riport error", err );
    else
    {
            //-----------------------------
            // PRINT PREVIEW
            //-----------------------------
            NCReportPreviewWindow *pv = new NCReportPreviewWindow();
            pv->setReport( report );
            pv->setOutput( (NCReportPreviewOutput*)output );
            pv->setWindowModality(Qt::ApplicationModal );
            pv->setAttribute( Qt::WA_DeleteOnClose );
            pv->show();
    }

}

void ui_almacen::on_pushButton_aceptar_clicked()
{
    if(indice.row() < 0 || indice.column() < 0 )
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Seleccione una posicion al que desea mover");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }

    object_Contenedor_has_Producto producto_almacen;
    producto_almacen.mf_set_Contenedor_idContenedor(currentIdContenedor);    
    producto_almacen.mf_set_Producto_idProducto(currentCod);
    producto_almacen.mf_set_Colaborador_Persona_idPersona(QString::number(Sesion::getIdColaborador()));
    producto_almacen.mf_set_fecha(QDate::currentDate().toString(Qt::ISODate));        
    producto_almacen.mf_set_cantidadProducto(QString::number(cantidadProducto));

    if(producto_almacen.mf_exist_product())
    {

        if(!producto_almacen.mf_update())
        {
            QMessageBox box;
            box.setIcon(QMessageBox::Warning);
            box.setWindowTitle("Advertencia");
            box.setText("No se logro actualizar la cantidad de productos");
            box.setStandardButtons(QMessageBox::Ok);
            box.exec();
            return;
        }
    }
    else
    {
        if(!producto_almacen.mf_add())
        {            
            QMessageBox box;
            box.setIcon(QMessageBox::Warning);
            box.setWindowTitle("Advertencia");
            box.setText("No se logro agregar el producto al contenedor");
            box.setStandardButtons(QMessageBox::Ok);
            box.exec();
            return;
        }
    }

    /**
     *COMPORTAMIENTO
     *1 DE PRODUCTOS A ALAMCEN
     *2 DE VITRINA A ALMACEN
     *3 DE ALMACEN A ALMACEN
     **/
    if(comportamiento == 1)
    {
        actualizar_cantidad_almacen(cantidadProducto,currentCod);
        emit actualizar_lista_productos();
        close();

    }
    if(comportamiento == 2)
    {
        actualizar_cantidad_almacen(cantidadProducto,currentCod);
        actualizar_cantidad_vitrina(-cantidadProducto,currentCod);
        emit actualizar_grilla_vitrina();
        close();
    }
    if(comportamiento == 3)
    {
        emit traspaso_almacen(cantidadProducto);
    }
    ui->pushButton_aceptar->hide();


}

void ui_almacen::on_tableWidget_griContenedores_clicked(const QModelIndex &index)
{
    indice = index;
    QString fila = QString::number(indice.row()+1);
    QString columna = QString::number(indice.column()+1);
    QString pos = fila+"-"+columna;
    if(Contenedor[pos].size() == 0)
    {
        ui->pushButton_aceptar->setEnabled(false);
    }
    else
    {
        ui->pushButton_aceptar->setEnabled(true);
        set_currentIdContenedor(Contenedor[pos]);
    }
}
bool ui_almacen::actualizar_cantidad_vitrina(int cant, QString id)
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

bool ui_almacen::actualizar_cantidad_almacen(int cant, QString id)
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

