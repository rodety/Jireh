#ifndef OBJECT_TIPOOTROS_H
#define OBJECT_TIPOOTROS_H

#include "share_include.h"

#define TABLE_NAME_TIPOOTROS "TipoOtros"
class object_TipoOtros:public object_general
{

private:
	_QSTR md_o_idTipoOtros;
	_QSTR md_o_nombre;

public:
	object_TipoOtros();
	object_TipoOtros(_QSTR idTipoOtros, _QSTR nombre);
	object_TipoOtros(_QSTR nombre);

	void mf_set_idTipoOtros(_QSTR idTipoOtros);
	void mf_set_nombre(_QSTR nombre);

	_QSTR mf_get_idTipoOtros();
	_QSTR mf_get_nombre();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_TipoOtros();
};
#endif // OBJECT_TIPOOTROS_H
	/*
	object_TipoOtros obj_TipoOtros;
	obj_TipoOtros.mf_set_idTipoOtros();
	obj_TipoOtros.mf_set_nombre();

	obj_TipoOtros.mf_get_idTipoOtros();
	obj_TipoOtros.mf_get_nombre();
	*/
