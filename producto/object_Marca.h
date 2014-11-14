#ifndef OBJECT_MARCA_H
#define OBJECT_MARCA_H

#include "share_include.h"

#define TABLE_NAME_MARCA "Marca"
class object_Marca:public object_general
{

private:
	_QSTR md_o_idMarca;
	_QSTR md_o_nombre;

public:
	object_Marca();
	object_Marca(_QSTR idMarca, _QSTR nombre);
	object_Marca(_QSTR nombre);

	void mf_set_idMarca(_QSTR idMarca);
	void mf_set_nombre(_QSTR nombre);

	_QSTR mf_get_idMarca();
	_QSTR mf_get_nombre();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_Marca();
};
#endif // OBJECT_MARCA_H
	/*
	object_Marca obj_Marca;
	obj_Marca.mf_set_idMarca();
	obj_Marca.mf_set_nombre();

	obj_Marca.mf_get_idMarca();
	obj_Marca.mf_get_nombre();
	*/
