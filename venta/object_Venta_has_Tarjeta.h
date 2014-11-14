#ifndef OBJECT_VENTA_HAS_TARJETA_H
#define OBJECT_VENTA_HAS_TARJETA_H

#include "share_include.h"

#define TABLE_NAME_VENTA_HAS_TARJETA "Venta_has_Tarjeta"
class object_Venta_has_Tarjeta:public object_general
{

private:
	_QSTR md_o_idVenta_has_Tarjeta;
	_QSTR md_o_Tarjeta_idTarjeta;
	_QSTR md_o_id;
	_QSTR md_o_tarjeta;
	_QSTR md_o_referencia;
	_QSTR md_o_lote;
	_QSTR md_o_fecha;
	_QSTR md_o_monto;
	_QSTR md_o_codigoAfiliacion;
	_QSTR md_o_nombre_pagador;
        _QSTR md_o_lastIdVenta_has_Tarjeta;

public:
	object_Venta_has_Tarjeta();
	object_Venta_has_Tarjeta(_QSTR idVenta_has_Tarjeta, _QSTR Tarjeta_idTarjeta, _QSTR id, _QSTR tarjeta, _QSTR referencia, _QSTR lote, _QSTR fecha, _QSTR monto, _QSTR codigoAfiliacion, _QSTR nombre_pagador);
	object_Venta_has_Tarjeta(_QSTR Tarjeta_idTarjeta, _QSTR id, _QSTR tarjeta, _QSTR referencia, _QSTR lote, _QSTR fecha, _QSTR monto, _QSTR codigoAfiliacion, _QSTR nombre_pagador);

	void mf_set_idVenta_has_Tarjeta(_QSTR idVenta_has_Tarjeta);
	void mf_set_Tarjeta_idTarjeta(_QSTR Tarjeta_idTarjeta);
	void mf_set_id(_QSTR id);
	void mf_set_tarjeta(_QSTR tarjeta);
	void mf_set_referencia(_QSTR referencia);
	void mf_set_lote(_QSTR lote);
	void mf_set_fecha(_QSTR fecha);
	void mf_set_monto(_QSTR monto);
	void mf_set_codigoAfiliacion(_QSTR codigoAfiliacion);
	void mf_set_nombre_pagador(_QSTR nombre_pagador);
        void mf_set_lastIdVenta_has_Tarjeta(_QSTR lastIdVenta_has_Tarjeta);

	_QSTR mf_get_idVenta_has_Tarjeta();
	_QSTR mf_get_Tarjeta_idTarjeta();
	_QSTR mf_get_id();
	_QSTR mf_get_tarjeta();
	_QSTR mf_get_referencia();
	_QSTR mf_get_lote();
	_QSTR mf_get_fecha();
	_QSTR mf_get_monto();
	_QSTR mf_get_codigoAfiliacion();
	_QSTR mf_get_nombre_pagador();
        _QSTR mf_get_lastIdVenta_has_Tarjeta();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();

	~object_Venta_has_Tarjeta();
};
#endif // OBJECT_VENTA_HAS_TARJETA_H
	/*
	object_Venta_has_Tarjeta obj_Venta_has_Tarjeta;
	obj_Venta_has_Tarjeta.mf_set_idVenta_has_Tarjeta();
	obj_Venta_has_Tarjeta.mf_set_Tarjeta_idTarjeta();
	obj_Venta_has_Tarjeta.mf_set_id();
	obj_Venta_has_Tarjeta.mf_set_tarjeta();
	obj_Venta_has_Tarjeta.mf_set_referencia();
	obj_Venta_has_Tarjeta.mf_set_lote();
	obj_Venta_has_Tarjeta.mf_set_fecha();
	obj_Venta_has_Tarjeta.mf_set_monto();
	obj_Venta_has_Tarjeta.mf_set_codigoAfiliacion();
	obj_Venta_has_Tarjeta.mf_set_nombre_pagador();

	obj_Venta_has_Tarjeta.mf_get_idVenta_has_Tarjeta();
	obj_Venta_has_Tarjeta.mf_get_Tarjeta_idTarjeta();
	obj_Venta_has_Tarjeta.mf_get_id();
	obj_Venta_has_Tarjeta.mf_get_tarjeta();
	obj_Venta_has_Tarjeta.mf_get_referencia();
	obj_Venta_has_Tarjeta.mf_get_lote();
	obj_Venta_has_Tarjeta.mf_get_fecha();
	obj_Venta_has_Tarjeta.mf_get_monto();
	obj_Venta_has_Tarjeta.mf_get_codigoAfiliacion();
	obj_Venta_has_Tarjeta.mf_get_nombre_pagador();
	*/
