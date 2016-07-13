#ifndef OBJECT_VENTA_HAS_PRODUCTO_H
#define OBJECT_VENTA_HAS_PRODUCTO_H

#include "share_include.h"

#define TABLE_NAME_VENTA_HAS_PRODUCTO "Venta_has_Producto"
class object_Venta_has_Producto:public object_general
{

private:
    _QSTR md_o_idVenta_has_Producto;
    _QSTR md_o_Venta_idVenta;
    _QSTR md_o_Producto_idProducto;
    _QSTR md_o_cantidad;
    _QSTR md_o_precio;
    _QSTR md_o_descuento;
    _QSTR md_o_descripcion;
    _QSTR md_o_Producto_has_Vitrina_idProducto_has_Vitrina;
public:
    object_Venta_has_Producto();
    object_Venta_has_Producto(_QSTR idVenta_has_Producto, _QSTR Venta_idVenta, _QSTR Producto_idProducto, _QSTR cantidad, _QSTR precio, _QSTR descuento, _QSTR descripcion, _QSTR Producto_has_Vitrina_idProducto_has_Vitrina);
    object_Venta_has_Producto(_QSTR Venta_idVenta, _QSTR Producto_idProducto, _QSTR cantidad, _QSTR precio, _QSTR descuento, _QSTR descripcion, _QSTR Producto_has_Vitrina_idProducto_has_Vitrina);

    void mf_set_idVenta_has_Producto(_QSTR idVenta_has_Producto);
    void mf_set_Venta_idVenta(_QSTR Venta_idVenta);
    void mf_set_Producto_idProducto(_QSTR Producto_idProducto);
    void mf_set_cantidad(_QSTR cantidad);
    void mf_set_precio(_QSTR precio);
    void mf_set_descuento(_QSTR descuento);
    void mf_set_descripcion(_QSTR descripcion);
    void mf_set_Producto_has_Vitrina_idProducto_has_Vitrina(_QSTR Producto_has_Vitrina_idProducto_has_Vitrina);

    _QSTR mf_get_idVenta_has_Producto();
    _QSTR mf_get_Venta_idVenta();
    _QSTR mf_get_Producto_idProducto();
    _QSTR mf_get_cantidad();
    _QSTR mf_get_precio();
    _QSTR mf_get_descuento();
    _QSTR mf_get_descripcion();
    _QSTR mf_get_Producto_has_Vitrina_idProducto_has_Vitrina();
    vector<_QSTR> mf_listPk(_QSTR pk);
    bool mf_load(_QSTR pk);
    bool mf_add();
    bool mf_update();
    bool mf_remove();

    ~object_Venta_has_Producto();
};
#endif // OBJECT_VENTA_HAS_PRODUCTO_H
    /*
    object_Venta_has_Producto obj_Venta_has_Producto;
    obj_Venta_has_Producto.mf_set_idVenta_has_Producto();
    obj_Venta_has_Producto.mf_set_Venta_idVenta();
    obj_Venta_has_Producto.mf_set_Producto_idProducto();
    obj_Venta_has_Producto.mf_set_cantidad();
    obj_Venta_has_Producto.mf_set_precio();
    obj_Venta_has_Producto.mf_set_descuento();
    obj_Venta_has_Producto.mf_set_descripcion();
    obj_Venta_has_Producto.mf_get_idVenta_has_Producto();
    obj_Venta_has_Producto.mf_get_Venta_idVenta();
    obj_Venta_has_Producto.mf_get_Producto_idProducto();
    obj_Venta_has_Producto.mf_get_cantidad();
    obj_Venta_has_Producto.mf_get_precio();
    obj_Venta_has_Producto.mf_get_descuento();
    obj_Venta_has_Producto.mf_get_descripcion();
    */
