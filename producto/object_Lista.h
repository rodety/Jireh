#ifndef OBJECT_LISTA_H
#define OBJECT_LISTA_H

#include "share_include.h"

#define TABLE_NAME_LISTA "Lista"
class object_Lista:public object_general
{

private:
	_QSTR md_o_idLista;
	_QSTR md_o_nombre;

public:
	object_Lista();
	object_Lista(_QSTR idLista, _QSTR nombre);
	object_Lista(_QSTR nombre);

	void mf_set_idLista(_QSTR idLista);
	void mf_set_nombre(_QSTR nombre);

	_QSTR mf_get_idLista();
	_QSTR mf_get_nombre();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();
        static QSqlQueryModel* mostrarId();

	~object_Lista();
};
#endif // OBJECT_LISTA_H
	/*
	object_Lista obj_Lista;
	obj_Lista.mf_set_idLista();
	obj_Lista.mf_set_nombre();

	obj_Lista.mf_get_idLista();
	obj_Lista.mf_get_nombre();
	*/
