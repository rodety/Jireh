#ifndef UIVENTAS_H
#define UIVENTAS_H

#include <QWidget>
#include <cliente/ui_cliente.h>
#include <producto/ui_producto.h>
#include <vitrina/object_Tienda.h>
#include <configuracion/object_Configuracion.h>
#include <colaborador/object_Colaborador.h>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QPair>
#include <venta/ui_tarjeta.h>
#include <venta/delagate.h>
#include <venta/comboboxdelegate.h>
#include <venta/object_Venta.h>
#include <venta/object_EntregaProducto.h>
#include <venta/object_Venta_has_Producto.h>
#include <venta/object_Venta_has_Tarjeta.h>
#include <venta/ui_tarjeta.h>
#include <mycombobox.h>
#include <QVector>
#include <venta/ui_pagos.h>
#include <venta/object_VentaPlazo.h>
#include <venta/impresora.h>
#include <venta/ui_busca_producto.h>
#include <vitrina/ui_tienda.h>
#include <vitrina/ui_almacen.h>
#include <venta/ui_tarjeta.h>
#include <impresion/impresion.h>
#include <impresion/articulo.h>
#include <venta/qcomboboxitemdelegate.h>
namespace Ui {
class uiventas;
}

class uiventas : public QWidget
{
    Q_OBJECT
    
public:
    explicit uiventas(QWidget *parent = 0);
    ~uiventas();
    void loadVenta(QString id_venta);
public slots:
    void loadListaPagos();
signals:
    void actualizarListaAgenda();

private slots:
    void on_pushButton_buscarCliente_clicked();
    void recojeCliente(cliente);
    void actualizaDatosCliente();
    bool ventaBoleta();
    void recojeProducto(QString,QString,QString,QString,int,QString,int,int,QString);
    void on_lineEdit_efectivo_textChanged(const QString &arg1);
    void on_lineEdit_tarjeta_textChanged(const QString &arg1);

    void on_radioButton_Boleta_clicked();

    void on_radioButton_Factura_clicked();

    void on_radioButton_cotizacion_clicked();

    void on_pushButton_guardar_clicked();    

    void on_tableView_Productos_doubleClicked(const QModelIndex &index);

    void on_dateTimeEdit_Desde_dateTimeChanged(const QDateTime &dateTime);

    void on_comboBox_Empresa_currentIndexChanged(const QString &arg1);

    void on_comboBox_Empresa_currentIndexChanged(int index);

    void on_comboBox_Tienda_currentIndexChanged(int index);

    void on_comboBox_Documento_currentIndexChanged(int index);

    void on_comboBox_Forma_Pago_currentIndexChanged(int index);

    void on_comboBox_Colaborador_currentIndexChanged(int index);

    void on_dateTimeEdit_Desde_editingFinished();

    void on_dateTimeEdit_Hasta_editingFinished();

    void on_tableView_Reporte_Ventas_doubleClicked(const QModelIndex &index);

    void on_pushButton_limpiar_clicked();    

    void on_pushButton_anular_clicked();

    void on_comboBox_buscar_producto_activated(int index);

    void on_tabWidget_currentChanged(int index);

    void on_tableView_pagos_clicked(const QModelIndex &index);

    void on_pushButton_registro_tarjeta_clicked();

    void on_pushButton_compras_clicked();

    void on_tableView_Productos_clicked(const QModelIndex &index);

    void on_doubleSpinBox_descuento_valueChanged(double arg1);

    void on_pushButton_buscar_clicked();

    void on_buscar_venta_returnPressed();

private:
    Ui::uiventas *ui;
    int count_row;
    int fuente; //Fuente de donde provienen los productos
    object_Configuracion configuracion;
    map<int,QString> res;
    double total_venta;
    double m_entregado;
    double sub_total;
    double monto_igv;
    double igv;
    void calculaprecio(double);
    void configuracionesIniciaciales();
    void configuracionReportes();
    void calcularReporte(int tipo);
    void limpiarInterfazVenta();
    void habilitar_editar();
    void habilitar_nuevo();
    QSqlRelationalTableModel* productos_Model;
    void configTableVentas();
    QStandardItemModel * seleccionados_model;
    QString idCliente;
    QString idVentaActual;
    QString montoTarjeta;
    QString numeroDocumento;
    object_Venta_has_Tarjeta v_tarjeta;
    object_Venta update_venta;
    QVector< bool > listo_calcular;

    //DATOS PARA LA CONSULTA
    QString _idTienda;
    QString _idColaborador;
    QString _idDocuemento;
    QString _idFormaPago;
    bool comportamiento;
    double efectivo_pasado;
    double tarjeta_pasado;
    bool actualizar_configuracion();
    bool validar_montoEntregado();
    bool flag_reporte;
    QModelIndex index_pagos;
    object_Tienda tienda_actual;
    void imprimir(bool);
    QComboBoxItemDelegate * delegate1;
    void anularVenta();
    QModelIndex indiceProducto;
    void calcularSubtotal();
    bool validarEntregadoProducto();
    bool validarCancelado();
    void updateSerieNumeroDocumento();
    cliente customer;




};

#endif // UIVENTAS_H
