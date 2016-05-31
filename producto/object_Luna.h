#ifndef OBJECT_LUNA_H
#define OBJECT_LUNA_H

#include "share_include.h"

#define TABLE_NAME_LUNA "Luna"
class object_Luna:public object_general
{

private:
	_QSTR md_o_Producto_idProducto;
	_QSTR md_o_Diametro_idDiametro;
	_QSTR md_o_CalidadLuna_idCalidadLuna;
	_QSTR md_o_TipoLuna_idTipoLuna;
	_QSTR md_o_Tratamiento_idTratamiento;
	_QSTR md_o_valorInicial;
	_QSTR md_o_valorFinal;
	_QSTR md_o_precio;
	_QSTR md_o_cilindro;
	_QSTR md_o_cilindrof;
	_QSTR md_o_Lista_idLista;
	_QSTR md_o_Laboratorio_idLaboratorio;

public:
	object_Luna();
	object_Luna(_QSTR Producto_idProducto, _QSTR Diametro_idDiametro, _QSTR CalidadLuna_idCalidadLuna, _QSTR TipoLuna_idTipoLuna, _QSTR Tratamiento_idTratamiento, _QSTR valorInicial, _QSTR valorFinal, _QSTR precio, _QSTR cilindro, _QSTR cilindrof, _QSTR Lista_idLista, _QSTR Laboratorio_idLaboratorio);
	object_Luna(_QSTR Diametro_idDiametro, _QSTR CalidadLuna_idCalidadLuna, _QSTR TipoLuna_idTipoLuna, _QSTR Tratamiento_idTratamiento, _QSTR valorInicial, _QSTR valorFinal, _QSTR precio, _QSTR cilindro, _QSTR cilindrof, _QSTR Lista_idLista, _QSTR Laboratorio_idLaboratorio);

	void mf_set_Producto_idProducto(_QSTR Producto_idProducto);
	void mf_set_Diametro_idDiametro(_QSTR Diametro_idDiametro);
	void mf_set_CalidadLuna_idCalidadLuna(_QSTR CalidadLuna_idCalidadLuna);
	void mf_set_TipoLuna_idTipoLuna(_QSTR TipoLuna_idTipoLuna);
	void mf_set_Tratamiento_idTratamiento(_QSTR Tratamiento_idTratamiento);
	void mf_set_valorInicial(_QSTR valorInicial);
	void mf_set_valorFinal(_QSTR valorFinal);
	void mf_set_precio(_QSTR precio);
	void mf_set_cilindro(_QSTR cilindro);
	void mf_set_cilindrof(_QSTR cilindrof);
	void mf_set_Lista_idLista(_QSTR Lista_idLista);
	void mf_set_Laboratorio_idLaboratorio(_QSTR Laboratorio_idLaboratorio);

	_QSTR mf_get_Producto_idProducto();
	_QSTR mf_get_Diametro_idDiametro();
	_QSTR mf_get_CalidadLuna_idCalidadLuna();
	_QSTR mf_get_TipoLuna_idTipoLuna();
	_QSTR mf_get_Tratamiento_idTratamiento();
	_QSTR mf_get_valorInicial();
	_QSTR mf_get_valorFinal();
	_QSTR mf_get_precio();
	_QSTR mf_get_cilindro();
	_QSTR mf_get_cilindrof();
	_QSTR mf_get_Lista_idLista();
	_QSTR mf_get_Laboratorio_idLaboratorio();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();
        QSqlQueryModel* mf_show();
        QSqlQueryModel* mf_show_user();

        bool mf_updateDes(_QSTR d);

	~object_Luna();
};
#endif // OBJECT_LUNA_H
	/*
	object_Luna obj_Luna;
	obj_Luna.mf_set_Producto_idProducto();
	obj_Luna.mf_set_Diametro_idDiametro();
	obj_Luna.mf_set_CalidadLuna_idCalidadLuna();
	obj_Luna.mf_set_TipoLuna_idTipoLuna();
	obj_Luna.mf_set_Tratamiento_idTratamiento();
	obj_Luna.mf_set_valorInicial();
	obj_Luna.mf_set_valorFinal();
	obj_Luna.mf_set_precio();
	obj_Luna.mf_set_cilindro();
	obj_Luna.mf_set_cilindrof();
	obj_Luna.mf_set_Lista_idLista();
	obj_Luna.mf_set_Laboratorio_idLaboratorio();

	obj_Luna.mf_get_Producto_idProducto();
	obj_Luna.mf_get_Diametro_idDiametro();
	obj_Luna.mf_get_CalidadLuna_idCalidadLuna();
	obj_Luna.mf_get_TipoLuna_idTipoLuna();
	obj_Luna.mf_get_Tratamiento_idTratamiento();
	obj_Luna.mf_get_valorInicial();
	obj_Luna.mf_get_valorFinal();
	obj_Luna.mf_get_precio();
	obj_Luna.mf_get_cilindro();
	obj_Luna.mf_get_cilindrof();
	obj_Luna.mf_get_Lista_idLista();
	obj_Luna.mf_get_Laboratorio_idLaboratorio();
	*/
