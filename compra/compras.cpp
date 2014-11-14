#include "compras.h"
#include "ui_compras.h"
#include "ui_datos_compras.h"
#include <QString>
#include <QSqlQuery>
#include "ui_cant_item.h"
#include<QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <compra/ui_proveedores.h>
#include <producto/ui_producto.h>
#include <compra/object_Compra.h>
#include <compra/object_Compra_has_Proveedor.h>
#include <compra/object_Producto_has_Compra.h>

//Esta es una interfaz de compras
compras::compras(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::compras)
{
    ui->setupUi(this);
    contador = 0;

    currentCant = 0;
    compra_total = 0;
    ui->dateEdit->setDate(QDate::currentDate());
    updateListCompras();
    ui->lineEdit_ruc->setReadOnly(true);
    ui->lineEdit_direccion->setReadOnly(true);
    ui->lineEdit_subtotal->setReadOnly(true);
    ui->lineEdit_igv->setReadOnly(true);
    ui->lineEdit_total->setReadOnly(true);
    actualCompra = new compra;
    igv = Sesion::getIgv();    
    ui->lineEdit_igv->setText("IGV"+QString::number(igv)+"%");
    ui->dateEdit->setDate(QDate::currentDate());
    ui->tableWidget__items_productos->setColumnWidth(1,600);


}

compras::~compras()
{
    delete actualCompra;
    delete ui;
}

void compras::on_pushButton_clicked()
{
    ui_datos_compras* compras = new ui_datos_compras;
    compras->show();

}


void compras::on_pushButton_buscar_proveedor_clicked()
{
    ui_proveedores * form = new ui_proveedores;
    form->show();
    connect(form,SIGNAL(sentidProveedor(QString,QString,QString,QString)),this,SLOT(getProveedor(QString,QString,QString,QString)));

}

void compras::on_pushButton_buscar_producto_clicked()
{
    ui_producto * form = new ui_producto;
    form->setWindowTitle("Buscar Proveedor");
    form->setComportamiento(1);
    connect(form,SIGNAL(sentProductoCompra(QString,QString,QString,int)),this,SLOT(addItemProductos(QString,QString,QString,int)));
    form->show();
}



