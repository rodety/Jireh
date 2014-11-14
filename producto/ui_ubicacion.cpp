#include "ui_ubicacion.h"
#include "ui_ui_ubicacion.h"

ui_ubicacion::ui_ubicacion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_ubicacion)
{
    ui->setupUi(this);
}

ui_ubicacion::~ui_ubicacion()
{
    delete ui;
}

void ui_ubicacion::loadData(QString idProducto)
{
    object_Producto_has_Vitrina producto_vitrina;
    object_Contenedor_has_Producto producto_contenedor;
    producto_vitrina.mf_set_Producto_idProducto(idProducto);
    producto_contenedor.mf_set_Producto_idProducto(idProducto);
    ui->tableView_vitrina->setModel(producto_vitrina.mf_show());
    ui->tableView_almacen->setModel(producto_contenedor.mf_show_ubication());

}
