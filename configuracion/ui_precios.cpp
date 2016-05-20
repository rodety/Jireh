#include "ui_precios.h"
#include "ui_ui_precios.h"
#include <share_include.h>

ui_precios::ui_precios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_precios)
{
    ui->setupUi(this);
}

ui_precios::~ui_precios()
{
    delete ui;
}

void ui_precios::on_pushButton_descuentoGeneral_clicked()
{
    actualizar_descuento();

}
bool ui_precios::actualizar_descuento(){

    QSqlQuery query, query1;
    query.prepare("SELECT idProducto,precioVenta FROM Producto");
    double precio,descuento,porcentaje;
    porcentaje = 1+(ui->lineEdit_porcentaje_general->text().toDouble(0)/100);
    if (!query.exec())
    {

        ui->label_mensaje->setText("Error en la consulta SQL");
    }
    else{
        ui->label_mensaje->setText("Termino consulto");

    }
    while(query.next())
    {
        query1.prepare("UPDATE Producto SET precioDescuento = ? WHERE idProducto = ?");
        query1.bindValue(0,query.value(0).toString());
        precio = query.value(1).toDouble();
        descuento = (precio * porcentaje)-precio;
        query1.bindValue(1,descuento);
        if(!query1.exec())
        {
            ui->label_mensaje->setText("fallo al actualizar precio");
        }
        else{
            ui->label_mensaje->setText("id "+query.value(0).toString()+" "+descuento);
        }

    }

    ui->label_mensaje->setText("Termino Satisfactoriamente ...");




}
