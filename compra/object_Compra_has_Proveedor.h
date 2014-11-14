#ifndef OBJECT_COMPRA_HAS_PROVEEDOR_H
#define OBJECT_COMPRA_HAS_PROVEEDOR_H

#include "share_include.h"
#include "compra/object_proveedor.h"

#define TABLE_NAME_COMPRA_HAS_PROVEEDOR "Compra_has_Proveedor"
class object_Compra_has_Proveedor:public object_general
{

private:
	_QSTR md_o_Compra_idCompra;
	_QSTR md_o_Proveedor_idProveedor;
	_QSTR md_o_Colaborador_idColaborador;

public:
	object_Compra_has_Proveedor();
	object_Compra_has_Proveedor(_QSTR Compra_idCompra, _QSTR Proveedor_idProveedor, _QSTR Colaborador_idColaborador);
	object_Compra_has_Proveedor(_QSTR Proveedor_idProveedor, _QSTR Colaborador_idColaborador);

	void mf_set_Compra_idCompra(_QSTR Compra_idCompra);
	void mf_set_Proveedor_idProveedor(_QSTR Proveedor_idProveedor);
	void mf_set_Colaborador_idColaborador(_QSTR Colaborador_idColaborador);

	_QSTR mf_get_Compra_idCompra();
	_QSTR mf_get_Proveedor_idProveedor();
	_QSTR mf_get_Colaborador_idColaborador();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();
        object_proveedor mf_getProveedor();

	~object_Compra_has_Proveedor();
};
#endif // OBJECT_COMPRA_HAS_PROVEEDOR_H
	/*
	object_Compra_has_Proveedor obj_Compra_has_Proveedor;
	obj_Compra_has_Proveedor.mf_set_Compra_idCompra();
	obj_Compra_has_Proveedor.mf_set_Proveedor_idProveedor();
	obj_Compra_has_Proveedor.mf_set_Colaborador_idColaborador();

	obj_Compra_has_Proveedor.mf_get_Compra_idCompra();
	obj_Compra_has_Proveedor.mf_get_Proveedor_idProveedor();
	obj_Compra_has_Proveedor.mf_get_Colaborador_idColaborador();
	*/
