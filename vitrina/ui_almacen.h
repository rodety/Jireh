#ifndef UI_ALMACEN_H
#define UI_ALMACEN_H

#include <QWidget>
#include <QTableWidgetItem>
#include <map>
#include <QSqlQuery>
#include <QSqlError>
#include <producto/montura.h>
#include <producto/object_Contenedor_has_Producto.h>
#include <iostream>
using namespace std;

namespace Ui {
class ui_almacen;
}

class ui_almacen : public QWidget
{
    Q_OBJECT

private:
    QSqlQuery sqlQuery;
    bool fromVitrina;

    bool toAlmacen;
    int cantidadProducto;
    int comportamiento;

    QString currentIdEmpresa;
    QString currentIdTienda;
    QString currentIdAlmacen;
    QString currentIdAndamio;
    QString currentIdContenedor;

    QString currentCod;

    //key = name, map = id_entity;
    map<QString,QString> Empresas;
    map<QString,QString> Tiendas;
    map<QString,QString> Almacenes;
    map<QString,QString> Andamios;
    map<QString,QString> Contenedor;
    QModelIndex indice;
    bool actualizar_cantidad_vitrina(int cant, QString id);
    bool actualizar_cantidad_almacen(int cant, QString id);


public:
    QString get_currentIdEmpresa();
    QString get_currentIdTienda();
    QString get_currentIdAlmacen();
    QString get_currentIdAndamio();
    QString get_currentIdContenedor();
    int get_comportamiento();

    void setFromVitrina(bool b);
    void setToAlmacen(bool b);

    void set_currentIdEmpresa(QString);
    void set_currentIdTienda(QString);
    void set_currentIdAlmacen(QString);
    void set_currentIdAndamio(QString);
    void set_currentIdContenedor(QString);
    void set_currentCode(QString);
    void set_cantidad(int tmp)               { cantidadProducto=tmp;}
    void set_query(QSqlQuery query);
    void set_comportamiento(int com);

    void update_comboBox_Empresa();
    void update_comboBox_Tienda(QString idEmpresa);
    void update_comboBox_Almacen(QString idTienda);
    void update_comboBox_Andamio(QString idAlmacen);

    void clear_widget_Contenedores();
    void set_dimension_widget_Contenedores();
    void update_widget_Contenedores();
    void sendProducto(QString idProducto,QString descripcion ,QString precio_Venta,QString descuento,int cantidad ,QString idUbicacion,int tipoProducto,int stockProducto,QString precioCompra);
    
public:
    explicit ui_almacen(QWidget *parent = 0);
    ~ui_almacen();
    void enable_push_button_aceptar();
    
private slots:
    void on_comboBox_Empresa_currentIndexChanged(const QString &arg1);

    void on_comboBox_Tienda_currentIndexChanged(const QString &arg1);

    void on_comboBox_Almacen_currentIndexChanged(const QString &arg1);

    void on_comboBox_Andamio_currentIndexChanged(const QString &arg1);

    void on_pushButton_addAlmacen_clicked();

    void on_pushButton_editAlmacen_clicked();

    void on_pushButton_deleteAlmacen_clicked();

    void on_pushButton_addAndamio_clicked();

    void on_pushButton_editAndamio_clicked();

    void on_pushButton_deleteAndamio_clicked();

    void on_tableWidget_griContenedores_cellDoubleClicked(int row, int column);

    void on_tableWidget_griContenedores_itemSelectionChanged();

    void on_botonGenerarReporte_clicked();

    void on_pushButton_aceptar_clicked();

    void on_tableWidget_griContenedores_clicked(const QModelIndex &index);

private:
    Ui::ui_almacen *ui;
public:

signals:
    void actualizar_lista_productos();
    void actualizar_grilla_vitrina();
    void traspaso_almacen(int);    
    //codigo,descripcion,precioVenta,Descuento,cant,IdUbicacion,tipo de Producto,Stock del Producto,Precio Compra por lo del Kardex
    void sendProductoVenta(QString idProducto,QString descripcion ,QString precio_Venta,QString descuento,int cantidad ,QString idUbicacion,int tipoProducto,int stockProducto,QString precioCompra);
};

#endif // UI_ALMACEN_H
