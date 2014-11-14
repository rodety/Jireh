#include "ui_busca_producto.h"
#include "ui_ui_busca_producto.h"

ui_busca_producto::ui_busca_producto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_busca_producto)
{
    ui->setupUi(this);
}

ui_busca_producto::~ui_busca_producto()
{
    delete ui;
}

void ui_busca_producto::on_tabWidget_currentChanged(int index)
{
    if(index == 0)
    {
        ui_producto* form=new ui_producto;
        form->setComportamiento(2);
        form->setWindowTitle("Productos");
        form->show();
        //connect(form,SIGNAL(sentProductoVenta(QString,QString,QString,QString,int,QString,int)),this,SLOT(recojeProducto(QString,QString,QString,QString,int,QString,int)));
        //connect(form,SIGNAL(sentProductoVenta(QString,QString,QString,QString,int,QString,int)),form,SLOT(close()));

        ui->tabWidget->setCurrentWidget(form);
    }
}
