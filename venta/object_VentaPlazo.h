#ifndef OBJECT_VENTAPLAZO_H
#define OBJECT_VENTAPLAZO_H

#include "share_include.h"

#define TABLE_NAME_VENTAPLAZO "VentaPlazo"
class object_VentaPlazo:public object_general
{

private:
_QSTR md_o_idVentaPlazo;
_QSTR md_o_Venta_idVenta;
_QSTR md_o_Venta_has_Tarjeta_idVenta_has_Tarjeta;
_QSTR md_o_Colaborador_idColaborador;
_QSTR md_o_Tienda_idTienda;
_QSTR md_o_montoEfectivo;
_QSTR md_o_montoTarjeta;
_QSTR md_o_fecha;
_QSTR md_o_numeroDocumento;
_QSTR md_o_serieDocumento;
_QSTR md_o_registro;

public:
object_VentaPlazo();
object_VentaPlazo(_QSTR idVentaPlazo, _QSTR Venta_idVenta, _QSTR Venta_has_Tarjeta_idVenta_has_Tarjeta, _QSTR Colaborador_idColaborador, _QSTR Tienda_idTienda, _QSTR montoEfectivo, _QSTR montoTarjeta, _QSTR fecha, _QSTR numeroDocumento, _QSTR serieDocumento, _QSTR registro);
object_VentaPlazo(_QSTR Venta_idVenta, _QSTR Venta_has_Tarjeta_idVenta_has_Tarjeta, _QSTR Colaborador_idColaborador, _QSTR Tienda_idTienda, _QSTR montoEfectivo, _QSTR montoTarjeta, _QSTR fecha, _QSTR numeroDocumento, _QSTR serieDocumento, _QSTR registro);

void mf_set_idVentaPlazo(_QSTR idVentaPlazo);
void mf_set_Venta_idVenta(_QSTR Venta_idVenta);
void mf_set_Venta_has_Tarjeta_idVenta_has_Tarjeta(_QSTR Venta_has_Tarjeta_idVenta_has_Tarjeta);
void mf_set_Colaborador_idColaborador(_QSTR Colaborador_idColaborador);
void mf_set_Tienda_idTienda(_QSTR Tienda_idTienda);
void mf_set_montoEfectivo(_QSTR montoEfectivo);
void mf_set_montoTarjeta(_QSTR montoTarjeta);
void mf_set_fecha(_QSTR fecha);
void mf_set_numeroDocumento(_QSTR numeroDocumento);
void mf_set_serieDocumento(_QSTR serieDocumento);
void mf_set_registro(_QSTR registro);

_QSTR mf_get_idVentaPlazo();
_QSTR mf_get_Venta_idVenta();
_QSTR mf_get_Venta_has_Tarjeta_idVenta_has_Tarjeta();
_QSTR mf_get_Colaborador_idColaborador();
_QSTR mf_get_Tienda_idTienda();
_QSTR mf_get_montoEfectivo();
_QSTR mf_get_montoTarjeta();
_QSTR mf_get_fecha();
_QSTR mf_get_numeroDocumento();
_QSTR mf_get_serieDocumento();
_QSTR mf_get_registro();

bool mf_load(_QSTR pk);
bool mf_add();
bool mf_update();
bool mf_remove();
vector<_QSTR> mf_listPk(_QSTR pk);
QSqlQueryModel* mf_show();
bool mf_verifyRegister(_QSTR);
bool mf_register(_QSTR);

~object_VentaPlazo();
};
#endif // OBJECT_VENTAPLAZO_H
/*
object_VentaPlazo obj_VentaPlazo;
obj_VentaPlazo.mf_set_idVentaPlazo();
obj_VentaPlazo.mf_set_Venta_idVenta();
obj_VentaPlazo.mf_set_Venta_has_Tarjeta_idVenta_has_Tarjeta();
obj_VentaPlazo.mf_set_Colaborador_idColaborador();
obj_VentaPlazo.mf_set_Tienda_idTienda();
obj_VentaPlazo.mf_set_montoEfectivo();
obj_VentaPlazo.mf_set_montoTarjeta();
obj_VentaPlazo.mf_set_fecha();
obj_VentaPlazo.mf_set_numeroDocumento();
obj_VentaPlazo.mf_set_serieDocumento();
obj_VentaPlazo.mf_set_registro();

obj_VentaPlazo.mf_get_idVentaPlazo();
obj_VentaPlazo.mf_get_Venta_idVenta();
obj_VentaPlazo.mf_get_Venta_has_Tarjeta_idVenta_has_Tarjeta();
obj_VentaPlazo.mf_get_Colaborador_idColaborador();
obj_VentaPlazo.mf_get_Tienda_idTienda();
obj_VentaPlazo.mf_get_montoEfectivo();
obj_VentaPlazo.mf_get_montoTarjeta();
obj_VentaPlazo.mf_get_fecha();
obj_VentaPlazo.mf_get_numeroDocumento();
obj_VentaPlazo.mf_get_serieDocumento();
obj_VentaPlazo.mf_get_registro();
*/
