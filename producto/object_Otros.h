#ifndef OBJECT_OTROS_H
#define OBJECT_OTROS_H

#include "share_include.h"

#define TABLE_NAME_OTROS "Otros"
class object_Otros:public object_general
{

private:
	_QSTR md_o_Producto_idProducto;
	_QSTR md_o_Color_idColor;
	_QSTR md_o_Talla_idTalla;
	_QSTR md_o_Calidad_idCalidad;
	_QSTR md_o_TipoOtros_idTipoOtros;
	_QSTR md_o_Genero_idGenero;

public:
	object_Otros();
	object_Otros(_QSTR Producto_idProducto, _QSTR Color_idColor, _QSTR Talla_idTalla, _QSTR Calidad_idCalidad, _QSTR TipoOtros_idTipoOtros, _QSTR Genero_idGenero);
	object_Otros(_QSTR Color_idColor, _QSTR Talla_idTalla, _QSTR Calidad_idCalidad, _QSTR TipoOtros_idTipoOtros, _QSTR Genero_idGenero);

	void mf_set_Producto_idProducto(_QSTR Producto_idProducto);
	void mf_set_Color_idColor(_QSTR Color_idColor);
	void mf_set_Talla_idTalla(_QSTR Talla_idTalla);
	void mf_set_Calidad_idCalidad(_QSTR Calidad_idCalidad);
	void mf_set_TipoOtros_idTipoOtros(_QSTR TipoOtros_idTipoOtros);
	void mf_set_Genero_idGenero(_QSTR Genero_idGenero);

	_QSTR mf_get_Producto_idProducto();
	_QSTR mf_get_Color_idColor();
	_QSTR mf_get_Talla_idTalla();
	_QSTR mf_get_Calidad_idCalidad();
	_QSTR mf_get_TipoOtros_idTipoOtros();
	_QSTR mf_get_Genero_idGenero();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_Otros();
        QSqlQueryModel* mf_show(object_Producto tmp);
        QSqlQueryModel* mf_show_search(QString id);
};
#endif // OBJECT_OTROS_H
	/*
	object_Otros obj_Otros;
	obj_Otros.mf_set_Producto_idProducto();
	obj_Otros.mf_set_Color_idColor();
	obj_Otros.mf_set_Talla_idTalla();
	obj_Otros.mf_set_Calidad_idCalidad();
	obj_Otros.mf_set_TipoOtros_idTipoOtros();
	obj_Otros.mf_set_Genero_idGenero();

	obj_Otros.mf_get_Producto_idProducto();
	obj_Otros.mf_get_Color_idColor();
	obj_Otros.mf_get_Talla_idTalla();
	obj_Otros.mf_get_Calidad_idCalidad();
	obj_Otros.mf_get_TipoOtros_idTipoOtros();
	obj_Otros.mf_get_Genero_idGenero();
	*/