void compras::on_pushButton_guardar_clicked()
{
    //Vefificando el si hay elementos en la tabla
    if(ui->lineEdit_Num_Docuemento->text().size() == 0)
    {   QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Inserte el numero de documento");
        msgBox->show();
        return;
    }
    if(ui->tableWidget__items_productos->rowCount() == 0)
    {   QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Inserte un producto");
        msgBox->show();
        return;
    }
    if(ui->lineEdit_ruc->text().size() == 0)
    {

        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Seleccione un proveedor");
        msgBox->show();
        return;
    }
    if(ui->tableWidget__items_productos->rowCount() == 0)
    {

        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Seleccione un producto");
        msgBox->show();
        return;
    }
    bool insertado = false;

    QString idcompra,total;
    QDate fecha = ui->dateEdit->date();    
    //Total de la Venta
    total = ui->lineEdit_total->text();
    int tipoDocumento = 0;
    //Factura 0, Boleta 1
    if(ui->radioButton_Factura->isChecked())
        tipoDocumento = 0;
    else
        tipoDocumento = 1;

    QString serieDocuemento = ui->spinBox_Serie->text();
    QString numeroDocumento = ui->lineEdit_Num_Docuemento->text();

    object_Compra n_compra(fecha.toString(Qt::ISODate),total,C_NO_HABILITADO,QString::number(tipoDocumento),serieDocuemento,numeroDocumento);

    if(n_compra.mf_add())
        insertado = true;
    else
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Fallo al insertar compra");
        msgBox->show();
        insertado = false;
        return;
    }
    idcompra = n_compra.mf_get_lastId();    
    object_Compra_has_Proveedor n_proveedor(idcompra,idProveedor,QString::number(Sesion::getIdColaborador()));
    if(n_proveedor.mf_add())
        insertado = true;
    else
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Fallo al insertar Proveedor de Compra");
        msgBox->show();
        insertado = false;
        return;
    }
    object_Producto_has_Compra n_producto;
    QString idProducto;
    int cant;
    for (int i = 0; i<ui->tableWidget__items_productos->rowCount(); i++)
           {
               idProducto = ui->tableWidget__items_productos->item(i,0)->text();
               n_producto.mf_set_Producto_idProducto(idProducto);
               n_producto.mf_set_descripcion(ui->tableWidget__items_productos->item(i,1)->text());
               n_producto.mf_set_precio(ui->tableWidget__items_productos->item(i,2)->text());
               n_producto.mf_set_cantidad(ui->tableWidget__items_productos->item(i,3)->text());
               n_producto.mf_set_Compra_idCompra(idcompra);
               if(!n_producto.mf_add())
               {

                   QMessageBox *msgBox =new QMessageBox;
                   msgBox->setIcon(QMessageBox::Warning);
                   msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
                   msgBox->setText("Fallo al insertar un producto de Compra");
                   msgBox->show();
                   insertado = false;
                   return;
               }
               else
               {
                   object_Producto  p;
                   cant = ui->tableWidget__items_productos->item(i,3)->text().toInt();
                   p.mf_set_idProducto(idProducto);
                   p.mf_load(idProducto);
                   if(!p.mf_update_cant_stock(cant))
                   {
                       QMessageBox msgBox;
                       msgBox.setText(QString("No se logro aumentar stock de producto con id: "+ idProducto));
                       msgBox.exec();
                       return;
                   }


                   QString descripcion = "Aumento de stock por compra "+fecha.toString(Qt::ISODate)+" "+serieDocuemento+"-"+numeroDocumento+" "+ui->lineEdit_proveedor->text();

                   if(!p.mf_registrarKardex(cant,p.mf_get_stock().toInt(),descripcion,1))
                   {
                       QMessageBox msgBox;
                       msgBox.setText(QString("No se logro registrar kardex del producto con id: "+idProducto));
                       msgBox.exec();
                       return;
                   }

               }
            }
    if(insertado)
    {
        //AUMENTANDO STOCK
        //REGISTRANDO KARDEK

        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Compra Agregada");
        msgBox->show();
        updateListCompras();
        this->on_pushButton_limpiar_clicked();

    }

}
void compras::addItemProductos(QString codigo, QString descripcion, QString precio, int cant)
{
        int cantidad = cant;
        float preciof = precio.toDouble()/((igv/100)+1);

        //Quitando el IGV
        double total = cantidad*preciof;
        compra_total += total;

        double monto_sub_total;
        double monto_impuesto;
        double monto_total;

        monto_sub_total = compra_total;
        monto_impuesto = (monto_sub_total * igv/100);        
        monto_total = monto_sub_total + monto_impuesto;
        ui->tableWidget__items_productos->insertRow(contador);
        ui->tableWidget__items_productos->setItem(contador,0, new QTableWidgetItem(codigo));
        ui->tableWidget__items_productos->setItem(contador,1, new QTableWidgetItem(descripcion));        
        ui->tableWidget__items_productos->setItem(contador,2, new QTableWidgetItem(QString::number(preciof)));
        ui->tableWidget__items_productos->setItem(contador,3, new QTableWidgetItem(QString::number(cantidad)));
        ui->tableWidget__items_productos->setItem(contador,4, new QTableWidgetItem(QString::number(total)));
        contador++;
        Productos_Agregados[codigo] = Productos[codigo];
        ui->lineEdit_subtotal->setText(QString::number(monto_sub_total));
        ui->lineEdit_igv->setText(QString::number(monto_impuesto));
        ui->lineEdit_total->setText(QString::number(monto_total));
}
void compras::updateListCompras()
{
    ui->tableView_compras->setModel(object_Compra::mostrar());
    ui->tableView_compras->setColumnWidth(2,400);

}
void compras::on_tableWidget_Compras_itemClicked(QTableWidgetItem *item)
{

    currentItem = item->row();

}

void compras::on_pushButton_ver_compra_clicked()
{

}

void compras::on_lineEdit_proveedor_returnPressed()
{
    on_pushButton_buscar_proveedor_clicked();
}

void compras::on_lineEdit_productos_returnPressed()
{
    on_pushButton_buscar_producto_clicked();
}

void compras::on_tableWidget_Compras_doubleClicked(const QModelIndex &index)
{
    /*on_tableWidget_Compras_itemClicked();
    on_pushButton_ver_compra_clicked();*/
}


