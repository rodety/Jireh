#include "ui_datos_proveedor.h"
#include "ui_ui_datos_proveedor.h"
#include "proveedor.h"
#include <QMessageBox>
ui_datos_proveedor::ui_datos_proveedor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_datos_proveedor)
{
    ui->setupUi(this);
    QRegExp rx("[1-9]\\d{0,9}");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_ruc->setValidator(validator);

}

ui_datos_proveedor::~ui_datos_proveedor()
{

    delete ui;
}

void ui_datos_proveedor::setIdProveedor(QString id){ idProveedor = id;}
QString ui_datos_proveedor::getIdProveedor(){return idProveedor;}
void ui_datos_proveedor::set_ui_proveedor_parent(ui_proveedores* parent){ui_proveedores_parent = parent;}
ui_proveedores* ui_datos_proveedor::get_ui_proveedores_parent(){return ui_proveedores_parent;}
int ui_datos_proveedor::get_behavior(){return behavior;}
void ui_datos_proveedor::set_behavior(int val){behavior = val;}
void ui_datos_proveedor::update_form()
{
    ui->lineEdit_ruc->clear();
    ui->lineEdit_razon_social->clear();
    ui->lineEdit_direccion->clear();
    ui->lineEdit_telefono1->clear();
    ui->lineEdit_telefono2->clear();
    ui->lineEdit_nombre_contacto->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_nombre_banco->clear();
    ui->lineEdit_numero_cuenta->clear();
    ui->lineEdit_comentario->clear();

    QSqlQuery query;
    query.prepare("SELECT idProveedoor,raz_social,ruc,direccion,telefono1,telefono2,nombre_contacto,email,nombre_banco,numero_cuenta,comentario FROM Proveedor WHERE idProveedor=?");
    query.bindValue(0,ui_proveedores_parent->get_currentidProveedor());
    query.exec();
    query.next();

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

    ui->lineEdit_razon_social->setText(razonSocial);
    ui->lineEdit_ruc->setText(ruc);
    ui->lineEdit_direccion->setText(direccion);
    ui->lineEdit_telefono1->setText(telefono1);
    ui->lineEdit_telefono2->setText(telefono2);
    ui->lineEdit_nombre_contacto->setText(nombre_contacto);
    ui->lineEdit_email->setText(email);
    ui->lineEdit_nombre_banco->setText(nombre_banco);
    ui->lineEdit_numero_cuenta->setText(numero_cuenta);
    ui->lineEdit_comentario->setText(comentario);
}

void ui_datos_proveedor::on_pushButton_save_clicked()
{
    QString id = ui_proveedores_parent->get_currentidProveedor();
    QString razonSocial = ui->lineEdit_razon_social->text();
    QString ruc = ui->lineEdit_ruc->text();
    QString direccion = ui->lineEdit_direccion->text();
    QString telefono1 = ui->lineEdit_telefono1->text();
    QString telefono2 = ui->lineEdit_telefono2->text();
    QString nombre_contacto = ui->lineEdit_nombre_contacto->text();
    QString email = ui->lineEdit_email->text();
    QString nombre_banco = ui->lineEdit_nombre_banco->text();
    QString numero_cuenta = ui->lineEdit_numero_cuenta->text();
    QString comentario = ui->lineEdit_comentario->text();

    proveedor* proveedor_data;
    proveedor_data  = new proveedor(id,razonSocial,ruc,direccion,telefono1,telefono2,nombre_contacto,email,nombre_banco,numero_cuenta,comentario);
    switch(behavior)
        {
            case 0:
                if(!proveedor_data->agregar())
                {
                    QMessageBox msgBox;
                    msgBox.setText(QString("No se logro agregar Proveedor"));
                    msgBox.exec();
                }
                break;

            case 1:
                if(!proveedor_data->actualizar())
                {
                    QMessageBox msgBox;
                    msgBox.setText(QString("No se logro actualizar Proveedor"));
                    msgBox.exec();
                }
                break;
        }

    close();
    ui_proveedores_parent->update_list_proveedores();

}

void ui_datos_proveedor::on_pushButton_cancel_clicked()
{
    close();
}
