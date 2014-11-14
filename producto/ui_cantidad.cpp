#include "ui_cantidad.h"
#include "ui_ui_cantidad.h"

ui_cantidad::ui_cantidad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_cantidad)
{
    ui->setupUi(this);
}

ui_cantidad::~ui_cantidad()
{
    delete ui;
}

void ui_cantidad::on_pushButton_aceptar_clicked()
{
    emit enviarCantidad(codigo,descripcion,ui->spinBox_cantidad->value(),ui->doubleSpinBox_costo->value());
    this->close();
}

void ui_cantidad::setDatos(QString codigo, QString descripcion)
{
    this->codigo = codigo;
    this->descripcion = descripcion;
}


