#include "ui_tarjeta.h"
#include "ui_ui_tarjeta.h"
#include "venta/object_VentaPlazo.h"
#include "venta/object_Venta.h"


ui_tarjeta::ui_tarjeta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_tarjeta)
{
    ui->setupUi(this);
    ui->comboBox_tarjeta->setTipo("tarjeta");
    ui->comboBox_tarjeta->ActualizarItems(object_Tarjeta::mostrarId());
    ui->dateEdit->setDate(QDate::currentDate());
    ui->lineEdit_Monto->setEnabled(false);

    /*QRegExp rx("[0-9]\\d{0,9}");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_Afiliacion->setValidator(validator);
    ui->lineEdit_id->setValidator(validator);
    ui->lineEdit_Lote->setValidator(validator);
    ui->lineEdit_numero_Tarjeta->setValidator(validator);
    ui->lineEdit_Referencia->setValidator(validator);*/
}

ui_tarjeta::~ui_tarjeta()
{
    delete msgBox;
    delete ui;
}

void ui_tarjeta::on_pushButton_guardar_clicked()
{
    //Validaciones Basicas
    msgBox =new QMessageBox;
    if(ui->dateEdit->date() < QDate::currentDate())
    {
        QString str_warning = ui->dateEdit->date().toString(Qt::ISODate);

        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setWindowTitle("La fecha es correcta?");
        msgBox->setWindowIcon(QIcon(":/new/add1-.png"));
        msgBox->setText(str_warning);
        msgBox->setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox->setDefaultButton(QMessageBox::Save);
        msgBox->setButtonText(QMessageBox::Save, "Si");
        msgBox->setButtonText(QMessageBox::Cancel, "No");
        int ret = msgBox->exec();

        switch (ret) {
           case QMessageBox::Save:
               // Save was clicked
               break;
           case QMessageBox::Cancel:
                return;
               // Cancel was clicked
               break;
           default:
               // should never be reached
               break;
         }
    }

    if(!ui->comboBox_tarjeta->selecciono())
    {
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Selecciones una categoria de tarjeta");
        msgBox->show();
        return;
    }
    if(ui->lineEdit_id->text().size() == 0)
    {
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Ingrese Id de transaccion");
        msgBox->show();
        return;
    }
    if(ui->lineEdit_numero_Tarjeta->text().size() == 0)
    {
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Ingrese numero de transaccion");
        msgBox->show();
        return;
    }
    if(ui->lineEdit_Referencia->text().size() == 0)
    {
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Ingrese Referencia de transaccion");
        msgBox->show();
        return;
    }
    if(ui->lineEdit_Lote->text().size() == 0)
    {
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Ingrese Lote de transaccion");
        msgBox->show();
        return;
    }
    if(ui->lineEdit_Monto->text().size() == 0)
    {
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Ingrese Monto de transaccion");
        msgBox->show();
        return;
    }
    if(ui->lineEdit_Afiliacion->text().size() == 0)
    {
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Ingrese codigo de afiliacion");
        msgBox->show();
        return;
    }
    if(ui->lineEdit_nombre_pagador->text().size() == 0)
    {
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Ingrese Nombre del pagador");
        msgBox->show();
        return;
    }



    object_Tarjeta pTarjeta;
    pTarjeta.mf_set_nombre(ui->comboBox_tarjeta->currentText());
    pTarjeta.mf_set_idTarjeta(QString::number(ui->comboBox_tarjeta->getId(ui->comboBox_tarjeta->currentText())));
    mtarjeta.mf_set_Tarjeta_idTarjeta(pTarjeta.mf_get_idTarjeta());
    mtarjeta.mf_set_id(ui->lineEdit_id->text());
    mtarjeta.mf_set_tarjeta(ui->lineEdit_numero_Tarjeta->text());
    mtarjeta.mf_set_referencia(ui->lineEdit_Referencia->text());
    mtarjeta.mf_set_lote(ui->lineEdit_Lote->text());
    mtarjeta.mf_set_fecha(ui->dateEdit->date().toString(Qt::ISODate));
    mtarjeta.mf_set_monto(ui->lineEdit_Monto->text());
    mtarjeta.mf_set_codigoAfiliacion(ui->lineEdit_Afiliacion->text());
    mtarjeta.mf_set_nombre_pagador(ui->lineEdit_nombre_pagador->text());

    if(!mtarjeta.mf_update())
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Fallo al actualizar tarjeta");
        msgBox->show();
        return;
    }
    object_VentaPlazo vp;
    if(!vp.mf_register(idVentaPlazo))
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Fallo al actualizar registro en Venta a Plazos");
        msgBox->show();
        return;
    }


    if(vp.mf_verifyRegister(idVenta))
    {
        object_Venta v;
        if(!v.mf_update_register(idVenta,"1"))
        {
            QMessageBox *msgBox =new QMessageBox;
            msgBox->setIcon(QMessageBox::Information);
            msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
            msgBox->setText("Fallo al Registro de Tarjeta en Venta");
            msgBox->show();
            return;
        }
    }
    emit actualizarListaPagos();


    this->close();


}

void ui_tarjeta::set_idVenta(QString id)
{
    idVenta = id;
}

void ui_tarjeta::set_monto(QString money)
{
    ui->lineEdit_Monto->setText(money);
}
void ui_tarjeta::set_nombre_pagador(QString tmp)
{
    ui->lineEdit_nombre_pagador->setText(tmp);
}

void ui_tarjeta::load_data(object_Venta_has_Tarjeta *datos)
{
    ui->dateEdit->setDate(QDate::fromString(datos->mf_get_fecha(),Qt::ISODate));
    object_Tarjeta v_tarjeta;
    v_tarjeta.mf_load(datos->mf_get_Tarjeta_idTarjeta());
    ui->comboBox_tarjeta->buscarValor(v_tarjeta.mf_get_nombre());    
    ui->lineEdit_id->setText(datos->mf_get_id());
    ui->lineEdit_numero_Tarjeta->setText(datos->mf_get_tarjeta());
    ui->lineEdit_Referencia->setText(datos->mf_get_referencia());
    ui->lineEdit_Lote->setText(datos->mf_get_lote());
    ui->lineEdit_Monto->setText(datos->mf_get_monto());
    ui->lineEdit_Afiliacion->setText(datos->mf_get_codigoAfiliacion());
    ui->lineEdit_nombre_pagador->setText(datos->mf_get_nombre_pagador());
    mtarjeta = *datos;
}
void ui_tarjeta::set_idVentaPlazo(QString id)
{
    idVentaPlazo = id;
}
