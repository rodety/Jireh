#ifndef OBJECT_PRODUCTO_HAS_COMPRA_H
#define OBJECT_PRODUCTO_HAS_COMPRA_H

#include "share_include.h"

#define TABLE_NAME_PRODUCTO_HAS_COMPRA "Producto_has_Compra"
class object_Producto_has_Compra:public object_general
{

private:
    _QSTR md_o_idProducto_has_Compra;
    _QSTR md_o_Producto_idProducto;
    _QSTR md_o_Compra_idCompra;
    _QSTR md_o_cantidad;
    _QSTR md_o_precio;
    _QSTR md_o_descripcion;

public:
    object_Producto_has_Compra();
    object_Producto_has_Compra(_QSTR idProducto_has_Compra, _QSTR Producto_idProducto, _QSTR Compra_idCompra, _QSTR cantidad, _QSTR precio, _QSTR descripcion);
    object_Producto_has_Compra(_QSTR Producto_idProducto, _QSTR Compra_idCompra, _QSTR cantidad, _QSTR precio, _QSTR descripcion);

    void mf_set_idProducto_has_Compra(_QSTR idProducto_has_Compra);
    void mf_set_Producto_idProducto(_QSTR Producto_idProducto);
    void mf_set_Compra_idCompra(_QSTR Compra_idCompra);
    void mf_set_cantidad(_QSTR cantidad);
    void mf_set_precio(_QSTR precio);
    void mf_set_descripcion(_QSTR descripcion);

    _QSTR mf_get_idProducto_has_Compra();
    _QSTR mf_get_Producto_idProducto();
    _QSTR mf_get_Compra_idCompra();
    _QSTR mf_get_cantidad();
    _QSTR mf_get_precio();
    _QSTR mf_get_descripcion();

    bool mf_load(_QSTR pk);
    bool mf_add();
    bool mf_update();
    bool mf_remove();

    ~object_Producto_has_Compra();
};
#endif // OBJECT_PRODUCTO_HAS_COMPRA_H
    /*
    object_Producto_has_Compra obj_Producto_has_Compra;
    obj_Producto_has_Compra.mf_set_idProducto_has_Compra();
    obj_Producto_has_Compra.mf_set_Producto_idProducto();
    obj_Producto_has_Compra.mf_set_Compra_idCompra();
    obj_Producto_has_Compra.mf_set_cantidad();
    obj_Producto_has_Compra.mf_set_precio();
    obj_Producto_has_Compra.mf_set_descripcion();

    obj_Producto_has_Compra.mf_get_idProducto_has_Compra();
    obj_Producto_has_Compra.mf_get_Producto_idProducto();
    obj_Producto_has_Compra.mf_get_Compra_idCompra();
    obj_Producto_has_Compra.mf_get_cantidad();
    obj_Producto_has_Compra.mf_get_precio();
    obj_Producto_has_Compra.mf_get_descripcion();
    */
