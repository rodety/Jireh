#ifndef OBJECT_COLOR_H
#define OBJECT_COLOR_H

#include "share_include.h"

#define TABLE_NAME_COLOR "Color"
class object_Color:public object_general
{

private:
	_QSTR md_o_idColor;
	_QSTR md_o_nombre;

public:
	object_Color();
	object_Color(_QSTR idColor, _QSTR nombre);
	object_Color(_QSTR nombre);

	void mf_set_idColor(_QSTR idColor);
	void mf_set_nombre(_QSTR nombre);

	_QSTR mf_get_idColor();
	_QSTR mf_get_nombre();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_Color();
};
#endif // OBJECT_COLOR_H
	/*
	object_Color obj_Color;
	obj_Color.mf_set_idColor();
	obj_Color.mf_set_nombre();

	obj_Color.mf_get_idColor();
	obj_Color.mf_get_nombre();
	*/