void compras::on_tableWidget__items_productos_itemDoubleClicked(QTableWidgetItem *item)
{
    int count = item->row();
    double total = ui->tableWidget__items_productos->item(count,4)->text().toDouble();
    compra_total -= total;
    double monto_sub_total;
    double monto_impuesto;
    double monto_total;

    ui->tableWidget__items_productos->removeRow(count);
    if(ui->tableWidget__items_productos->rowCount() == 0)
    {
        //Reseteando la Compra
        compra_total = 0;
    }
    monto_sub_total = compra_total;
    monto_impuesto = (monto_sub_total * igv/100);
    monto_total = monto_sub_total + monto_impuesto;
    ui->lineEdit_subtotal->setText(QString::number(monto_sub_total));
    ui->lineEdit_igv->setText(QString::number(monto_impuesto));
    ui->lineEdit_total->setText(QString::number(monto_total));    
    contador--;    
}


void compras::on_pushButton_eliminar_compra_clicked()
{

    QMessageBox *msgBox =new QMessageBox;
    msgBox->setIcon(QMessageBox::Warning);
    msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
    msgBox->setWindowTitle("Confirmar");
    msgBox->setText("Desea eliminar el la compra seleccionada?");
    msgBox->setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
    msgBox->setButtonText(QMessageBox::Cancel,"Cancelar");

    int ret = msgBox->exec();

    switch(ret)
    {
        case QMessageBox::Ok:
    {
            QSqlQuery query;
            query.prepare("DELETE FROM compra WHERE idcompra = \""+current_idCompras+"\"");
            if(query.exec() == true)
            {
                qDebug()<<"Borrador compra"<<endl;
            }
            updateListCompras();
            break;
    }
        case QMessageBox::Cancel:
            break;
    }

}
void compras::getProveedor(QString id,QString ruc,QString razon,QString direccion)
{
    //Actualizando Proveedor
    idProveedor = id;
    actualCompra->setDatosProveedor(id,ruc,razon,direccion);
    ui->lineEdit_ruc->setText(ruc);
    ui->lineEdit_proveedor->setText(razon);
    ui->lineEdit_direccion->setText(direccion);
}



void compras::on_tableWidget__items_productos_doubleClicked(const QModelIndex &index)
{

}

void compras::on_pushButton_limpiar_clicked()
{
    //LIMPIANDO INTERFAZ
    ui->radioButton_Factura->setChecked(true);
    ui->spinBox_Serie->setValue(0001);
    ui->lineEdit_Num_Docuemento->clear();
    ui->dateEdit->setDate(QDate::currentDate());



    //LIMPIANDO DATOS
    ui->lineEdit_proveedor->clear();
    ui->lineEdit_ruc->clear();
    ui->lineEdit_direccion->clear();
    ui->lineEdit_productos->clear();
    for (int i=ui->tableWidget__items_productos->rowCount()-1; i >= 0; --i)
        ui->tableWidget__items_productos->removeRow(i);
    ui->lineEdit_subtotal->clear();
    ui->lineEdit_igv->clear();
    ui->lineEdit_total->clear();
    ui->lineEdit_proveedor->setFocus();
    contador = 0;
    currentCant = 0;
    compra_total = 0;
    habilitarInterfaz(true);

}

