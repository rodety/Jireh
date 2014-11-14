#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <producto/ui_producto.h>
#include <cliente/ui_cliente.h>
#include <vitrina/ui_tienda.h>
#include <vitrina/ui_almacen.h>
#include <configuracion/usuariosform.h>
#include <configuracion/sesion.h>
#include "configuracion/ui_configuracion.h"
#include <venta/uiventas.h>
#include <reporte/ui_reporte.h>
#include <compra/compras.h>
#include <agenda/agenda_ui.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void aplicarPermisos();
public slots:
    void close();
    
private slots:
    void on_actionProducto_triggered();
    void on_actionUsuario_triggered();
    void on_actionCliente_triggered();
    void on_actionVitrina_triggered();

    void on_actionAlmacen_triggered();

    void on_actionConfiguracion_triggered();

    void on_actionVentas_triggered();

    void on_actionReportes_triggered();

    void on_actionCompras_triggered();

    void on_actionAgenda_triggered();

private:
    Ui::MainWindow *ui;
    std::vector<QAction*> modulos;



};

#endif // MAINWINDOW_H
