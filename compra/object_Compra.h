#ifndef OBJECT_COMPRA_H
#define OBJECT_COMPRA_H

#include "share_include.h"
#include <compra/object_Producto_has_Compra.h>

#include <QVector>
#define TABLE_NAME_COMPRA "Compra"
class object_Compra:public object_general
{

private:
    _QSTR md_o_idCompra;
    _QSTR md_o_fecha;
    _QSTR md_o_montoTotal;
    _QSTR md_o_anulado;
    _QSTR md_o_tipo;
    _QSTR md_o_serie;
    _QSTR md_o_numero;
    _QSTR md_o_lastId;

public:
    object_Compra();
    object_Compra(_QSTR idCompra, _QSTR fecha, _QSTR montoTotal, _QSTR anulado, _QSTR tipo, _QSTR serie, _QSTR numero);
    object_Compra(_QSTR fecha, _QSTR montoTotal, _QSTR anulado, _QSTR tipo, _QSTR serie, _QSTR numero);

    void mf_set_idCompra(_QSTR idCompra);
    void mf_set_fecha(_QSTR fecha);
    void mf_set_montoTotal(_QSTR montoTotal);
    void mf_set_anulado(_QSTR anulado);
    void mf_set_tipo(_QSTR tipo);
    void mf_set_serie(_QSTR serie);
    void mf_set_numero(_QSTR numero);

    _QSTR mf_get_idCompra();
    _QSTR mf_get_fecha();
    _QSTR mf_get_montoTotal();
    _QSTR mf_get_anulado();
    _QSTR mf_get_tipo();
    _QSTR mf_get_serie();
    _QSTR mf_get_numero();
    _QSTR mf_get_lastId();

    bool mf_load(_QSTR pk);
    bool mf_add();
    bool mf_update();
    bool mf_remove();
    static QSqlQueryModel* mostrar();
    static QSqlQueryModel* mostrarByProduct(_QSTR idProducto);
    QVector<object_Producto_has_Compra>  mf_get_listProducto_has_Compra();

    ~object_Compra();
};
#endif // OBJECT_COMPRA_H
    /*
    object_Compra obj_Compra;
    obj_Compra.mf_set_idCompra();
    obj_Compra.mf_set_fecha();
    obj_Compra.mf_set_montoTotal();
    obj_Compra.mf_set_anulado();
    obj_Compra.mf_set_tipo();
    obj_Compra.mf_set_serie();
    obj_Compra.mf_set_numero();

    obj_Compra.mf_get_idCompra();
    obj_Compra.mf_get_fecha();
    obj_Compra.mf_get_montoTotal();
    obj_Compra.mf_get_anulado();
    obj_Compra.mf_get_tipo();
    obj_Compra.mf_get_serie();
    obj_Compra.mf_get_numero();
    */

