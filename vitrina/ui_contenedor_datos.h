#ifndef UI_CONTENEDOR_DATOS_H
#define UI_CONTENEDOR_DATOS_H

#include <QWidget>
#include "ui_almacen.h"
#include "configuracion/sesion.h"
#include <QInputDialog>

namespace Ui {
class ui_contenedor_datos;
}

class ui_contenedor_datos : public QWidget
{
    Q_OBJECT
private:

    QString idContenedor;
    ui_almacen* ui_almacen_parent;
    int behavior;
    int cantidadProducto;
    bool toAlmacen;
    QModelIndex indice;
    int max_numero_mover;
    QString idProducto;
    int fila;
    int columna;


public:

    QString get_idContenedor();
    void set_idContenedor(QString);

    ui_almacen* get_ui_almacen_parent();
    void set_ui_almacen_parent(ui_almacen*);

    int get_behavior();
    void set_behavior(int);

    void setToAlmacen(bool tmp)                 { toAlmacen=tmp;}
    void setCantidadProducto(int tmp)           { cantidadProducto=tmp;}

    void set_idProducto(QString);
    bool add_Product();
    bool insert_Product();
    void set_fila(int);
    void set_columna(int);
    void clear_widget_list_productos();
    void update_table_list_productos();
    void update_form();
    void show_controls_product(bool);




public:
    explicit ui_contenedor_datos(QWidget *parent = 0);
    ~ui_contenedor_datos();

private slots:
    void on_pushButton_salir_clicked();

    bool on_pushButton_addProducto_clicked();

    void on_pushButton_saveContenedor_clicked();

    void on_pushButton_deleteContenedor_clicked();

    void on_pushButton_deleteProducto_clicked();

    void on_traspaso_clicked();

    void on_tableView_datos_clicked(const QModelIndex &index);

    void on_traspaso_Almacen_clicked();

    void traspaso_vitrina();

    void traspaso_contenedor(int cant);

    void on_lineEdit_codigoProducto_cursorPositionChanged(int arg1, int arg2);    

    void on_tableView_datos_doubleClicked(const QModelIndex &index);

private:
    Ui::ui_contenedor_datos *ui;
    void actualizar_productos_cant(int cantidad, QString idProducto);    
    /**
     * @brief flag Control de comportamiento al momento de hacer un traspaso a otro contendor
     */
    bool flag;
};

#endif // UI_CONTENEDOR_DATOS_H
