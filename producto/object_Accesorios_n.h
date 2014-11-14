#ifndef OBJECT_ACCESORIOS_H
#define OBJECT_ACCESORIOS_H

#include "share_include.h"

#define TABLE_NAME_ACCESORIOS "Accesorios"
class object_Accesorios_n:public object_general
{

private:
	_QSTR md_o_Producto_idProducto;
	_QSTR md_o_Color_idColor;
	_QSTR md_o_Tamanio_idTamanio;
	_QSTR md_o_Calidad_idCalidad;
	_QSTR md_o_Genero_idGenero;

public:
    object_Accesorios_n();
    object_Accesorios_n(_QSTR Producto_idProducto, _QSTR Color_idColor, _QSTR Tamanio_idTamanio, _QSTR Calidad_idCalidad, _QSTR Genero_idGenero);
    object_Accesorios_n(_QSTR Color_idColor, _QSTR Tamanio_idTamanio, _QSTR Calidad_idCalidad, _QSTR Genero_idGenero);

	void mf_set_Producto_idProducto(_QSTR Producto_idProducto);
	void mf_set_Color_idColor(_QSTR Color_idColor);
	void mf_set_Tamanio_idTamanio(_QSTR Tamanio_idTamanio);
	void mf_set_Calidad_idCalidad(_QSTR Calidad_idCalidad);
	void mf_set_Genero_idGenero(_QSTR Genero_idGenero);

	_QSTR mf_get_Producto_idProducto();
	_QSTR mf_get_Color_idColor();
	_QSTR mf_get_Tamanio_idTamanio();
	_QSTR mf_get_Calidad_idCalidad();
	_QSTR mf_get_Genero_idGenero();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

    ~object_Accesorios_n();
};
#endif // OBJECT_ACCESORIOS_H
	/*
	object_Accesorios obj_Accesorios;
	obj_Accesorios.mf_set_Producto_idProducto();
	obj_Accesorios.mf_set_Color_idColor();
	obj_Accesorios.mf_set_Tamanio_idTamanio();
	obj_Accesorios.mf_set_Calidad_idCalidad();
	obj_Accesorios.mf_set_Genero_idGenero();

	obj_Accesorios.mf_get_Producto_idProducto();
	obj_Accesorios.mf_get_Color_idColor();
	obj_Accesorios.mf_get_Tamanio_idTamanio();
	obj_Accesorios.mf_get_Calidad_idCalidad();
	obj_Accesorios.mf_get_Genero_idGenero();
	*/
