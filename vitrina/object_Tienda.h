#ifndef OBJECT_TIENDA_H
#define OBJECT_TIENDA_H

#include "share_include.h"

#define TABLE_NAME_TIENDA "Tienda"
class object_Tienda:public object_general
{

private:
	_QSTR md_o_idTienda;
	_QSTR md_o_Empresa_idEmpresa;
	_QSTR md_o_nombre;
	_QSTR md_o_direccion;
	_QSTR md_o_telefono;
	_QSTR md_o_permisoMunicipal;
	_QSTR md_o_email;
	_QSTR md_o_razonSocial;
	_QSTR md_o_ruc;
	_QSTR md_o_mensaje_cliente;
	_QSTR md_o_mensaje_compra;

public:
	object_Tienda();
	object_Tienda(_QSTR idTienda, _QSTR Empresa_idEmpresa, _QSTR nombre, _QSTR direccion, _QSTR telefono, _QSTR permisoMunicipal, _QSTR email, _QSTR razonSocial, _QSTR ruc, _QSTR mensaje_cliente, _QSTR mensaje_compra);
	object_Tienda(_QSTR Empresa_idEmpresa, _QSTR nombre, _QSTR direccion, _QSTR telefono, _QSTR permisoMunicipal, _QSTR email, _QSTR razonSocial, _QSTR ruc, _QSTR mensaje_cliente, _QSTR mensaje_compra);

	void mf_set_idTienda(_QSTR idTienda);
	void mf_set_Empresa_idEmpresa(_QSTR Empresa_idEmpresa);
	void mf_set_nombre(_QSTR nombre);
	void mf_set_direccion(_QSTR direccion);
	void mf_set_telefono(_QSTR telefono);
	void mf_set_permisoMunicipal(_QSTR permisoMunicipal);
	void mf_set_email(_QSTR email);
	void mf_set_razonSocial(_QSTR razonSocial);
	void mf_set_ruc(_QSTR ruc);
	void mf_set_mensaje_cliente(_QSTR mensaje_cliente);
	void mf_set_mensaje_compra(_QSTR mensaje_compra);

	_QSTR mf_get_idTienda();
	_QSTR mf_get_Empresa_idEmpresa();
	_QSTR mf_get_nombre();
	_QSTR mf_get_direccion();
	_QSTR mf_get_telefono();
	_QSTR mf_get_permisoMunicipal();
	_QSTR mf_get_email();
	_QSTR mf_get_razonSocial();
	_QSTR mf_get_ruc();
	_QSTR mf_get_mensaje_cliente();
	_QSTR mf_get_mensaje_compra();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();
    QSqlQueryModel* mf_show(QString);
    QSqlQueryModel* mf_show_all();

	~object_Tienda();
};
#endif // OBJECT_TIENDA_H
	/*
	object_Tienda obj_Tienda;
	obj_Tienda.mf_set_idTienda();
	obj_Tienda.mf_set_Empresa_idEmpresa();
	obj_Tienda.mf_set_nombre();
	obj_Tienda.mf_set_direccion();
	obj_Tienda.mf_set_telefono();
	obj_Tienda.mf_set_permisoMunicipal();
	obj_Tienda.mf_set_email();
	obj_Tienda.mf_set_razonSocial();
	obj_Tienda.mf_set_ruc();
	obj_Tienda.mf_set_mensaje_cliente();
	obj_Tienda.mf_set_mensaje_compra();

	obj_Tienda.mf_get_idTienda();
	obj_Tienda.mf_get_Empresa_idEmpresa();
	obj_Tienda.mf_get_nombre();
	obj_Tienda.mf_get_direccion();
	obj_Tienda.mf_get_telefono();
	obj_Tienda.mf_get_permisoMunicipal();
	obj_Tienda.mf_get_email();
	obj_Tienda.mf_get_razonSocial();
	obj_Tienda.mf_get_ruc();
	obj_Tienda.mf_get_mensaje_cliente();
	obj_Tienda.mf_get_mensaje_compra();
	*/
