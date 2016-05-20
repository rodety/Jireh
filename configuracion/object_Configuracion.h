#ifndef OBJECT_CONFIGURACION_H
#define OBJECT_CONFIGURACION_H

#include "share_include.h"

#define TABLE_NAME_CONFIGURACION "Configuracion"
class object_Configuracion:public object_general
{

private:
	_QSTR md_o_idConfiguracion;
	_QSTR md_o_Tienda_idTienda;
	_QSTR md_o_igv;
	_QSTR md_o_serieBoleta;
	_QSTR md_o_serieFactura;
	_QSTR md_o_serieCotizacion;
	_QSTR md_o_codigoPos;
        _QSTR md_o_autorizacion;
        _QSTR md_o_codigoDoc;

public:
	object_Configuracion();
	object_Configuracion(_QSTR idConfiguracion, _QSTR Tienda_idTienda, _QSTR igv, _QSTR serieBoleta, _QSTR serieFactura, _QSTR serieCotizacion, _QSTR codigoPos);
	object_Configuracion(_QSTR Tienda_idTienda, _QSTR igv, _QSTR serieBoleta, _QSTR serieFactura, _QSTR serieCotizacion, _QSTR codigoPos);

	void mf_set_idConfiguracion(_QSTR idConfiguracion);
	void mf_set_Tienda_idTienda(_QSTR Tienda_idTienda);
	void mf_set_igv(_QSTR igv);
	void mf_set_serieBoleta(_QSTR serieBoleta);
	void mf_set_serieFactura(_QSTR serieFactura);
	void mf_set_serieCotizacion(_QSTR serieCotizacion);
	void mf_set_codigoPos(_QSTR codigoPos);
        void mf_set_autorizacion(_QSTR autorizacion);
        void mf_set_codigoDoc(_QSTR codigoDoc);

	_QSTR mf_get_idConfiguracion();
	_QSTR mf_get_Tienda_idTienda();
	_QSTR mf_get_igv();
	_QSTR mf_get_serieBoleta();
	_QSTR mf_get_serieFactura();
	_QSTR mf_get_serieCotizacion();
	_QSTR mf_get_codigoPos();
        _QSTR mf_get_autorizacion();
        _QSTR mf_get_codigoDoc();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_Configuracion();
};
#endif // OBJECT_CONFIGURACION_H
	/*
	object_Configuracion obj_Configuracion;
	obj_Configuracion.mf_set_idConfiguracion();
	obj_Configuracion.mf_set_Tienda_idTienda();
	obj_Configuracion.mf_set_igv();
	obj_Configuracion.mf_set_serieBoleta();
	obj_Configuracion.mf_set_serieFactura();
	obj_Configuracion.mf_set_serieCotizacion();
	obj_Configuracion.mf_set_codigoPos();

	obj_Configuracion.mf_get_idConfiguracion();
	obj_Configuracion.mf_get_Tienda_idTienda();
	obj_Configuracion.mf_get_igv();
	obj_Configuracion.mf_get_serieBoleta();
	obj_Configuracion.mf_get_serieFactura();
	obj_Configuracion.mf_get_serieCotizacion();
	obj_Configuracion.mf_get_codigoPos();
	*/
