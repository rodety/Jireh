#ifndef OBJECT_VENTA_H
#define OBJECT_VENTA_H

#include "share_include.h"

#define TABLE_NAME_VENTA "Venta"
class object_Venta:public object_general
{

private:
	_QSTR md_o_idVenta;
	_QSTR md_o_fechaPreVenta;
	_QSTR md_o_fechaCancelacion;
	_QSTR md_o_serieDocumento;
	_QSTR md_o_numeroDocumento;
	_QSTR md_o_formaPago;
	_QSTR md_o_codigoTransaccion;
	_QSTR md_o_plazo;
	_QSTR md_o_montoTotal;
	_QSTR md_o_fechaEntrega;
	_QSTR md_o_montoAdelanto;
	_QSTR md_o_Entregado;
	_QSTR md_o_Anulado;
	_QSTR md_o_pendiente;
	_QSTR md_o_Tienda_idTienda;
	_QSTR md_o_Cliente_idCliente;
	_QSTR md_o_Colaborador_idColaborador;
    _QSTR md_o_tipoDocumento;
    _QSTR md_o_lastIdVenta;
    _QSTR md_o_dateFrom;
    _QSTR md_o_dateTo;

public:
	object_Venta();
	object_Venta(_QSTR idVenta, _QSTR fechaPreVenta, _QSTR fechaCancelacion, _QSTR serieDocumento, _QSTR numeroDocumento, _QSTR formaPago, _QSTR codigoTransaccion, _QSTR plazo, _QSTR montoTotal, _QSTR fechaEntrega, _QSTR montoAdelanto, _QSTR Entregado, _QSTR Anulado, _QSTR pendiente, _QSTR Tienda_idTienda, _QSTR Cliente_idCliente, _QSTR Colaborador_idColaborador, _QSTR tipoDocumento);
	object_Venta(_QSTR fechaPreVenta, _QSTR fechaCancelacion, _QSTR serieDocumento, _QSTR numeroDocumento, _QSTR formaPago, _QSTR codigoTransaccion, _QSTR plazo, _QSTR montoTotal, _QSTR fechaEntrega, _QSTR montoAdelanto, _QSTR Entregado, _QSTR Anulado, _QSTR pendiente, _QSTR Tienda_idTienda, _QSTR Cliente_idCliente, _QSTR Colaborador_idColaborador, _QSTR tipoDocumento);

	void mf_set_idVenta(_QSTR idVenta);
	void mf_set_fechaPreVenta(_QSTR fechaPreVenta);
	void mf_set_fechaCancelacion(_QSTR fechaCancelacion);
	void mf_set_serieDocumento(_QSTR serieDocumento);
	void mf_set_numeroDocumento(_QSTR numeroDocumento);
	void mf_set_formaPago(_QSTR formaPago);
	void mf_set_codigoTransaccion(_QSTR codigoTransaccion);
	void mf_set_plazo(_QSTR plazo);
	void mf_set_montoTotal(_QSTR montoTotal);
	void mf_set_fechaEntrega(_QSTR fechaEntrega);
	void mf_set_montoAdelanto(_QSTR montoAdelanto);
	void mf_set_Entregado(_QSTR Entregado);
	void mf_set_Anulado(_QSTR Anulado);
	void mf_set_pendiente(_QSTR pendiente);
	void mf_set_Tienda_idTienda(_QSTR Tienda_idTienda);
	void mf_set_Cliente_idCliente(_QSTR Cliente_idCliente);
	void mf_set_Colaborador_idColaborador(_QSTR Colaborador_idColaborador);
	void mf_set_tipoDocumento(_QSTR tipoDocumento);
    void mf_set_dateFrom(_QSTR dateFrom);
    void mf_set_dateTo(_QSTR dateTo);

	_QSTR mf_get_idVenta();
	_QSTR mf_get_fechaPreVenta();
	_QSTR mf_get_fechaCancelacion();
	_QSTR mf_get_serieDocumento();
	_QSTR mf_get_numeroDocumento();
	_QSTR mf_get_formaPago();
	_QSTR mf_get_codigoTransaccion();
	_QSTR mf_get_plazo();
	_QSTR mf_get_montoTotal();
	_QSTR mf_get_fechaEntrega();
	_QSTR mf_get_montoAdelanto();
	_QSTR mf_get_Entregado();
	_QSTR mf_get_Anulado();
	_QSTR mf_get_pendiente();
	_QSTR mf_get_Tienda_idTienda();
	_QSTR mf_get_Cliente_idCliente();
	_QSTR mf_get_Colaborador_idColaborador();
	_QSTR mf_get_tipoDocumento();
        _QSTR mf_get_lastIdVenta();

	bool mf_load(_QSTR pk);
	bool mf_add();
	bool mf_update();
	bool mf_remove();
        QSqlQueryModel* mf_show(int tipo);
        bool mf_update_register(_QSTR pk,_QSTR flag);
        bool mf_update_anulado(_QSTR pk,_QSTR estado);


	~object_Venta();
};
#endif // OBJECT_VENTA_H
	/*
	object_Venta obj_Venta;
	obj_Venta.mf_set_idVenta();
	obj_Venta.mf_set_fechaPreVenta();
	obj_Venta.mf_set_fechaCancelacion();
	obj_Venta.mf_set_serieDocumento();
	obj_Venta.mf_set_numeroDocumento();
	obj_Venta.mf_set_formaPago();
	obj_Venta.mf_set_codigoTransaccion();
	obj_Venta.mf_set_plazo();
	obj_Venta.mf_set_montoTotal();
	obj_Venta.mf_set_fechaEntrega();
	obj_Venta.mf_set_montoAdelanto();
	obj_Venta.mf_set_Entregado();
	obj_Venta.mf_set_Anulado();
	obj_Venta.mf_set_pendiente();
	obj_Venta.mf_set_Tienda_idTienda();
	obj_Venta.mf_set_Cliente_idCliente();
	obj_Venta.mf_set_Colaborador_idColaborador();
	obj_Venta.mf_set_tipoDocumento();

	obj_Venta.mf_get_idVenta();
	obj_Venta.mf_get_fechaPreVenta();
	obj_Venta.mf_get_fechaCancelacion();
	obj_Venta.mf_get_serieDocumento();
	obj_Venta.mf_get_numeroDocumento();
	obj_Venta.mf_get_formaPago();
	obj_Venta.mf_get_codigoTransaccion();
	obj_Venta.mf_get_plazo();
	obj_Venta.mf_get_montoTotal();
	obj_Venta.mf_get_fechaEntrega();
	obj_Venta.mf_get_montoAdelanto();
	obj_Venta.mf_get_Entregado();
	obj_Venta.mf_get_Anulado();
	obj_Venta.mf_get_pendiente();
	obj_Venta.mf_get_Tienda_idTienda();
	obj_Venta.mf_get_Cliente_idCliente();
	obj_Venta.mf_get_Colaborador_idColaborador();
	obj_Venta.mf_get_tipoDocumento();
	*/
