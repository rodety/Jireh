#include "ui_proveedores.h"
#include "ui_ui_proveedores.h"
#include "ui_datos_proveedor.h"
#include "proveedor.h"
ui_proveedores::ui_proveedores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_proveedores)
{
    ui->setupUi(this);
    update_list_proveedores();
}

ui_proveedores::~ui_proveedores()
{
    delete ui;
}


void ui_proveedores::on_pushButton_add_proveedor_clicked()
{
    ui_datos_proveedor *proveedor = new ui_datos_proveedor;
    proveedor->set_ui_proveedor_parent(this);
    proveedor->set_behavior(0);
    proveedor->setWindowTitle("Nuevo Proveedor");
    proveedor->show();

}
QString ui_proveedores::get_currentidProveedor()
{
    return currentIdProveedor;
}
void ui_proveedores::set_currentidProveedor(QString id)
{
    currentIdProveedor = id;
}
void ui_proveedores::update_list_proveedores()
{
    for (int i=ui->tableWidget->rowCount()-1; i >= 0; --i)
        ui->tableWidget->removeRow(i);

    QString id;
    QString razonSocial;
    QString ruc;
    QString direccion;
    QString telefono1;
    QString telefono2;
    QString nombre_contacto;
    QString email;
    QString nombre_banco;
    QString numero_cuenta;
    QString comentario;
    QSqlQuery query;
    query.prepare("SELECT idProveedor,raz_social,ruc,direccion,telefono1,telefono2,nombre_contacto,email,nombre_banco,numero_cuenta,comentario FROM Proveedor");
    query.exec();

    int c = 0;

       while(query.next())
       {
           id = query.value(0).toString();
           razonSocial = query.value(1).toString();
           ruc = query.value(2).toString();
           direccion =query.value(3).toString();
           telefono1 =query.value(4).toString();
           telefono2 =query.value(5).toString();
           nombre_contacto =query.value(6).toString();
           email = query.value(7).toString();
           nombre_banco = query.value(8).toString();
           numero_cuenta = query.value(9).toString();
           comentario = query.value(10).toString();
           Proveedores[razonSocial] = id;

           ui->tableWidget->insertRow(c);

           ui->tableWidget->setItem(c,0, new QTableWidgetItem(ruc));
           ui->tableWidget->setItem(c,1, new QTableWidgetItem(razonSocial));
           ui->tableWidget->setItem(c,2, new QTableWidgetItem(direccion));
           ui->tableWidget->setItem(c,3, new QTableWidgetItem(telefono1));
           ui->tableWidget->setItem(c,4, new QTableWidgetItem(telefono2));
           ui->tableWidget->setItem(c,5, new QTableWidgetItem(nombre_contacto));
           ui->tableWidget->setItem(c,6, new QTableWidgetItem(email));
           ui->tableWidget->setItem(c,7, new QTableWidgetItem(nombre_banco));
           ui->tableWidget->setItem(c,8, new QTableWidgetItem(numero_cuenta));
           ui->tableWidget->setItem(c,9, new QTableWidgetItem(comentario));
           c++;
       }
}

void ui_proveedores::on_pushButton_edit_proveedor_clicked()
{
    ui_datos_proveedor *proveedor = new ui_datos_proveedor;
    proveedor->setIdProveedor(get_currentidProveedor());
    proveedor->set_ui_proveedor_parent(this);
    proveedor->set_behavior(1);
    proveedor->update_form();
    proveedor->setWindowTitle("Editar Proveedor");
    proveedor->show();
}

void ui_proveedores::on_pushButton_sup_proveedor_clicked()
{
    proveedor* any_proveedor =  new proveedor;
    any_proveedor->setid(get_currentidProveedor());
    any_proveedor->eliminar();
    update_list_proveedores();
}

void ui_proveedores::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    int count = item->row();
    QString raz_social = ui->tableWidget->item(count,1)->text();
    set_currentidProveedor(Proveedores[raz_social]);
}



void ui_proveedores::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    int count = item->row();
    QString ruc = ui->tableWidget->item(count,0)->text();
    QString raz_social = ui->tableWidget->item(count,1)->text();
    QString direccion = ui->tableWidget->item(count,2)->text();
    set_currentidProveedor(Proveedores[raz_social]);
    emit sentidProveedor(currentIdProveedor,ruc,raz_social,direccion);
    this->close();
}
