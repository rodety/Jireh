#ifndef OBJECT_LABORATORIO_H
#define OBJECT_LABORATORIO_H

#include "share_include.h"

#define TABLE_NAME_LABORATORIO "Laboratorio"
class object_Laboratorio:public object_general
{

private:
	_QSTR md_o_idLaboratorio;
	_QSTR md_o_nombre;

public:
	object_Laboratorio();
	object_Laboratorio(_QSTR idLaboratorio, _QSTR nombre);
	object_Laboratorio(_QSTR nombre);

	void mf_set_idLaboratorio(_QSTR idLaboratorio);
	void mf_set_nombre(_QSTR nombre);

	_QSTR mf_get_idLaboratorio();
	_QSTR mf_get_nombre();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();
        static QSqlQueryModel* mostrarId();

	~object_Laboratorio();
};
#endif // OBJECT_LABORATORIO_H
	/*
	object_Laboratorio obj_Laboratorio;
	obj_Laboratorio.mf_set_idLaboratorio();
	obj_Laboratorio.mf_set_nombre();

	obj_Laboratorio.mf_get_idLaboratorio();
	obj_Laboratorio.mf_get_nombre();
	*/
