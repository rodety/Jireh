#ifndef OBJECT_TIPOLENTE_H
#define OBJECT_TIPOLENTE_H

#include "share_include.h"

#define TABLE_NAME_TIPOLENTE "TipoLente"
class object_TipoLente:public object_general
{

private:
	_QSTR md_o_idTipoLente;
	_QSTR md_o_nombre;

public:
	object_TipoLente();
	object_TipoLente(_QSTR idTipoLente, _QSTR nombre);
	object_TipoLente(_QSTR nombre);

	void mf_set_idTipoLente(_QSTR idTipoLente);
	void mf_set_nombre(_QSTR nombre);

	_QSTR mf_get_idTipoLente();
	_QSTR mf_get_nombre();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_TipoLente();
};
#endif // OBJECT_TIPOLENTE_H
	/*
	object_TipoLente obj_TipoLente;
	obj_TipoLente.mf_set_idTipoLente();
	obj_TipoLente.mf_set_nombre();

	obj_TipoLente.mf_get_idTipoLente();
	obj_TipoLente.mf_get_nombre();
	*/
