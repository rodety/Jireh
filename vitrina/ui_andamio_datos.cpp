#include "ui_andamio_datos.h"
#include "ui_ui_andamio_datos.h"
#include <QSqlQuery>
#include "andamio.h"
#include <QMessageBox>

ui_andamio_datos::ui_andamio_datos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_andamio_datos)
{
    ui->setupUi(this);
}

ui_andamio_datos::~ui_andamio_datos()
{
    delete ui;
}

QString ui_andamio_datos::get_idAlmacen(){return idAlmacen;}

void ui_andamio_datos::set_idAlmacen(QString an){idAlmacen = an;}

ui_almacen* ui_andamio_datos::get_ui_almacen_parent(){return ui_almacen_parent;}
void ui_andamio_datos::set_ui_almacen_parent(ui_almacen * al){ui_almacen_parent = al;}

int ui_andamio_datos::get_behavior(){return behavior;}
void ui_andamio_datos::set_behavior(int b){behavior = b;}

void ui_andamio_datos::update_form()
{
    ui->lineEdit_nombre->clear();
    ui->lineEdit_descripcion->clear();

    QSqlQuery query;
    query.prepare("SELECT nombre,descripcion,fila,columna FROM Andamio WHERE idAndamio=?");
    query.bindValue(0,ui_almacen_parent->get_currentIdAndamio());
    query.exec();
    query.next();

    QString nombre = query.value(0).toString();
    QString descripcion = query.value(1).toString();
    int fila = query.value(2).toInt();
    int columna = query.value(3).toInt();

    ui->lineEdit_nombre->insert(nombre);
    ui->lineEdit_descripcion->insert(descripcion);
    ui->spinBox_fila->setValue(fila);
    ui->spinBox_columna->setValue(columna);
}

void ui_andamio_datos::on_pushButton_cancelar_clicked()
{
    close();
}

void ui_andamio_datos::on_pushButton_aceptar_clicked()
{
    QString nombre = ui->lineEdit_nombre->text();
    QString descripcion = ui->lineEdit_descripcion->text();
    QString fila = ui->spinBox_fila->text();
    QString columna = ui->spinBox_columna->text();

    if(fila.compare("0")==0 || columna.compare("0")==0)
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Información");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
        msgBox->setText("Ningún Andamio puede contener alguna dimensión de valor cero!");
        msgBox->exec();
    }
    else
    {
        andamio *andamio_data;

        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setWindowTitle("Resultado");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setButtonText(QMessageBox::Ok,"Aceptar");

        switch(behavior)
        {
            case 0:

                andamio_data = new andamio(0,get_idAlmacen(),nombre,descripcion,fila,columna);
                andamio_data->agregar();

                msgBox->setText("Andamio creado correctamente.");

                break;

            case 1:

                QString idAndamio = ui_almacen_parent->get_currentIdAndamio();
                andamio_data = new andamio(idAndamio,idAlmacen,nombre,descripcion,fila,columna);
                andamio_data->actualizar();

                msgBox->setText("Datos actualizados correctamente.");

                break;
        }

        close();
        ui_almacen_parent->update_comboBox_Andamio(idAlmacen);

        msgBox->exec();
    }
}
