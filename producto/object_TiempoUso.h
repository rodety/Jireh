#ifndef OBJECT_TIEMPOUSO_H
#define OBJECT_TIEMPOUSO_H

#include "share_include.h"

#define TABLE_NAME_TIEMPOUSO "TiempoUso"
class object_TiempoUso:public object_general
{

private:
	_QSTR md_o_idTiempoUso;
	_QSTR md_o_valor;

public:
	object_TiempoUso();
	object_TiempoUso(_QSTR idTiempoUso, _QSTR valor);
	object_TiempoUso(_QSTR valor);

	void mf_set_idTiempoUso(_QSTR idTiempoUso);
	void mf_set_valor(_QSTR valor);

	_QSTR mf_get_idTiempoUso();
	_QSTR mf_get_valor();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_TiempoUso();
};
#endif // OBJECT_TIEMPOUSO_H
	/*
	object_TiempoUso obj_TiempoUso;
	obj_TiempoUso.mf_set_idTiempoUso();
	obj_TiempoUso.mf_set_valor();

	obj_TiempoUso.mf_get_idTiempoUso();
	obj_TiempoUso.mf_get_valor();
	*/
