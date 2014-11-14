#ifndef OBJECT_CONTENEDOR_HAS_PRODUCTO_H
#define OBJECT_CONTENEDOR_HAS_PRODUCTO_H

#include "share_include.h"

#define TABLE_NAME_CONTENEDOR_HAS_PRODUCTO "Contenedor_has_Producto"
class object_Contenedor_has_Producto:public object_general
{

private:
	_QSTR md_o_idContenedor;
	_QSTR md_o_Contenedor_idContenedor;
	_QSTR md_o_Producto_idProducto;
	_QSTR md_o_Colaborador_Persona_idPersona;
	_QSTR md_o_fecha;
	_QSTR md_o_cantidadProducto;

public:
	object_Contenedor_has_Producto();
	object_Contenedor_has_Producto(_QSTR idContenedor, _QSTR Contenedor_idContenedor, _QSTR Producto_idProducto, _QSTR Colaborador_Persona_idPersona, _QSTR fecha, _QSTR cantidadProducto);
	object_Contenedor_has_Producto(_QSTR Contenedor_idContenedor, _QSTR Producto_idProducto, _QSTR Colaborador_Persona_idPersona, _QSTR fecha, _QSTR cantidadProducto);

	void mf_set_idContenedor(_QSTR idContenedor);
	void mf_set_Contenedor_idContenedor(_QSTR Contenedor_idContenedor);
	void mf_set_Producto_idProducto(_QSTR Producto_idProducto);
	void mf_set_Colaborador_Persona_idPersona(_QSTR Colaborador_Persona_idPersona);
	void mf_set_fecha(_QSTR fecha);
	void mf_set_cantidadProducto(_QSTR cantidadProducto);

	_QSTR mf_get_idContenedor();
	_QSTR mf_get_Contenedor_idContenedor();
	_QSTR mf_get_Producto_idProducto();
	_QSTR mf_get_Colaborador_Persona_idPersona();
	_QSTR mf_get_fecha();
	_QSTR mf_get_cantidadProducto();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();
    bool mf_exist_product();
    QSqlQueryModel* mf_show();
    QSqlQueryModel* mf_show_ubication();
    bool mf_update_cant(int);
    bool mf_remove_cant(int);

	~object_Contenedor_has_Producto();
};
#endif // OBJECT_CONTENEDOR_HAS_PRODUCTO_H
	/*
	object_Contenedor_has_Producto obj_Contenedor_has_Producto;
	obj_Contenedor_has_Producto.mf_set_idContenedor();
	obj_Contenedor_has_Producto.mf_set_Contenedor_idContenedor();
	obj_Contenedor_has_Producto.mf_set_Producto_idProducto();
	obj_Contenedor_has_Producto.mf_set_Colaborador_Persona_idPersona();
	obj_Contenedor_has_Producto.mf_set_fecha();
	obj_Contenedor_has_Producto.mf_set_cantidadProducto();

	obj_Contenedor_has_Producto.mf_get_idContenedor();
	obj_Contenedor_has_Producto.mf_get_Contenedor_idContenedor();
	obj_Contenedor_has_Producto.mf_get_Producto_idProducto();
	obj_Contenedor_has_Producto.mf_get_Colaborador_Persona_idPersona();
	obj_Contenedor_has_Producto.mf_get_fecha();
	obj_Contenedor_has_Producto.mf_get_cantidadProducto();
	*/
