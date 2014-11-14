#ifndef OBJECT_MONTURA_H
#define OBJECT_MONTURA_H

#include "share_include.h"
#include "object_Producto.h"
#define TABLE_NAME_MONTURA "Montura"
class object_Montura:public object_general
{

private:
	_QSTR md_o_Producto_idProducto;
	_QSTR md_o_Forma_idForma;
	_QSTR md_o_Color_idColor;
	_QSTR md_o_Tamanio_idTamanio;
	_QSTR md_o_Calidad_idCalidad;
	_QSTR md_o_Genero_idGenero;

public:
	object_Montura();
	object_Montura(_QSTR Producto_idProducto, _QSTR Forma_idForma, _QSTR Color_idColor, _QSTR Tamanio_idTamanio, _QSTR Calidad_idCalidad, _QSTR Genero_idGenero);
	object_Montura(_QSTR Forma_idForma, _QSTR Color_idColor, _QSTR Tamanio_idTamanio, _QSTR Calidad_idCalidad, _QSTR Genero_idGenero);

	void mf_set_Producto_idProducto(_QSTR Producto_idProducto);
	void mf_set_Forma_idForma(_QSTR Forma_idForma);
	void mf_set_Color_idColor(_QSTR Color_idColor);
	void mf_set_Tamanio_idTamanio(_QSTR Tamanio_idTamanio);
	void mf_set_Calidad_idCalidad(_QSTR Calidad_idCalidad);
	void mf_set_Genero_idGenero(_QSTR Genero_idGenero);

	_QSTR mf_get_Producto_idProducto();
	_QSTR mf_get_Forma_idForma();
	_QSTR mf_get_Color_idColor();
	_QSTR mf_get_Tamanio_idTamanio();
	_QSTR mf_get_Calidad_idCalidad();
	_QSTR mf_get_Genero_idGenero();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_Montura();
        QSqlQueryModel* mf_show(object_Producto tmp);
        QSqlQueryModel* mf_show_search(QString id);
};
#endif // OBJECT_MONTURA_H
	/*
	object_Montura obj_Montura;
	obj_Montura.mf_set_Producto_idProducto();
	obj_Montura.mf_set_Forma_idForma();
	obj_Montura.mf_set_Color_idColor();
	obj_Montura.mf_set_Tamanio_idTamanio();
	obj_Montura.mf_set_Calidad_idCalidad();
	obj_Montura.mf_set_Genero_idGenero();

	obj_Montura.mf_get_Producto_idProducto();
	obj_Montura.mf_get_Forma_idForma();
	obj_Montura.mf_get_Color_idColor();
	obj_Montura.mf_get_Tamanio_idTamanio();
	obj_Montura.mf_get_Calidad_idCalidad();
	obj_Montura.mf_get_Genero_idGenero();
	*/
