#ifndef UI_PRODUCTO_H
#define UI_PRODUCTO_H

#include <QWidget>
#include <producto/ui_agregarluna.h>
#include <producto/ui_agregarmontura.h>
#include <producto/ui_agregarlente.h>
#include <producto/ui_agregarotros.h>
#include <producto/object_Accesorios.h>
#include <producto/ui_agregaraccesorios.h>
#include <producto/object_LenteContacto.h>
#include <producto/object_Luna.h>
#include <producto/object_Montura.h>
#include <producto/object_Otros.h>
#include <producto/object_Producto.h>
#include <producto/ui_ubicacion.h>
#include <producto/accesorios.h>
#include <compra/object_Compra.h>
#include <compra/compras.h>
#include <compra/object_Compra_has_Proveedor.h>
#include <producto/object_Kardex.h>
#include <extras/ui_trabajosextras.h>
#include <vitrina/ui_tienda.h>
#include <producto/tipoluna.h>
#include <producto/object_Laboratorio.h>
#include <producto/object_Lista.h>
#include <producto/ui_cantidad.h>
//#include <producto/estado.h>
#include <extras/etiqueta.h>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextEdit>
#include <QPoint>

namespace Ui {
class ui_producto;
}

class ui_producto : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_producto(QWidget *parent = 0);
    ~ui_producto();
    void set_index_combo_producto(int index);    
    void configurarVenta(int index);
    void imprimir_tablas(QString filename, QTableView * t);




private slots:

    void configurarCombos(int index);
    void on_comboBox_tipoProducto_currentIndexChanged(int index);
    void on_pushButton_agregar_2_clicked();
    void on_pushButton_editar_clicked();
    void on_pushButton_eliminar_clicked();

    void agregar_etiqueta(const QModelIndex & model);
    void eliminar_etiqueta(const QModelIndex & model);
    void enviar_productoCompra(const QModelIndex & model);
    void enviar_venta(const QModelIndex & model, int cant,QString pos, int tipo);
    void on_pushButton_previsualizar_clicked();
    void on_pushButton_imprimir_clicked();
    void on_pushButton_anterior_clicked();
    void on_pushButton_siguiente_clicked();
    void on_tabWidget_currentChanged(int index);

    void on_btnToVitrina_clicked();
    void on_btnToAlmacen_clicked();

    void on_comboBox_select_1_currentIndexChanged(int index);

    void on_comboBox_select_2_currentIndexChanged(int index);

    void on_comboBox_select_3_currentIndexChanged(int index);

    void on_comboBox_select_4_currentIndexChanged(int index);

    void on_comboBox_select_5_currentIndexChanged(int index);

    void on_comboBox_select_6_currentIndexChanged(int index);

    void on_doubleSpinBox_Cilindro_editingFinished();

private:
    Ui::ui_producto *ui;
    int posicion;

    QList<etiqueta> etiquetas;
    int act;
    int pag;
    int comportamiento;
    QString idcodigo;
    bool flagConsultar;
    bool verificarstock(int index);
    int max_numero_mover;
    QModelIndex current_index;
    QString id_Producto_has_Vitrina;
    QString id_Contenedor_has_Producto;
    bool transponer;
    double vesfera;
    double vcilindro;
    int cantidad;
    double precio;
    void configurarui(int index);
private slots:
    void seleccionar();
    void actualizarTrabajosExtras();
    void on_doubleSpinBox_Inicio_editingFinished();
    bool verificaciones_para_mover();

    void on_tableView_productos_clicked(const QModelIndex &index);

    void on_pushButton_buscar_clicked();

    void on_lineEdit_buscar_returnPressed();

    void on_tableView_productos_doubleClicked(const QModelIndex &index);

    void on_pushButton_etiquetar_clicked();

    void on_tableView_vitrina_doubleClicked(const QModelIndex &index);

    void on_tableView_almacen_doubleClicked(const QModelIndex &index);

    void on_pushButton_transponer_clicked();

    void on_tableView_compras_doubleClicked(const QModelIndex &index);

    void on_pushButton_imprimir_2_clicked();

    void on_pushButton_imprimir_kardex_clicked();

    void on_pushButton_imprimir_lc_clicked();

public slots:
    void setComportamiento(int);
    void actualizarListaProductos();
    void recogerCantidad(QString,QString,int,double);

signals:
    void sentProductoCompra(QString,QString,QString,int);//codigo,descripcion,precioCompra,cantidad
    //codigo,descripcion,precioVenta,Descuento,cant,IdUbicacion,tipo de Producto,Stock del Producto,Precio Compra por lo del Kardex
    void sentProductoVenta(QString,QString,QString,QString,int,QString,int,int,QString);


};

#endif // UI_PRODUCTO_H
