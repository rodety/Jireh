#include "ui_agregar_empresa.h"
#include "ui_ui_agregar_empresa.h"
#include "empresa.h"

ui_agregar_empresa::ui_agregar_empresa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_agregar_empresa)
{
    ui->setupUi(this);
}

ui_agregar_empresa::~ui_agregar_empresa()
{
    delete ui;
}
void ui_agregar_empresa::set_idEmpresa(QString idEmpresa)
{
    this->idEmpresa = idEmpresa;
}
QString ui_agregar_empresa::get_idEmpresa()
{
    return idEmpresa;
}

int ui_agregar_empresa::get_behavior()
{
    return behavior;
}
void ui_agregar_empresa::set_behavior(int c)
{
    this->behavior = c;
}
void ui_agregar_empresa::update_form()
{
    ui->lineEdit__ruc->clear();
    ui->lineEdit_raz_social->clear();
    ui->lineEdit__direccion->clear();
    ui->lineEdit_telefono->clear();
    ui->lineEdit_representante->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_web->clear();

    qDebug()<<"Id Empresa" <<idEmpresa<<endl;
    QSqlQuery query;
    query.prepare("SELECT razonSocial,ruc,direccion,telefono,representa_legal,email,web FROM Empresa WHERE idEmpresa=?");
    query.bindValue(0,idEmpresa);
    query.exec();
    query.next();


    QString raz_social = query.value(0).toString();
    QString ruc = query.value(1).toString();
    QString direccion = query.value(2).toString();
    QString telefono = query.value(3).toString();
    QString representante = query.value(4).toString();
    QString email = query.value(5).toString();
    QString web = query.value(6).toString();

    ui->lineEdit_raz_social->setText(raz_social);
    ui->lineEdit__ruc->setText(ruc);
    ui->lineEdit__direccion->setText(direccion);
    ui->lineEdit_telefono->setText(telefono);
    ui->lineEdit_representante->setText(representante);
    ui->lineEdit_email->setText(email);
    ui->lineEdit_web->setText(web);
}

void ui_agregar_empresa::on_pushButton_accept_clicked()
{
    QString ruc = ui->lineEdit__ruc->text();
    QString raz_social = ui->lineEdit_raz_social->text();
    QString direccion = ui->lineEdit__direccion->text();
    QString telefono = ui->lineEdit_telefono->text();
    QString representante = ui->lineEdit_representante->text();
    QString email = ui->lineEdit_email->text();
    QString web = ui->lineEdit_web->text();

    empresa* empresa_data;

    switch(behavior)
    {
        case 0:
            empresa_data  = new empresa(idEmpresa,raz_social,ruc,direccion,telefono,representante,email,web);
            empresa_data->actualizar();
            break;
        case 1:
            empresa_data  = new empresa(idEmpresa,raz_social,ruc,direccion,telefono,representante,email,web);
            empresa_data->agregar();
            break;
    }
    close();
    emit actualizarParent();
}

void ui_agregar_empresa::on_pushButton_cancel_clicked()
{
    close();
}
