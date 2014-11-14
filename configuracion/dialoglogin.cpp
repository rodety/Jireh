#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include "sesion.h"
#include "ui_cambiarpassdialog.h"
#include <QMessageBox>

DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
    Ok = false;
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::on_buttonBox_accepted()
{
    int status = Sesion::Iniciar(ui->lineEdit_Usuario->text(),ui->lineEdit_Password->text());
  switch(status)
  {
    case Sesion::PassUsrWrong :
      {
        QMessageBox::warning(0,"Inicio de Sesion",tr("Usuario o password INCORRECTOS"),0,0);
        return;
      }
    case Sesion::UsuarioDeshabilitado :
      {
        QMessageBox::warning(0,"Inicio de Sesion",tr("El usuario esta DESHABILITADO"),0,0);
        return;
      }
    case Sesion::SleepTime :
      {
        QMessageBox::warning(0,"Inicio de sesion","Excedio el numero de intentos fallidos\nInicio de sesion bloqueado por 20 segundos",0,0);
        return;
        //FALTA BLOQUEAR A LOS USUARIOS AGREGANDO DOS
        //CAMPOS A DB INTENTOS Y TIEMPO DE BLOQUEO
        //TABLA COLABORADOR
      }
    case Sesion::ResetPass:
      {
        ui_cambiarPassDialog cpd;
        Sesion* S = Sesion::getSesion();
        cpd.set_idusr(S->get_Usuario()->get_id());
        int code = cpd.exec();
        if(code == QMessageBox::Rejected)
        {
          this->ui->lineEdit_Usuario->setText("");
          this->ui->lineEdit_Password->setText("");
          return;
        }
      }
    case Sesion::inicioOK :
      {
            Ok=true;
            emit logOk();
            this->close();
      }
  }

}

void DialogLogin::on_buttonBox_rejected()
{

}
