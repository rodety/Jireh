#include "ui_cambiarpassdialog.h"
#include "ui_ui_cambiarpassdialog.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QSqlQuery>
#include <QPushButton>

ui_cambiarPassDialog::ui_cambiarPassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ui_cambiarPassDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("&Cancelar");
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

ui_cambiarPassDialog::~ui_cambiarPassDialog()
{
    delete ui;
}

void ui_cambiarPassDialog::on_buttonBox_accepted()
{
    QString pass1 = ui->lineEdit_nuevoPass->text();
    QString pass2 = ui->lineEdit_confPass->text();
    if(pass1!=pass2)
    {
        QMessageBox::warning(0,"Cambio Contraseña","Las contraseñas no coinciden",0,0);
        setResult(QDialog::Rejected);
        return;
    }
    QString a;
    QSqlQuery q;    
    bool sta = q.exec("UPDATE Colaborador SET contrasena = MD5('"+pass1+"'), resset_pass = 0 WHERE idColaborador = "+a.setNum(id_usr));
    if(!sta)
        QMessageBox::warning(0,"Error","No se pudo actualizar las contrasenas",0,0);
}

void ui_cambiarPassDialog::on_buttonBox_rejected()
{

}

void ui_cambiarPassDialog::on_lineEdit_nuevoPass_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
    else
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

void ui_cambiarPassDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    /*if(button->text()=="&OK");
    {

    }*/
}
