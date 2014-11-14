#ifndef OBJECT_CLIENTE_H
#define OBJECT_CLIENTE_H

#include "share_include.h"

#define TABLE_NAME_CLIENTE "Cliente"
class object_Cliente:public object_general
{

private:
	_QSTR md_o_idCliente;
	_QSTR md_o_nombres;
	_QSTR md_o_primer_apellido;
	_QSTR md_o_segundo_apellido;
	_QSTR md_o_numeroDocumento;
	_QSTR md_o_direccion;
	_QSTR md_o_sexo;
	_QSTR md_o_fechaNacimiento;
	_QSTR md_o_telefono;
	_QSTR md_o_telefono2;
	_QSTR md_o_movil;
	_QSTR md_o_email;
	_QSTR md_o_nacionalidad;
	_QSTR md_o_Documento_idDocumento1;
	_QSTR md_o_ruc;
	_QSTR md_o_razonSocial;
	_QSTR md_o_direccion2;

public:
	object_Cliente();
	object_Cliente(_QSTR idCliente, _QSTR nombres, _QSTR primer_apellido, _QSTR segundo_apellido, _QSTR numeroDocumento, _QSTR direccion, _QSTR sexo, _QSTR fechaNacimiento, _QSTR telefono, _QSTR telefono2, _QSTR movil, _QSTR email, _QSTR nacionalidad, _QSTR Documento_idDocumento1, _QSTR ruc, _QSTR razonSocial, _QSTR direccion2);
	object_Cliente(_QSTR nombres, _QSTR primer_apellido, _QSTR segundo_apellido, _QSTR numeroDocumento, _QSTR direccion, _QSTR sexo, _QSTR fechaNacimiento, _QSTR telefono, _QSTR telefono2, _QSTR movil, _QSTR email, _QSTR nacionalidad, _QSTR Documento_idDocumento1, _QSTR ruc, _QSTR razonSocial, _QSTR direccion2);

	void mf_set_idCliente(_QSTR idCliente);
	void mf_set_nombres(_QSTR nombres);
	void mf_set_primer_apellido(_QSTR primer_apellido);
	void mf_set_segundo_apellido(_QSTR segundo_apellido);
	void mf_set_numeroDocumento(_QSTR numeroDocumento);
	void mf_set_direccion(_QSTR direccion);
	void mf_set_sexo(_QSTR sexo);
	void mf_set_fechaNacimiento(_QSTR fechaNacimiento);
	void mf_set_telefono(_QSTR telefono);
	void mf_set_telefono2(_QSTR telefono2);
	void mf_set_movil(_QSTR movil);
	void mf_set_email(_QSTR email);
	void mf_set_nacionalidad(_QSTR nacionalidad);
	void mf_set_Documento_idDocumento1(_QSTR Documento_idDocumento1);
	void mf_set_ruc(_QSTR ruc);
	void mf_set_razonSocial(_QSTR razonSocial);
	void mf_set_direccion2(_QSTR direccion2);

	_QSTR mf_get_idCliente();
	_QSTR mf_get_nombres();
	_QSTR mf_get_primer_apellido();
	_QSTR mf_get_segundo_apellido();
	_QSTR mf_get_numeroDocumento();
	_QSTR mf_get_direccion();
	_QSTR mf_get_sexo();
	_QSTR mf_get_fechaNacimiento();
	_QSTR mf_get_telefono();
	_QSTR mf_get_telefono2();
	_QSTR mf_get_movil();
	_QSTR mf_get_email();
	_QSTR mf_get_nacionalidad();
	_QSTR mf_get_Documento_idDocumento1();
	_QSTR mf_get_ruc();
	_QSTR mf_get_razonSocial();
	_QSTR mf_get_direccion2();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_Cliente();
};
#endif // OBJECT_CLIENTE_H
	/*
	object_Cliente obj_Cliente;
	obj_Cliente.mf_set_idCliente();
	obj_Cliente.mf_set_nombres();
	obj_Cliente.mf_set_primer_apellido();
	obj_Cliente.mf_set_segundo_apellido();
	obj_Cliente.mf_set_numeroDocumento();
	obj_Cliente.mf_set_direccion();
	obj_Cliente.mf_set_sexo();
	obj_Cliente.mf_set_fechaNacimiento();
	obj_Cliente.mf_set_telefono();
	obj_Cliente.mf_set_telefono2();
	obj_Cliente.mf_set_movil();
	obj_Cliente.mf_set_email();
	obj_Cliente.mf_set_nacionalidad();
	obj_Cliente.mf_set_Documento_idDocumento1();
	obj_Cliente.mf_set_ruc();
	obj_Cliente.mf_set_razonSocial();
	obj_Cliente.mf_set_direccion2();

	obj_Cliente.mf_get_idCliente();
	obj_Cliente.mf_get_nombres();
	obj_Cliente.mf_get_primer_apellido();
	obj_Cliente.mf_get_segundo_apellido();
	obj_Cliente.mf_get_numeroDocumento();
	obj_Cliente.mf_get_direccion();
	obj_Cliente.mf_get_sexo();
	obj_Cliente.mf_get_fechaNacimiento();
	obj_Cliente.mf_get_telefono();
	obj_Cliente.mf_get_telefono2();
	obj_Cliente.mf_get_movil();
	obj_Cliente.mf_get_email();
	obj_Cliente.mf_get_nacionalidad();
	obj_Cliente.mf_get_Documento_idDocumento1();
	obj_Cliente.mf_get_ruc();
	obj_Cliente.mf_get_razonSocial();
	obj_Cliente.mf_get_direccion2();
	*/
