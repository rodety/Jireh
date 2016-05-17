#include "ui_trabajosextras.h"
#include "ui_ui_trabajosextras.h"

ui_trabajosExtras::ui_trabajosExtras(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_trabajosExtras)
{
    ui->setupUi(this);
    modo=0;
    //QRegExp rx("[1-9]\\d{0,9}");
    QRegExp rx("\\d*\\.\\d+");
    validator = new QRegExpValidator(rx, this);
    ui->lineEdit_Descuento->setValidator(validator);
    ui->lineEdit_precio->setValidator(validator);
}

ui_trabajosExtras::~ui_trabajosExtras()
{
    delete validator;
    delete ui;
}

void ui_trabajosExtras::setModo(bool m)
{
    modo=m;
}
void ui_trabajosExtras::setTrabajosExtras(trabajosExtras *t)
{
    pTrabajosExtras=*t;
    ui->lineEdit_descripcion->setText(pTrabajosExtras.getDescripcion());
    ui->lineEdit_precio->setText(pTrabajosExtras.getPrecio());
    ui->lineEdit_Descuento->setText(pTrabajosExtras.getDescuento());
}

bool ui_trabajosExtras::verificarRestricciones()
{
    QMessageBox box;
    box.setIcon(QMessageBox::Warning);
    box.setWindowTitle("Error de Escritura");

    if(ui->lineEdit_descripcion->text().size() == 0)
    {
        box.setText("La Descripcion es obligatoria");
        box.exec();
        ui->lineEdit_descripcion->setFocus();
        return false;
    }
    return true;
}

void ui_trabajosExtras::on_pushButton_agregar_clicked()
{
    if(!verificarRestricciones())
        return;

    pTrabajosExtras.setDescripcion(ui->lineEdit_descripcion->text());
    pTrabajosExtras.setPrecio(ui->lineEdit_precio->text());
    pTrabajosExtras.setDescuento(ui->lineEdit_Descuento->text());
    if(modo==false)//agrego
    {
        if(pTrabajosExtras.agregar())
        {
            this->close();
            emit guardado();
        }
        else
        {
            QMessageBox box;
            box.setIcon(QMessageBox::Critical);
            box.setWindowTitle("Error");
            box.setText("El Trabajo Extra no se pudo agregar!");
            box.setStandardButtons(QMessageBox::Ok);
            box.setDefaultButton(QMessageBox::Ok);
            box.exec();
        }
    }
    else//actualizo
    {
        if(pTrabajosExtras.actualizar())
        {
            this->close();
            emit guardado();
        }
        else
        {
            QMessageBox box;
            box.setIcon(QMessageBox::Critical);
            box.setWindowTitle("Error");
            box.setText("El Trabajo Extra no se pudo actualizar!");
            box.setStandardButtons(QMessageBox::Ok);
            box.setDefaultButton(QMessageBox::Ok);
            box.exec();
        }
    }
}
