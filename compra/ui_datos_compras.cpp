#include "ui_datos_compras.h"
#include "ui_ui_datos_compras.h"

ui_datos_compras::ui_datos_compras(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_datos_compras)
{
    ui->setupUi(this);
    count_row = 0;
}

ui_datos_compras::~ui_datos_compras()
{
    delete ui;
}

void ui_datos_compras::on_pushButton_4_clicked()
{
    close();
}
void ui_datos_compras::setdataproveedor(QDate fecha,QString proveedor, QString ruc, QString direccion, QString total)
{
    ui->dateEdit->setDate(fecha);
    ui->lineEdit_proveedor->setText(proveedor);
    ui->lineEdit_ruc->setText(ruc);
    ui->lineEdit_direccion->setText(direccion);
    ui->lineEdit_total->setText(total);
}
void ui_datos_compras::additemproducto(QString codigo,QString descripcion, QString accesorios, QString precio, QString cantidad, QString total)
{
    ui->tableWidget->insertRow(count_row);

    ui->tableWidget->setItem(count_row,0,new QTableWidgetItem(codigo));
    ui->tableWidget->setItem(count_row,1,new QTableWidgetItem(descripcion));
    ui->tableWidget->setItem(count_row,2,new QTableWidgetItem(accesorios));
    ui->tableWidget->setItem(count_row,3,new QTableWidgetItem(precio));
    ui->tableWidget->setItem(count_row,4,new QTableWidgetItem(cantidad));
    ui->tableWidget->setItem(count_row,5,new QTableWidgetItem(total));
    count_row++;

}
