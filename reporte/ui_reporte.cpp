#include "ui_reporte.h"
#include "ui_ui_reporte.h"

ui_reporte::ui_reporte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_reporte)
{
    ui->setupUi(this);
    seleccionados_model = new QStandardItemModel(this);
    ui->listView_entidad->setModel(seleccionados_model);
}

ui_reporte::~ui_reporte()
{
    //hola
    delete ui;
}




void execute();

/*void ui_reporte::on_pushButton_calcular_clicked()
{

}
*/

void ui_reporte::on_comboBox_currentIndexChanged(int index)
{


}

void ui_reporte::on_listView_entidad_clicked(const QModelIndex &index)
{
    int row = index.row();
    if(ui->comboBox_entidades->currentIndex() == 1){

    }

}

void ui_reporte::on_comboBox_entidades_currentIndexChanged(int index)
{
    int count_row =0;
    if(index == 0){
        seleccionados_model->clear();
    }
    if(index == 1){

        seleccionados_model->clear();
        seleccionados_model->setItem(count_row++,0,new QStandardItem("Luna"));
        seleccionados_model->setItem(count_row++,0,new QStandardItem("Montura"));
        seleccionados_model->setItem(count_row++,0,new QStandardItem("Lentes de Contacto"));
        seleccionados_model->setItem(count_row++,0,new QStandardItem("Otros"));
        seleccionados_model->setItem(count_row++,0,new QStandardItem("Accesorios"));
    }
    if(index == 2){
        object_Tienda tienda;
        QSqlQueryModel* model = tienda.mf_show_all();
        seleccionados_model->clear();
        for(int i=0;i<model->rowCount();i++)
        {
            seleccionados_model->setItem(i,0,new QStandardItem(model->record(i).value(1).toString()));
            Tienda[model->record(i).value(1).toString()] = model->record(i).value(0).toString();
        }
    }
    if(index == 3){
        object_Colaborador colaborador;
        QSqlQueryModel* model = colaborador.mf_show();
        seleccionados_model->clear();
        for(int i=0;i<model->rowCount();i++)
        {
            seleccionados_model->setItem(i,0,new QStandardItem(model->record(i).value(1).toString()));
            Colaborador[model->record(i).value(1).toString()] = model->record(i).value(0).toString();
        }
    }
    if(index == 4){
        object_Cliente cliente;
        QSqlQueryModel* model = cliente.mf_show_all();
        seleccionados_model->clear();
        for(int i=0;i<model->rowCount();i++)
        {
            seleccionados_model->setItem(i,0,new QStandardItem(model->record(i).value(1).toString()));
            Cliente[model->record(i).value(1).toString()] = model->record(i).value(0).toString();
        }
    }
}

void ui_reporte::on_listView_entidad_doubleClicked(const QModelIndex &index)
{
    int index_entidades = ui->comboBox_entidades->currentIndex();
    QString id;
    if(index_entidades == 0){

    }

    if(index_entidades == 1){
        if(index.row() == 0){
            ui->tableView_principal->setModel(get_reporte_producto(1));
        }
        if(index.row() == 1){
            ui->tableView_principal->setModel(get_reporte_producto(2));
        }

    }
    if(index_entidades == 2){

    }
    if(index_entidades == 3){

    }
    if(index_entidades == 4){

    }
}

QSqlQueryModel *ui_reporte::get_reporte_producto(int tipo)
{
    //Consultas puras INNER JOIN
    QSqlQueryModel* model=new QSqlQueryModel;
    if(tipo == 1){
        model->setQuery("select Luna.Producto_idProducto as 'id' ,Luna.valorInicial,Luna.valorFinal,Tratamiento.nombre as 'Tratamiento',CalidadLuna.nombre as 'Calidad', TipoLuna.nombre as 'Tipo' ,SUM(Venta_has_Producto.precio) as 'Total' from Luna INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Tratamiento INNER JOIN CalidadLuna INNER JOIN TipoLuna WHERE Luna.Producto_idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND Tratamiento.idTratamiento = Luna.Tratamiento_idTratamiento AND CalidadLuna.idCalidadLuna = Luna.CalidadLuna_idCalidadLuna AND TipoLuna.idTipoLuna = Luna.TipoLuna_idTipoLuna GROUP BY Luna.Producto_idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    }
    if(tipo == 2){
        model->setQuery("select Montura.Producto_idProducto as 'id' ,Forma.nombre as 'Forma', Color.nombre as 'Color', Tamanio.nombre as 'Tamanio', Calidad.nombre as 'Calidad',SUM(Venta_has_Producto.precio) as 'Total' from Montura INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Forma INNER JOIN Color INNER JOIN Tamanio INNER JOIN Calidad WHERE Montura.Producto_idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND Forma.idForma = Montura.Forma_idForma AND Color.idColor = Montura.Color_idColor AND Tamanio.idTamanio = Montura.Tamanio_idTamanio AND Calidad.idCalidad = Montura.Calidad_idCalidad GROUP BY Montura.Producto_idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    }
    return model;

}
