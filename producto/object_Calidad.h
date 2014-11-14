#ifndef OBJECT_CALIDAD_H
#define OBJECT_CALIDAD_H

#include "share_include.h"

#define TABLE_NAME_CALIDAD "Calidad"
class object_Calidad:public object_general
{

private:
	_QSTR md_o_idCalidad;
	_QSTR md_o_nombre;

public:
	object_Calidad();
	object_Calidad(_QSTR idCalidad, _QSTR nombre);
	object_Calidad(_QSTR nombre);

	void mf_set_idCalidad(_QSTR idCalidad);
	void mf_set_nombre(_QSTR nombre);

	_QSTR mf_get_idCalidad();
	_QSTR mf_get_nombre();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_Calidad();
};
#endif // OBJECT_CALIDAD_H
	/*
	object_Calidad obj_Calidad;
	obj_Calidad.mf_set_idCalidad();
	obj_Calidad.mf_set_nombre();

	obj_Calidad.mf_get_idCalidad();
	obj_Calidad.mf_get_nombre();
	*/