void compras::on_tableView_compras_doubleClicked(const QModelIndex &index)
{
    this->on_pushButton_limpiar_clicked();

    QString idCompra = ui->tableView_compras->model()->index(index.row(),0).data().toString();

    object_Compra mycompra;
    mycompra.mf_load(idCompra);
    object_Compra_has_Proveedor cp;
    object_proveedor myProveedor;
    if(cp.mf_load(idCompra))
        //myProveedor = cp.mf_getProveedor();
    {
        if(!myProveedor.mf_load(cp.mf_get_Proveedor_idProveedor()))
        {
            qDebug()<<"No logro cargar proveedor"<<endl;
        }
    }
    else
    {
        qDebug()<<"No logro cargar compra"<<endl;
    }
    object_Producto_has_Compra pc;


    QVector<object_Producto_has_Compra> lista = mycompra.mf_get_listProducto_has_Compra();
    //LENANDO DATOS
    if(mycompra.mf_get_tipo() == "0")
        ui->radioButton_Factura->click();
    if(mycompra.mf_get_tipo() == "1")
        ui->radioButton_Boleta->click();
    ui->spinBox_Serie->setValue(mycompra.mf_get_serie().toInt());
    ui->lineEdit_Num_Docuemento->setText(mycompra.mf_get_numero());
    ui->dateEdit->setDate(QDate::fromString(mycompra.mf_get_fecha(),Qt::ISODate));
    ui->lineEdit_proveedor->setText(myProveedor.mf_get_raz_social());
    ui->lineEdit_ruc->setText(myProveedor.mf_get_ruc());
    ui->lineEdit_direccion->setText(myProveedor.mf_get_direccion());

    for(int i=0;i<lista.size();i++)
    {
        pc = lista[i];
        addItemProductos(pc.mf_get_Producto_idProducto(),pc.mf_get_descripcion(),pc.mf_get_precio(),pc.mf_get_cantidad().toInt());
    }

    habilitarInterfaz(false);
    ui->tabWidget->setCurrentIndex(1);
}

void compras::habilitarInterfaz(bool flag)
{
    ui->pushButton_guardar->setEnabled(flag);
    ui->pushButton_buscar_producto->setEnabled(flag);
    ui->pushButton_buscar_proveedor->setEnabled(flag);
    ui->pushButton_cancelar->setEnabled(flag);



    ui->radioButton_Factura->setEnabled(flag);
    ui->radioButton_Boleta->setEnabled(flag);
    ui->spinBox_Serie->setEnabled(flag);
    ui->lineEdit_Num_Docuemento->setEnabled(flag);
    ui->dateEdit->setEnabled(flag);



    //LIMPIANDO DATOS
    ui->lineEdit_proveedor->setEnabled(flag);
    ui->lineEdit_ruc->setEnabled(flag);
    ui->lineEdit_direccion->setEnabled(flag);
    ui->lineEdit_productos->setEnabled(flag);

    ui->lineEdit_subtotal->setEnabled(flag);
    ui->lineEdit_igv->setEnabled(flag);
    ui->lineEdit_total->setEnabled(flag);
    ui->lineEdit_proveedor->setEnabled(flag);

    ui->tableWidget__items_productos->setEnabled(flag);


}

void compras::loadCompra(QString idCompra)
{
    this->on_pushButton_limpiar_clicked();
    object_Compra mycompra;
    mycompra.mf_load(idCompra);
    object_Compra_has_Proveedor cp;
    object_proveedor myProveedor;
    if(cp.mf_load(idCompra))
        //myProveedor = cp.mf_getProveedor();
    {
        if(!myProveedor.mf_load(cp.mf_get_Proveedor_idProveedor()))
        {
            qDebug()<<"No logro cargar proveedor"<<endl;
        }
    }
    else
    {
        qDebug()<<"No logro cargar compra"<<endl;
    }
    object_Producto_has_Compra pc;


    QVector<object_Producto_has_Compra> lista = mycompra.mf_get_listProducto_has_Compra();
    //LENANDO DATOS
    if(mycompra.mf_get_tipo() == "0")
        ui->radioButton_Factura->click();
    if(mycompra.mf_get_tipo() == "1")
        ui->radioButton_Boleta->click();
    ui->spinBox_Serie->setValue(mycompra.mf_get_serie().toInt());
    ui->lineEdit_Num_Docuemento->setText(mycompra.mf_get_numero());
    ui->dateEdit->setDate(QDate::fromString(mycompra.mf_get_fecha(),Qt::ISODate));
    ui->lineEdit_proveedor->setText(myProveedor.mf_get_raz_social());
    ui->lineEdit_ruc->setText(myProveedor.mf_get_ruc());
    ui->lineEdit_direccion->setText(myProveedor.mf_get_direccion());

    for(int i=0;i<lista.size();i++)
    {
        pc = lista[i];
        addItemProductos(pc.mf_get_Producto_idProducto(),pc.mf_get_descripcion(),pc.mf_get_precio(),pc.mf_get_cantidad().toInt());
    }

    habilitarInterfaz(false);
    ui->tabWidget->setCurrentIndex(1);

}
