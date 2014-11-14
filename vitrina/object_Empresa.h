#ifndef OBJECT_EMPRESA_H
#define OBJECT_EMPRESA_H

#include "share_include.h"

#define TABLE_NAME_EMPRESA "Empresa"
class object_Empresa:public object_general
{

private:
	_QSTR md_o_idEmpresa;
	_QSTR md_o_razonSocial;
	_QSTR md_o_ruc;
	_QSTR md_o_direccion;
	_QSTR md_o_telefono;
	_QSTR md_o_representa_legal;
	_QSTR md_o_email;
	_QSTR md_o_web;

public:
	object_Empresa();
	object_Empresa(_QSTR idEmpresa, _QSTR razonSocial, _QSTR ruc, _QSTR direccion, _QSTR telefono, _QSTR representa_legal, _QSTR email, _QSTR web);
	object_Empresa(_QSTR razonSocial, _QSTR ruc, _QSTR direccion, _QSTR telefono, _QSTR representa_legal, _QSTR email, _QSTR web);

	void mf_set_idEmpresa(_QSTR idEmpresa);
	void mf_set_razonSocial(_QSTR razonSocial);
	void mf_set_ruc(_QSTR ruc);
	void mf_set_direccion(_QSTR direccion);
	void mf_set_telefono(_QSTR telefono);
	void mf_set_representa_legal(_QSTR representa_legal);
	void mf_set_email(_QSTR email);
	void mf_set_web(_QSTR web);

	_QSTR mf_get_idEmpresa();
	_QSTR mf_get_razonSocial();
	_QSTR mf_get_ruc();
	_QSTR mf_get_direccion();
	_QSTR mf_get_telefono();
	_QSTR mf_get_representa_legal();
	_QSTR mf_get_email();
	_QSTR mf_get_web();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();
        QSqlQueryModel* mf_show();

	~object_Empresa();
};
#endif // OBJECT_EMPRESA_H
	/*
	object_Empresa obj_Empresa;
	obj_Empresa.mf_set_idEmpresa();
	obj_Empresa.mf_set_razonSocial();
	obj_Empresa.mf_set_ruc();
	obj_Empresa.mf_set_direccion();
	obj_Empresa.mf_set_telefono();
	obj_Empresa.mf_set_representa_legal();
	obj_Empresa.mf_set_email();
	obj_Empresa.mf_set_web();

	obj_Empresa.mf_get_idEmpresa();
	obj_Empresa.mf_get_razonSocial();
	obj_Empresa.mf_get_ruc();
	obj_Empresa.mf_get_direccion();
	obj_Empresa.mf_get_telefono();
	obj_Empresa.mf_get_representa_legal();
	obj_Empresa.mf_get_email();
	obj_Empresa.mf_get_web();
	*/
