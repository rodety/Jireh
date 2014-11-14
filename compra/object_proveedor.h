#ifndef OBJECT_PROVEEDOR_H
#define OBJECT_PROVEEDOR_H

#include "share_include.h"

#define TABLE_NAME_PROVEEDOR "proveedor"
class object_proveedor:public object_general
{

private:
	_QSTR md_o_idProveedor;
	_QSTR md_o_raz_social;
	_QSTR md_o_ruc;
	_QSTR md_o_direccion;
	_QSTR md_o_fecha;
	_QSTR md_o_telefono1;
	_QSTR md_o_telefono2;
	_QSTR md_o_nombre_contacto;
	_QSTR md_o_email;
	_QSTR md_o_nombre_banco;
	_QSTR md_o_numero_cuenta;
	_QSTR md_o_comentario;

public:
	object_proveedor();
	object_proveedor(_QSTR idProveedor, _QSTR raz_social, _QSTR ruc, _QSTR direccion, _QSTR fecha, _QSTR telefono1, _QSTR telefono2, _QSTR nombre_contacto, _QSTR email, _QSTR nombre_banco, _QSTR numero_cuenta, _QSTR comentario);
	object_proveedor(_QSTR raz_social, _QSTR ruc, _QSTR direccion, _QSTR fecha, _QSTR telefono1, _QSTR telefono2, _QSTR nombre_contacto, _QSTR email, _QSTR nombre_banco, _QSTR numero_cuenta, _QSTR comentario);

	void mf_set_idProveedor(_QSTR idProveedor);
	void mf_set_raz_social(_QSTR raz_social);
	void mf_set_ruc(_QSTR ruc);
	void mf_set_direccion(_QSTR direccion);
	void mf_set_fecha(_QSTR fecha);
	void mf_set_telefono1(_QSTR telefono1);
	void mf_set_telefono2(_QSTR telefono2);
	void mf_set_nombre_contacto(_QSTR nombre_contacto);
	void mf_set_email(_QSTR email);
	void mf_set_nombre_banco(_QSTR nombre_banco);
	void mf_set_numero_cuenta(_QSTR numero_cuenta);
	void mf_set_comentario(_QSTR comentario);

	_QSTR mf_get_idProveedor();
	_QSTR mf_get_raz_social();
	_QSTR mf_get_ruc();
	_QSTR mf_get_direccion();
	_QSTR mf_get_fecha();
	_QSTR mf_get_telefono1();
	_QSTR mf_get_telefono2();
	_QSTR mf_get_nombre_contacto();
	_QSTR mf_get_email();
	_QSTR mf_get_nombre_banco();
	_QSTR mf_get_numero_cuenta();
	_QSTR mf_get_comentario();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_proveedor();
};
#endif // OBJECT_PROVEEDOR_H
	/*
	object_proveedor obj_proveedor;
	obj_proveedor.mf_set_idProveedor();
	obj_proveedor.mf_set_raz_social();
	obj_proveedor.mf_set_ruc();
	obj_proveedor.mf_set_direccion();
	obj_proveedor.mf_set_fecha();
	obj_proveedor.mf_set_telefono1();
	obj_proveedor.mf_set_telefono2();
	obj_proveedor.mf_set_nombre_contacto();
	obj_proveedor.mf_set_email();
	obj_proveedor.mf_set_nombre_banco();
	obj_proveedor.mf_set_numero_cuenta();
	obj_proveedor.mf_set_comentario();

	obj_proveedor.mf_get_idProveedor();
	obj_proveedor.mf_get_raz_social();
	obj_proveedor.mf_get_ruc();
	obj_proveedor.mf_get_direccion();
	obj_proveedor.mf_get_fecha();
	obj_proveedor.mf_get_telefono1();
	obj_proveedor.mf_get_telefono2();
	obj_proveedor.mf_get_nombre_contacto();
	obj_proveedor.mf_get_email();
	obj_proveedor.mf_get_nombre_banco();
	obj_proveedor.mf_get_numero_cuenta();
	obj_proveedor.mf_get_comentario();
	*/
