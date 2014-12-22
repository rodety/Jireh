#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    modulos.push_back(ui->actionProducto);
    modulos.push_back(ui->actionUsuario);
    modulos.push_back(ui->actionCliente);
    modulos.push_back(ui->actionVitrina);
    modulos.push_back(ui->actionAlmacen);
    modulos.push_back(ui->actionCompras);
    modulos.push_back(ui->actionReportes);
    modulos.push_back(ui->actionVentas);
    modulos.push_back(ui->actionConfiguracion);
    modulos.push_back(ui->actionAgenda);

    for(size_t i = 0; i<modulos.size();i++)
        modulos[i]->setEnabled(false);
    aplicarPermisos();

}

void MainWindow::aplicarPermisos()
{
    Sesion * s = Sesion::getSesion();
    std::map<int,bool> v ;

    v = s->get_Permisos();

    std::map<int,bool>::iterator it = v.begin();
    if(!v.size())
    {
        QMessageBox::warning(0,"Error de Permisos","No se definieron permisos para este usuario",0,0);
        return;
    }

    for(;it!=v.end();it++)
        modulos[(*it).first-1]->setEnabled((*it).second);
}

void MainWindow::close()
{
    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionProducto_triggered()
{
    bool control = true;
    foreach(QWidget *widget, QApplication::topLevelWidgets()) {

       qDebug()<<widget->objectName()<<endl;
      if(widget->objectName() == "formProducto")
      {
          setCentralWidget(widget);
          control = false;
          qDebug()<<"Ya fue creado producto"<<endl;
      }
    }
    if(control)
    {
        ui_producto* formProducto;

        formProducto=new ui_producto;
        formProducto->setComportamiento(0);
        setCentralWidget(formProducto);
        qDebug()<<"creado producto"<<endl;
    }

}

void MainWindow::on_actionUsuario_triggered()
{
    bool control = true;
    foreach(QWidget *widget, QApplication::topLevelWidgets()) {
      if(widget->objectName() == "formUsuarios")
      {
          setCentralWidget(widget);
          control = false;
          qDebug()<<"Ya fue creado Usuario FOrm"<<endl;
      }
    }
    if(control)
    {
        UsuariosForm* formUsuarios;

        formUsuarios= new UsuariosForm;
        setCentralWidget(formUsuarios);
        qDebug()<<"creado Usuario FOrm"<<endl;
    }


}

void MainWindow::on_actionCliente_triggered()
{
    bool control = true;
    foreach(QWidget *widget, QApplication::topLevelWidgets()) {
      if(widget->objectName() == "ui_cliente")
      {
          setCentralWidget(widget);
          control = false;
          qDebug()<<"Ya fue creado ui_cliente"<<endl;
      }
    }
    if(control)
    {
        ui_cliente* formCliente;

        formCliente=new ui_cliente;
        formCliente->setComportamiento(0);
        setCentralWidget(formCliente);
        qDebug()<<"creado ui_cliente"<<endl;
    }



}

void MainWindow::on_actionVitrina_triggered()
{

    bool control = true;
    foreach(QWidget *widget, QApplication::topLevelWidgets()) {
      if(widget->objectName() == "ui_tienda")
      {
          setCentralWidget(widget);
          control = false;
          qDebug()<<"Ya fue creado ui_tienda"<<endl;
      }
    }
    if(control)
    {
        ui_tienda* formTienda;
        formTienda = new ui_tienda;
        setCentralWidget(formTienda);
        qDebug()<<"creado ui_tienda"<<endl;
    }

}

void MainWindow::on_actionAlmacen_triggered()
{
    bool control = true;
    foreach(QWidget *widget, QApplication::topLevelWidgets()) {
      if(widget->objectName() == "ui_almacen")
      {
          setCentralWidget(widget);
          control = false;
          qDebug()<<"Ya fue creado ui_almacen"<<endl;
      }
    }
    if(control)
    {

        ui_almacen* formAlmacen;

        formAlmacen = new ui_almacen;
        setCentralWidget(formAlmacen);
        qDebug()<<"creado ui_tienda"<<endl;
    }

}

void MainWindow::on_actionConfiguracion_triggered()
{
    ui_configuracion *formConfiguracion;

    formConfiguracion = new ui_configuracion;
    setCentralWidget(formConfiguracion);
    connect(formConfiguracion,SIGNAL(closeparent()),this,SLOT(close()));
}

void MainWindow::on_actionVentas_triggered()
{
    bool control = true;
    foreach(QWidget *widget, QApplication::topLevelWidgets()) {
      if(widget->objectName() == "uiventas")
      {
          setCentralWidget(widget);
          control = false;
          qDebug()<<"Ya fue creado uiventas"<<endl;
      }
    }
    if(control)
    {
        uiventas * formVentas;

        formVentas = new uiventas;
        setCentralWidget(formVentas);
        qDebug()<<"creado ui_tienda"<<endl;
    }


}

void MainWindow::on_actionReportes_triggered()
{
    bool control = true;
    foreach(QWidget *widget, QApplication::topLevelWidgets()) {
      if(widget->objectName() == "ui_reporte")
      {
          setCentralWidget(widget);
          control = false;
          qDebug()<<"Ya fue creado ui_reporte"<<endl;
      }
    }
    if(control)
    {
        ui_reporte* formReporte;

        formReporte = new ui_reporte;
        setCentralWidget(formReporte);
        qDebug()<<"creado ui_reporte"<<endl;
    }



}

void MainWindow::on_actionCompras_triggered()
{
    bool control = true;
    foreach(QWidget *widget, QApplication::topLevelWidgets()) {
      if(widget->objectName() == "compras")
      {
          setCentralWidget(widget);
          control = false;
          qDebug()<<"Ya fue creado compras"<<endl;
      }
    }
    if(control)
    {
        compras* formCompras;
        formCompras = new compras;
        setCentralWidget(formCompras);
        qDebug()<<"creado ui_reporte"<<endl;
    }


}

void MainWindow::on_actionAgenda_triggered()
{
    bool control = true;
    foreach(QWidget *widget, QApplication::topLevelWidgets()) {
      if(widget->objectName() == "agenda_ui")
      {
          setCentralWidget(widget);
          control = false;
          qDebug()<<"Ya fue creado agenda_ui"<<endl;
      }
    }
    if(control)
    {

        agenda_ui* formAgenda;
        formAgenda = new agenda_ui;
        setCentralWidget(formAgenda);
        qDebug()<<"creado ui_reporte"<<endl;
    }


}
