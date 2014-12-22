#ifndef UI_TIENDA_H
#define UI_TIENDA_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QSqlQuery>
#include <vitrina/tienda.h>
#include <map>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <QMessageBox>
#include "ui_almacen.h"
#include <vitrina/ui_agregar_empresa.h>
#include <vitrina/ui_tienda_agregar.h>
#include <configuracion/sesion.h>
#include <vitrina/tienda.h>
#include <producto/object_Tratamiento.h>
#include <producto/object_Calidad.h>
#include <producto/object_Color.h>
#include <producto/object_Marca.h>
#include <producto/object_TiempoUso.h>
#include <producto/object_TipoLente.h>
#include <producto/object_TipoOtros.h>
#include <producto/object_Accesorios_n.h>
class ui_tienda_agregar;

class ui_agregar_empresa;
using namespace std;

enum lbls {Empresa,Tienda,Vitrina};

namespace Ui {
class ui_tienda;
}

class  ui_tienda : public QWidget
{
    Q_OBJECT
private:
    QSqlQuery sqlQuery;

    QString idTraspaso;
    QString idEmpresa;
    QString idTienda;
    QString idVitrina;
    QString idItem;
    QString idItem_tras;
    QString idProducto_tras;
    ui_tienda * ui_tienda_traspaso;
    ui_almacen * ui_almacen_traspaso;
    int actual_nivel;
    int row_traspaso;
    bool caso;
    bool caso_traspaso;
    bool toVitrina;  //de producto hasta vitrina
    ui_agregar_empresa* add_empresa;

    lbls actual;     // puntero para los botones agregar,editar....
    map<QString,QString> Empresas;
    map<QString,QString> Tiendas;
    map<QString,QString> Vitrinas;
    map<QString,QString> idProductos;
    map<QString,QString> idVitrina_Producto;
    map<QString,QString> estado;
    map<QString,QString> comentario;
    map<QString,QString> cod_producto;
    ui_tienda_agregar* tienda_agregar;
    QModelIndex indice;
    int item;
    int comportamiento;
    int movimiento;
    QString idVitrina_Producto_old;



public:

    void changeActual(lbls num);

    QString get_idEmpresa()                 {return idEmpresa;}
    QString get_idTienda()                  {return idTienda;}
    QString get_idVitrina()                 {return idVitrina;}
    QString get_idItem()                    {return idItem;}
    QString get_idItem_tras()               {return idItem_tras;}
    QString get_idProducto_tras()           {return idProducto_tras;}
    int get_actual_nivel()                  {return actual_nivel;}
    int get_row_traspaso()                  {return row_traspaso;}
    bool get_caso()                         {return caso;}
    bool get_caso_traspaso()                {return caso_traspaso;}
    ui_tienda* get_ui_tienda_traspaso()     {return ui_tienda_traspaso;}

    void set_ui_tienda_traspaso(ui_tienda* tmp)     { ui_tienda_traspaso=tmp; }

    ui_almacen* get_ui_almacen_traspaso()           { return ui_almacen_traspaso; }

    void set_ui_almacen_traspaso(ui_almacen* tmp)   { ui_almacen_traspaso=tmp; }

    void set_idEmpresa(QString tmp)         {idEmpresa=tmp;}
    void set_idTienda(QString tmp)          {idTienda=tmp;}
    void set_idVitrina(QString tmp)         {idVitrina=tmp;}
    void set_idItem(QString tmp)            {idItem=tmp;}
    void set_idItem_tras(QString tmp)       {idItem_tras=tmp;}
    void set_idProducto_tras(QString tmp)   {idProducto_tras=tmp;}
    void set_caso(bool tmp)                 {caso=tmp;}
    void set_caso_traspaso(bool tmp)        {caso_traspaso=tmp;}
    void set_actual_nivel(int tmp)          {actual_nivel=tmp;}
    void set_row_traspaso(int tmp)          {row_traspaso=tmp;}
    void set_query(QSqlQuery q)             {sqlQuery=q;}
    void set_traspaso(bool tmp)             {toVitrina=tmp;}
    void set_idTraspaso(QString tmp)        {idTraspaso=tmp;}
    void set_item(int tmp)                  {tmp = item;}
    void enableButtonAceptar();
    void actualizar_combo_vitrina(QString);
    void actualizar_combo_niveles(QString);
    void limpiar_grilla();
    void set_dimension_grilla();
    void actualizar_grilla();
    void habilitar_botones();

    void agregarTienda(bool b);         //true para agregar .....................false para editar
    void deshabilitarTienda();
    void agregarVitrina(bool b);
    void deshabilitarVitrina();
    void agregarEmpresa(bool b);
    void deshabilitarEmpresa();

    void on_btn_traspaso() { on_pushButton_traspaso_clicked();}
    bool actualizar_cantidad_vitrina(int cant, QString id);
    bool actualizar_cantidad_almacen(int cant, QString id);
    void setComportamiento(int tem);
    void setMovimiento(int mov);
    int getMovimiento();
    void configurarVenta();
    void configurarPermisos();


public:
    ui_tienda(QWidget *parent = 0);
    ui_tienda(QWidget *, int a);
    ~ui_tienda();
    
private slots:

    void on_comboBox_empresa_currentIndexChanged(const QString &arg1);

    void on_comboBox_tienda_currentIndexChanged(const QString &arg1);

    void on_comboBox_vitrina_currentIndexChanged(const QString &arg1);

    void on_comboBox_niveles_currentIndexChanged(int index);

    void on_grilla_cellDoubleClicked(int row, int column);

    void on_grilla_itemSelectionChanged();

    void on_pushButton_traspaso_clicked();

    void on_pushButton_aceptar_traspaso_clicked();

    void on_button_traspaso_almacen_clicked();

    void on_comboBox_vitrina_activated(int index);

    void on_comboBox_empresa_activated(const QString &arg1);

    void on_comboBox_tienda_activated(const QString &arg1);

    void on_lineEdit_estado_returnPressed();

    void on_grilla_clicked(const QModelIndex &index);

    void on_pushButton_quitar_clicked();

    void on_grilla_doubleClicked(const QModelIndex &index);

    void on_btnAgregar_empresa_clicked();

    void on_btnEditar_empresa_clicked();

    void on_btnDeshabilitar_empresa_clicked();

    void on_btnAgregar_tienda_clicked();

    void on_btnEditar_tienda_clicked();

    void on_btnDeshabilitar_tienda_clicked();

    void on_btnAgregar_vitrina_clicked();

    void on_btnEditar_vitrina_clicked();

    void on_btnDeshabilitar_vitrina_clicked();

    void on_btnImprimir_clicked();

    void on_pushButton_reponer_clicked();

   // void on_pushButton_print_clicked();

public slots:
    void actualizar_combo_empresa();
    void actualizar_combo_tienda(QString idEmpresa);
    void actualizar_grilla_productos();
    void remove_producto();
signals:
    void actualizar_lista_productos();

    //codigo,descripcion,precioVenta,Descuento,cant,IdUbicacion,tipo de Producto,Stock del Producto,Precio Compra por lo del Kardex
    void sentProductoVenta(QString codigo,QString descripcion,QString p_venta,QString p_desc,int cant,QString idUbicacion,int tipo_produc,int stock ,QString p_compra);

private:
    Ui::ui_tienda *ui;
    bool flag; //Control de actualizacion de Lista de tiendas
};

#endif // UI_TIENDA_H

