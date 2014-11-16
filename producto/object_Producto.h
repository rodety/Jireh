#ifndef OBJECT_PRODUCTO_H
#define OBJECT_PRODUCTO_H

#include "share_include.h"

#define TABLE_NAME_PRODUCTO "Producto"
class object_Producto:public object_general
{

private:
	_QSTR md_o_idProducto;
	_QSTR md_o_codigo;
	_QSTR md_o_descripcion;
	_QSTR md_o_precioCompra;
	_QSTR md_o_precioVenta;
	_QSTR md_o_precioDescuento;
	_QSTR md_o_accesorios;
	_QSTR md_o_stock;
	_QSTR md_o_observaciones;
	_QSTR md_o_Estado_idEstado;
	_QSTR md_o_Marca_idMarca;
	_QSTR md_o_idColaborador;
	_QSTR md_o_cantidadVitrina;
	_QSTR md_o_cantidadAlmacen;
	_QSTR md_o_tipo;

public:
	object_Producto();
	object_Producto(_QSTR idProducto, _QSTR codigo, _QSTR descripcion, _QSTR precioCompra, _QSTR precioVenta, _QSTR precioDescuento, _QSTR accesorios, _QSTR stock, _QSTR observaciones, _QSTR Estado_idEstado, _QSTR Marca_idMarca, _QSTR idColaborador, _QSTR cantidadVitrina, _QSTR cantidadAlmacen, _QSTR tipo);
	object_Producto(_QSTR codigo, _QSTR descripcion, _QSTR precioCompra, _QSTR precioVenta, _QSTR precioDescuento, _QSTR accesorios, _QSTR stock, _QSTR observaciones, _QSTR Estado_idEstado, _QSTR Marca_idMarca, _QSTR idColaborador, _QSTR cantidadVitrina, _QSTR cantidadAlmacen, _QSTR tipo);

	void mf_set_idProducto(_QSTR idProducto);
	void mf_set_codigo(_QSTR codigo);
	void mf_set_descripcion(_QSTR descripcion);
	void mf_set_precioCompra(_QSTR precioCompra);
	void mf_set_precioVenta(_QSTR precioVenta);
	void mf_set_precioDescuento(_QSTR precioDescuento);
	void mf_set_accesorios(_QSTR accesorios);
	void mf_set_stock(_QSTR stock);
	void mf_set_observaciones(_QSTR observaciones);
	void mf_set_Estado_idEstado(_QSTR Estado_idEstado);
	void mf_set_Marca_idMarca(_QSTR Marca_idMarca);
	void mf_set_idColaborador(_QSTR idColaborador);
	void mf_set_cantidadVitrina(_QSTR cantidadVitrina);
	void mf_set_cantidadAlmacen(_QSTR cantidadAlmacen);
	void mf_set_tipo(_QSTR tipo);

	_QSTR mf_get_idProducto();
	_QSTR mf_get_codigo();
	_QSTR mf_get_descripcion();
	_QSTR mf_get_precioCompra();
	_QSTR mf_get_precioVenta();
	_QSTR mf_get_precioDescuento();
	_QSTR mf_get_accesorios();
	_QSTR mf_get_stock();
	_QSTR mf_get_observaciones();
	_QSTR mf_get_Estado_idEstado();
	_QSTR mf_get_Marca_idMarca();
	_QSTR mf_get_idColaborador();
	_QSTR mf_get_cantidadVitrina();
	_QSTR mf_get_cantidadAlmacen();
	_QSTR mf_get_tipo();

	bool mf_load(_QSTR pk);
    bool mf_load_stock(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();
    bool mf_update_cant_vitrina(int cant);
    bool mf_update_cant_almacen(int cant);
    static QSqlQueryModel* mf_search(_QSTR cod);
    bool mf_load_code(_QSTR code);
    bool mf_update_cant_stock_price(int cant, double price);
    bool mf_update_cant_stock(int cant);
    bool mf_registrarKardex(int cant,int stock,QString detalle, int tipo);

	~object_Producto();
};
#endif // OBJECT_PRODUCTO_H
	/*
	object_Producto obj_Producto;
	obj_Producto.mf_set_idProducto();
	obj_Producto.mf_set_codigo();
	obj_Producto.mf_set_descripcion();
	obj_Producto.mf_set_precioCompra();
	obj_Producto.mf_set_precioVenta();
	obj_Producto.mf_set_precioDescuento();
	obj_Producto.mf_set_accesorios();
	obj_Producto.mf_set_stock();
	obj_Producto.mf_set_observaciones();
	obj_Producto.mf_set_Estado_idEstado();
	obj_Producto.mf_set_Marca_idMarca();
	obj_Producto.mf_set_idColaborador();
	obj_Producto.mf_set_cantidadVitrina();
	obj_Producto.mf_set_cantidadAlmacen();
	obj_Producto.mf_set_tipo();

	obj_Producto.mf_get_idProducto();
	obj_Producto.mf_get_codigo();
	obj_Producto.mf_get_descripcion();
	obj_Producto.mf_get_precioCompra();
	obj_Producto.mf_get_precioVenta();
	obj_Producto.mf_get_precioDescuento();
	obj_Producto.mf_get_accesorios();
	obj_Producto.mf_get_stock();
	obj_Producto.mf_get_observaciones();
	obj_Producto.mf_get_Estado_idEstado();
	obj_Producto.mf_get_Marca_idMarca();
	obj_Producto.mf_get_idColaborador();
	obj_Producto.mf_get_cantidadVitrina();
	obj_Producto.mf_get_cantidadAlmacen();
	obj_Producto.mf_get_tipo();
	*/
