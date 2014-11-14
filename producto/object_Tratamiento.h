#ifndef OBJECT_TRATAMIENTO_H
#define OBJECT_TRATAMIENTO_H

#include "share_include.h"

#define TABLE_NAME_TRATAMIENTO "Tratamiento"
class object_Tratamiento:public object_general
{

private:
	_QSTR md_o_idTratamiento;
	_QSTR md_o_nombre;

public:
	object_Tratamiento();
	object_Tratamiento(_QSTR idTratamiento, _QSTR nombre);
	object_Tratamiento(_QSTR nombre);

	void mf_set_idTratamiento(_QSTR idTratamiento);
	void mf_set_nombre(_QSTR nombre);

	_QSTR mf_get_idTratamiento();
	_QSTR mf_get_nombre();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_Tratamiento();
};
#endif // OBJECT_TRATAMIENTO_H
	/*
	object_Tratamiento obj_Tratamiento;
	obj_Tratamiento.mf_set_idTratamiento();
	obj_Tratamiento.mf_set_nombre();

	obj_Tratamiento.mf_get_idTratamiento();
	obj_Tratamiento.mf_get_nombre();
	*/
