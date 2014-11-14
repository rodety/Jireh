#ifndef OBJECT_KARDEX_H
#define OBJECT_KARDEX_H

#include "share_include.h"

#define TABLE_NAME_KARDEX "Kardex"
class object_Kardex:public object_general
{

private:
	_QSTR md_o_idKardex;
	_QSTR md_o_Producto_idProducto;
    _QSTR md_o_Colaborador_idColaborador;
	_QSTR md_o_fecha;
	_QSTR md_o_detalle;
	_QSTR md_o_cant;
	_QSTR md_o_costo_unit;
	_QSTR md_o_costo_total;
	_QSTR md_o_costo_promedio;
	_QSTR md_o_saldo_total;
	_QSTR md_o_tipo;

public:
	object_Kardex();
	object_Kardex(_QSTR idKardex, _QSTR Producto_idProducto, _QSTR fecha, _QSTR detalle, _QSTR cant, _QSTR costo_unit, _QSTR costo_total, _QSTR costo_promedio, _QSTR saldo_total, _QSTR tipo);
	object_Kardex(_QSTR Producto_idProducto, _QSTR fecha, _QSTR detalle, _QSTR cant, _QSTR costo_unit, _QSTR costo_total, _QSTR costo_promedio, _QSTR saldo_total, _QSTR tipo);

	void mf_set_idKardex(_QSTR idKardex);
	void mf_set_Producto_idProducto(_QSTR Producto_idProducto);
    void mf_set_Colaborador_idColaborador(_QSTR Colaborador_idColaborador);
	void mf_set_fecha(_QSTR fecha);
	void mf_set_detalle(_QSTR detalle);
	void mf_set_cant(_QSTR cant);
	void mf_set_costo_unit(_QSTR costo_unit);
	void mf_set_costo_total(_QSTR costo_total);
	void mf_set_costo_promedio(_QSTR costo_promedio);
	void mf_set_saldo_total(_QSTR saldo_total);
	void mf_set_tipo(_QSTR tipo);

	_QSTR mf_get_idKardex();
	_QSTR mf_get_Producto_idProducto();
    _QSTR mf_get_Colaborador_idColaborador();
	_QSTR mf_get_fecha();
	_QSTR mf_get_detalle();
	_QSTR mf_get_cant();
	_QSTR mf_get_costo_unit();
	_QSTR mf_get_costo_total();
	_QSTR mf_get_costo_promedio();
	_QSTR mf_get_saldo_total();
	_QSTR mf_get_tipo();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();
    QSqlQueryModel* mf_show();


	~object_Kardex();
};
#endif // OBJECT_KARDEX_H
	/*
	object_Kardex obj_Kardex;
	obj_Kardex.mf_set_idKardex();
	obj_Kardex.mf_set_Producto_idProducto();
	obj_Kardex.mf_set_fecha();
	obj_Kardex.mf_set_detalle();
	obj_Kardex.mf_set_cant();
	obj_Kardex.mf_set_costo_unit();
	obj_Kardex.mf_set_costo_total();
	obj_Kardex.mf_set_costo_promedio();
	obj_Kardex.mf_set_saldo_total();
	obj_Kardex.mf_set_tipo();

	obj_Kardex.mf_get_idKardex();
	obj_Kardex.mf_get_Producto_idProducto();
	obj_Kardex.mf_get_fecha();
	obj_Kardex.mf_get_detalle();
	obj_Kardex.mf_get_cant();
	obj_Kardex.mf_get_costo_unit();
	obj_Kardex.mf_get_costo_total();
	obj_Kardex.mf_get_costo_promedio();
	obj_Kardex.mf_get_saldo_total();
	obj_Kardex.mf_get_tipo();
	*/
