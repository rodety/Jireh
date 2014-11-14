#ifndef OBJECT_ENTREGAPRODUCTO_H
#define OBJECT_ENTREGAPRODUCTO_H

#include "share_include.h"

#define TABLE_NAME_ENTREGAPRODUCTO "EntregaProducto"
class object_EntregaProducto:public object_general
{

private:
    _QSTR md_o_idEntregaProducto;
    _QSTR md_o_Cliente_idCliente;
    _QSTR md_o_Colaborador_idColaborador;
    _QSTR md_o_Producto_idProducto;
    _QSTR md_o_Venta_idVenta;
    _QSTR md_o_estado;
    _QSTR md_o_fecha;

public:
    object_EntregaProducto();
    object_EntregaProducto(_QSTR idEntregaProducto, _QSTR Cliente_idCliente, _QSTR Colaborador_idColaborador, _QSTR Producto_idProducto, _QSTR Venta_idVenta, _QSTR estado, _QSTR fecha);
    object_EntregaProducto(_QSTR Cliente_idCliente, _QSTR Colaborador_idColaborador, _QSTR Producto_idProducto, _QSTR Venta_idVenta, _QSTR estado, _QSTR fecha);

    void mf_set_idEntregaProducto(_QSTR idEntregaProducto);
    void mf_set_Cliente_idCliente(_QSTR Cliente_idCliente);
    void mf_set_Colaborador_idColaborador(_QSTR Colaborador_idColaborador);
    void mf_set_Producto_idProducto(_QSTR Producto_idProducto);
    void mf_set_Venta_idVenta(_QSTR Venta_idVenta);
    void mf_set_estado(_QSTR estado);
    void mf_set_fecha(_QSTR fecha);

    _QSTR mf_get_idEntregaProducto();
    _QSTR mf_get_Cliente_idCliente();
    _QSTR mf_get_Colaborador_idColaborador();
    _QSTR mf_get_Producto_idProducto();
    _QSTR mf_get_Venta_idVenta();
    _QSTR mf_get_estado();
    _QSTR mf_get_fecha();
    vector<_QSTR> mf_listPk(_QSTR pk);
    bool mf_load(_QSTR pk);
    bool mf_add();
    bool mf_update();
    bool mf_remove();

    ~object_EntregaProducto();
};
#endif // OBJECT_ENTREGAPRODUCTO_H
    /*
    object_EntregaProducto obj_EntregaProducto;
    obj_EntregaProducto.mf_set_idEntregaProducto();
    obj_EntregaProducto.mf_set_Cliente_idCliente();
    obj_EntregaProducto.mf_set_Colaborador_idColaborador();
    obj_EntregaProducto.mf_set_Producto_idProducto();
    obj_EntregaProducto.mf_set_Venta_idVenta();
    obj_EntregaProducto.mf_set_estado();
    obj_EntregaProducto.mf_set_fecha();

    obj_EntregaProducto.mf_get_idEntregaProducto();
    obj_EntregaProducto.mf_get_Cliente_idCliente();
    obj_EntregaProducto.mf_get_Colaborador_idColaborador();
    obj_EntregaProducto.mf_get_Producto_idProducto();
    obj_EntregaProducto.mf_get_Venta_idVenta();
    obj_EntregaProducto.mf_get_estado();
    obj_EntregaProducto.mf_get_fecha();
    */
