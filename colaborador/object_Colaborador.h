#ifndef OBJECT_COLABORADOR_H
#define OBJECT_COLABORADOR_H

#include "share_include.h"

#define TABLE_NAME_COLABORADOR "Colaborador"
class object_Colaborador:public object_general
{

private:
	_QSTR md_o_nombres;
	_QSTR md_o_primer_apellido;
	_QSTR md_o_segundo_apellido;
	_QSTR md_o_idTipoColaborador;
	_QSTR md_o_usuario;
	_QSTR md_o_habilitado;
	_QSTR md_o_Documento_idDocumento;
	_QSTR md_o_numeroDocumento;
	_QSTR md_o_direccion;
	_QSTR md_o_sexo;
	_QSTR md_o_fechaNacimiento;
	_QSTR md_o_movil;
	_QSTR md_o_email;
	_QSTR md_o_telefono;
	_QSTR md_o_telefono2;
	_QSTR md_o_resset_pass;
	_QSTR md_o_observaciones;
	_QSTR md_o_contrasena;
	_QSTR md_o_idColaborador;

public:
	object_Colaborador();
	object_Colaborador(_QSTR nombres, _QSTR primer_apellido, _QSTR segundo_apellido, _QSTR idTipoColaborador, _QSTR usuario, _QSTR habilitado, _QSTR Documento_idDocumento, _QSTR numeroDocumento, _QSTR direccion, _QSTR sexo, _QSTR fechaNacimiento, _QSTR movil, _QSTR email, _QSTR telefono, _QSTR telefono2, _QSTR resset_pass, _QSTR observaciones, _QSTR contrasena, _QSTR idColaborador);
	object_Colaborador(_QSTR primer_apellido, _QSTR segundo_apellido, _QSTR idTipoColaborador, _QSTR usuario, _QSTR habilitado, _QSTR Documento_idDocumento, _QSTR numeroDocumento, _QSTR direccion, _QSTR sexo, _QSTR fechaNacimiento, _QSTR movil, _QSTR email, _QSTR telefono, _QSTR telefono2, _QSTR resset_pass, _QSTR observaciones, _QSTR contrasena, _QSTR idColaborador);

	void mf_set_nombres(_QSTR nombres);
	void mf_set_primer_apellido(_QSTR primer_apellido);
	void mf_set_segundo_apellido(_QSTR segundo_apellido);
	void mf_set_idTipoColaborador(_QSTR idTipoColaborador);
	void mf_set_usuario(_QSTR usuario);
	void mf_set_habilitado(_QSTR habilitado);
	void mf_set_Documento_idDocumento(_QSTR Documento_idDocumento);
	void mf_set_numeroDocumento(_QSTR numeroDocumento);
	void mf_set_direccion(_QSTR direccion);
	void mf_set_sexo(_QSTR sexo);
	void mf_set_fechaNacimiento(_QSTR fechaNacimiento);
	void mf_set_movil(_QSTR movil);
	void mf_set_email(_QSTR email);
	void mf_set_telefono(_QSTR telefono);
	void mf_set_telefono2(_QSTR telefono2);
	void mf_set_resset_pass(_QSTR resset_pass);
	void mf_set_observaciones(_QSTR observaciones);
	void mf_set_contrasena(_QSTR contrasena);
	void mf_set_idColaborador(_QSTR idColaborador);

	_QSTR mf_get_nombres();
	_QSTR mf_get_primer_apellido();
	_QSTR mf_get_segundo_apellido();
	_QSTR mf_get_idTipoColaborador();
	_QSTR mf_get_usuario();
	_QSTR mf_get_habilitado();
	_QSTR mf_get_Documento_idDocumento();
	_QSTR mf_get_numeroDocumento();
	_QSTR mf_get_direccion();
	_QSTR mf_get_sexo();
	_QSTR mf_get_fechaNacimiento();
	_QSTR mf_get_movil();
	_QSTR mf_get_email();
	_QSTR mf_get_telefono();
	_QSTR mf_get_telefono2();
	_QSTR mf_get_resset_pass();
	_QSTR mf_get_observaciones();
	_QSTR mf_get_contrasena();
	_QSTR mf_get_idColaborador();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
    bool mf_remove();
    static QSqlQueryModel* mf_show();


	~object_Colaborador();
};
#endif // OBJECT_COLABORADOR_H
	/*
	object_Colaborador obj_Colaborador;
	obj_Colaborador.mf_set_nombres();
	obj_Colaborador.mf_set_primer_apellido();
	obj_Colaborador.mf_set_segundo_apellido();
	obj_Colaborador.mf_set_idTipoColaborador();
	obj_Colaborador.mf_set_usuario();
	obj_Colaborador.mf_set_habilitado();
	obj_Colaborador.mf_set_Documento_idDocumento();
	obj_Colaborador.mf_set_numeroDocumento();
	obj_Colaborador.mf_set_direccion();
	obj_Colaborador.mf_set_sexo();
	obj_Colaborador.mf_set_fechaNacimiento();
	obj_Colaborador.mf_set_movil();
	obj_Colaborador.mf_set_email();
	obj_Colaborador.mf_set_telefono();
	obj_Colaborador.mf_set_telefono2();
	obj_Colaborador.mf_set_resset_pass();
	obj_Colaborador.mf_set_observaciones();
	obj_Colaborador.mf_set_contrasena();
	obj_Colaborador.mf_set_idColaborador();

	obj_Colaborador.mf_get_nombres();
	obj_Colaborador.mf_get_primer_apellido();
	obj_Colaborador.mf_get_segundo_apellido();
	obj_Colaborador.mf_get_idTipoColaborador();
	obj_Colaborador.mf_get_usuario();
	obj_Colaborador.mf_get_habilitado();
	obj_Colaborador.mf_get_Documento_idDocumento();
	obj_Colaborador.mf_get_numeroDocumento();
	obj_Colaborador.mf_get_direccion();
	obj_Colaborador.mf_get_sexo();
	obj_Colaborador.mf_get_fechaNacimiento();
	obj_Colaborador.mf_get_movil();
	obj_Colaborador.mf_get_email();
	obj_Colaborador.mf_get_telefono();
	obj_Colaborador.mf_get_telefono2();
	obj_Colaborador.mf_get_resset_pass();
	obj_Colaborador.mf_get_observaciones();
	obj_Colaborador.mf_get_contrasena();
	obj_Colaborador.mf_get_idColaborador();
	*/
