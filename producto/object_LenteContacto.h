#ifndef OBJECT_LENTECONTACTO_H
#define OBJECT_LENTECONTACTO_H

#include "share_include.h"

#define TABLE_NAME_LENTECONTACTO "LenteContacto"
class object_LenteContacto:public object_general
{

private:
	_QSTR md_o_Producto_idProducto;
	_QSTR md_o_presentacion;
	_QSTR md_o_tinteVisibilidad;
	_QSTR md_o_contenidoAcuoso;
	_QSTR md_o_diseno;
	_QSTR md_o_TipoLente_idTipoLente;
	_QSTR md_o_Potencia_idPotencia;
	_QSTR md_o_CurvaBase_idCurvaBase;
	_QSTR md_o_Diametro_idDiametro;
	_QSTR md_o_TiempoUso_idTiempoUso;
	_QSTR md_o_Material_idMaterial;

public:
	object_LenteContacto();
	object_LenteContacto(_QSTR Producto_idProducto, _QSTR presentacion, _QSTR tinteVisibilidad, _QSTR contenidoAcuoso, _QSTR diseno, _QSTR TipoLente_idTipoLente, _QSTR Potencia_idPotencia, _QSTR CurvaBase_idCurvaBase, _QSTR Diametro_idDiametro, _QSTR TiempoUso_idTiempoUso, _QSTR Material_idMaterial);
	object_LenteContacto(_QSTR presentacion, _QSTR tinteVisibilidad, _QSTR contenidoAcuoso, _QSTR diseno, _QSTR TipoLente_idTipoLente, _QSTR Potencia_idPotencia, _QSTR CurvaBase_idCurvaBase, _QSTR Diametro_idDiametro, _QSTR TiempoUso_idTiempoUso, _QSTR Material_idMaterial);

	void mf_set_Producto_idProducto(_QSTR Producto_idProducto);
	void mf_set_presentacion(_QSTR presentacion);
	void mf_set_tinteVisibilidad(_QSTR tinteVisibilidad);
	void mf_set_contenidoAcuoso(_QSTR contenidoAcuoso);
	void mf_set_diseno(_QSTR diseno);
	void mf_set_TipoLente_idTipoLente(_QSTR TipoLente_idTipoLente);
	void mf_set_Potencia_idPotencia(_QSTR Potencia_idPotencia);
	void mf_set_CurvaBase_idCurvaBase(_QSTR CurvaBase_idCurvaBase);
	void mf_set_Diametro_idDiametro(_QSTR Diametro_idDiametro);
	void mf_set_TiempoUso_idTiempoUso(_QSTR TiempoUso_idTiempoUso);
	void mf_set_Material_idMaterial(_QSTR Material_idMaterial);

	_QSTR mf_get_Producto_idProducto();
	_QSTR mf_get_presentacion();
	_QSTR mf_get_tinteVisibilidad();
	_QSTR mf_get_contenidoAcuoso();
	_QSTR mf_get_diseno();
	_QSTR mf_get_TipoLente_idTipoLente();
	_QSTR mf_get_Potencia_idPotencia();
	_QSTR mf_get_CurvaBase_idCurvaBase();
	_QSTR mf_get_Diametro_idDiametro();
	_QSTR mf_get_TiempoUso_idTiempoUso();
	_QSTR mf_get_Material_idMaterial();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_LenteContacto();
        QSqlQueryModel* mf_show(object_Producto tmp);
        QSqlQueryModel* mf_show_search(QString id);
};
#endif // OBJECT_LENTECONTACTO_H
	/*
	object_LenteContacto obj_LenteContacto;
	obj_LenteContacto.mf_set_Producto_idProducto();
	obj_LenteContacto.mf_set_presentacion();
	obj_LenteContacto.mf_set_tinteVisibilidad();
	obj_LenteContacto.mf_set_contenidoAcuoso();
	obj_LenteContacto.mf_set_diseno();
	obj_LenteContacto.mf_set_TipoLente_idTipoLente();
	obj_LenteContacto.mf_set_Potencia_idPotencia();
	obj_LenteContacto.mf_set_CurvaBase_idCurvaBase();
	obj_LenteContacto.mf_set_Diametro_idDiametro();
	obj_LenteContacto.mf_set_TiempoUso_idTiempoUso();
	obj_LenteContacto.mf_set_Material_idMaterial();

	obj_LenteContacto.mf_get_Producto_idProducto();
	obj_LenteContacto.mf_get_presentacion();
	obj_LenteContacto.mf_get_tinteVisibilidad();
	obj_LenteContacto.mf_get_contenidoAcuoso();
	obj_LenteContacto.mf_get_diseno();
	obj_LenteContacto.mf_get_TipoLente_idTipoLente();
	obj_LenteContacto.mf_get_Potencia_idPotencia();
	obj_LenteContacto.mf_get_CurvaBase_idCurvaBase();
	obj_LenteContacto.mf_get_Diametro_idDiametro();
	obj_LenteContacto.mf_get_TiempoUso_idTiempoUso();
	obj_LenteContacto.mf_get_Material_idMaterial();
	*/
