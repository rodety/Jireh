#ifndef OBJECT_PRODUCTO_HAS_VITRINA_H
#define OBJECT_PRODUCTO_HAS_VITRINA_H

#include "share_include.h"

#define TABLE_NAME_PRODUCTO_HAS_VITRINA "Producto_has_Vitrina"
class object_Producto_has_Vitrina:public object_general
{

private:
	_QSTR md_o_idProducto_has_Vitrina;
	_QSTR md_o_Producto_idProducto;
	_QSTR md_o_Vitrina_Ubicacion_idUbicacion;
	_QSTR md_o_Colaborador_Persona_idPersona;
	_QSTR md_o_fila;
	_QSTR md_o_columna;
	_QSTR md_o_nivel;
	_QSTR md_o_fecha;
	_QSTR md_o_estado;
	_QSTR md_o_comentario;

public:
	object_Producto_has_Vitrina();
	object_Producto_has_Vitrina(_QSTR idProducto_has_Vitrina, _QSTR Producto_idProducto, _QSTR Vitrina_Ubicacion_idUbicacion, _QSTR Colaborador_Persona_idPersona, _QSTR fila, _QSTR columna, _QSTR nivel, _QSTR fecha, _QSTR estado, _QSTR comentario);
	object_Producto_has_Vitrina(_QSTR Producto_idProducto, _QSTR Vitrina_Ubicacion_idUbicacion, _QSTR Colaborador_Persona_idPersona, _QSTR fila, _QSTR columna, _QSTR nivel, _QSTR fecha, _QSTR estado, _QSTR comentario);

	void mf_set_idProducto_has_Vitrina(_QSTR idProducto_has_Vitrina);
	void mf_set_Producto_idProducto(_QSTR Producto_idProducto);
	void mf_set_Vitrina_Ubicacion_idUbicacion(_QSTR Vitrina_Ubicacion_idUbicacion);
	void mf_set_Colaborador_Persona_idPersona(_QSTR Colaborador_Persona_idPersona);
	void mf_set_fila(_QSTR fila);
	void mf_set_columna(_QSTR columna);
	void mf_set_nivel(_QSTR nivel);
	void mf_set_fecha(_QSTR fecha);
	void mf_set_estado(_QSTR estado);
	void mf_set_comentario(_QSTR comentario);

	_QSTR mf_get_idProducto_has_Vitrina();
	_QSTR mf_get_Producto_idProducto();
	_QSTR mf_get_Vitrina_Ubicacion_idUbicacion();
	_QSTR mf_get_Colaborador_Persona_idPersona();
	_QSTR mf_get_fila();
	_QSTR mf_get_columna();
	_QSTR mf_get_nivel();
	_QSTR mf_get_fecha();
	_QSTR mf_get_estado();
	_QSTR mf_get_comentario();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();
    QSqlQueryModel* mf_show();
    bool mf_update_comentario();
    bool mf_update_estado();

	~object_Producto_has_Vitrina();
};
#endif // OBJECT_PRODUCTO_HAS_VITRINA_H
	/*
	object_Producto_has_Vitrina obj_Producto_has_Vitrina;
	obj_Producto_has_Vitrina.mf_set_idProducto_has_Vitrina();
	obj_Producto_has_Vitrina.mf_set_Producto_idProducto();
	obj_Producto_has_Vitrina.mf_set_Vitrina_Ubicacion_idUbicacion();
	obj_Producto_has_Vitrina.mf_set_Colaborador_Persona_idPersona();
	obj_Producto_has_Vitrina.mf_set_fila();
	obj_Producto_has_Vitrina.mf_set_columna();
	obj_Producto_has_Vitrina.mf_set_nivel();
	obj_Producto_has_Vitrina.mf_set_fecha();
	obj_Producto_has_Vitrina.mf_set_estado();
	obj_Producto_has_Vitrina.mf_set_comentario();

	obj_Producto_has_Vitrina.mf_get_idProducto_has_Vitrina();
	obj_Producto_has_Vitrina.mf_get_Producto_idProducto();
	obj_Producto_has_Vitrina.mf_get_Vitrina_Ubicacion_idUbicacion();
	obj_Producto_has_Vitrina.mf_get_Colaborador_Persona_idPersona();
	obj_Producto_has_Vitrina.mf_get_fila();
	obj_Producto_has_Vitrina.mf_get_columna();
	obj_Producto_has_Vitrina.mf_get_nivel();
	obj_Producto_has_Vitrina.mf_get_fecha();
	obj_Producto_has_Vitrina.mf_get_estado();
	obj_Producto_has_Vitrina.mf_get_comentario();
	*/
