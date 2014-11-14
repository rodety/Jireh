#ifndef OBJECT_TARJETA_H
#define OBJECT_TARJETA_H

#include "share_include.h"

#define TABLE_NAME_TARJETA "Tarjeta"
class object_Tarjeta:public object_general
{

private:
	_QSTR md_o_idTarjeta;
	_QSTR md_o_nombre;
	_QSTR md_o_descripcion;

public:
	object_Tarjeta();
	object_Tarjeta(_QSTR idTarjeta, _QSTR nombre, _QSTR descripcion);
	object_Tarjeta(_QSTR nombre, _QSTR descripcion);

	void mf_set_idTarjeta(_QSTR idTarjeta);
	void mf_set_nombre(_QSTR nombre);
	void mf_set_descripcion(_QSTR descripcion);

	_QSTR mf_get_idTarjeta();
	_QSTR mf_get_nombre();
	_QSTR mf_get_descripcion();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();
    bool completar();

    static QSqlQueryModel* mostrarId();

	~object_Tarjeta();
};
#endif // OBJECT_TARJETA_H
	/*
	object_Tarjeta obj_Tarjeta;
	obj_Tarjeta.mf_set_idTarjeta();
	obj_Tarjeta.mf_set_nombre();
	obj_Tarjeta.mf_set_descripcion();

	obj_Tarjeta.mf_get_idTarjeta();
	obj_Tarjeta.mf_get_nombre();
	obj_Tarjeta.mf_get_descripcion();
	*/
