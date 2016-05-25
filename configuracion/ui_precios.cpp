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
        qDebug()<<"Error en la consulta SQL"<<endl;
    }
    else{
        ui->label_mensaje->setText("Termino consulto");
        qDebug()<<"Termino consulto"<<endl;

    }
    while(query.next())
    {
        query1.prepare("UPDATE Producto SET precioDescuento = ? WHERE idProducto = ?");
        query1.bindValue(0,query.value(0).toString());
        precio = query.value(1).toDouble();
        descuento = (precio * porcentaje)-precio;
        query1.bindValue(1,QString::number(descuento));
        if(!query1.exec())
        {
            ui->label_mensaje->setText("fallo al actualizar precio");
            qDebug()<<"fallo al actualizar precio"<<endl;
        }
        else{
            ui->label_mensaje->setText("id "+query.value(0).toString()+" "+descuento);
            qDebug()<<"id "+query.value(0).toString()+" "+QString::number(descuento)<<endl;
        }

    }

    ui->label_mensaje->setText("Termino Satisfactoriamente ...");
    qDebug()<<"Termino Satisfactoriamente ..."<<endl;




}
