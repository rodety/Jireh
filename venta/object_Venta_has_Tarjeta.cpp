#include "object_Venta_has_Tarjeta.h"

object_Venta_has_Tarjeta::object_Venta_has_Tarjeta()
{
	//file Venta_has_Tarjeta
	//function construct_0
	//w!
}

object_Venta_has_Tarjeta::object_Venta_has_Tarjeta(_QSTR idVenta_has_Tarjeta, _QSTR Tarjeta_idTarjeta, _QSTR id, _QSTR tarjeta, _QSTR referencia, _QSTR lote, _QSTR fecha, _QSTR monto, _QSTR codigoAfiliacion, _QSTR nombre_pagador)
{
	//file Venta_has_Tarjeta
	//function construct_1
	//w!

	md_o_idVenta_has_Tarjeta = idVenta_has_Tarjeta;
	md_o_Tarjeta_idTarjeta = Tarjeta_idTarjeta;
	md_o_id = id;
	md_o_tarjeta = tarjeta;
	md_o_referencia = referencia;
	md_o_lote = lote;
	md_o_fecha = fecha;
	md_o_monto = monto;
	md_o_codigoAfiliacion = codigoAfiliacion;
	md_o_nombre_pagador = nombre_pagador;
}
object_Venta_has_Tarjeta::object_Venta_has_Tarjeta(_QSTR Tarjeta_idTarjeta, _QSTR id, _QSTR tarjeta, _QSTR referencia, _QSTR lote, _QSTR fecha, _QSTR monto, _QSTR codigoAfiliacion, _QSTR nombre_pagador)
{
	//file Venta_has_Tarjeta
	//function construct_2
	//w!

	md_o_Tarjeta_idTarjeta = Tarjeta_idTarjeta;
	md_o_id = id;
	md_o_tarjeta = tarjeta;
	md_o_referencia = referencia;
	md_o_lote = lote;
	md_o_fecha = fecha;
	md_o_monto = monto;
	md_o_codigoAfiliacion = codigoAfiliacion;
	md_o_nombre_pagador = nombre_pagador;
}
object_Venta_has_Tarjeta::~object_Venta_has_Tarjeta()
{

}


void object_Venta_has_Tarjeta::mf_set_idVenta_has_Tarjeta(_QSTR idVenta_has_Tarjeta)
{
	//function mf_set_idVenta_has_Tarjeta
	//w!

	md_o_idVenta_has_Tarjeta = idVenta_has_Tarjeta;
}
void object_Venta_has_Tarjeta::mf_set_Tarjeta_idTarjeta(_QSTR Tarjeta_idTarjeta)
{
	//function mf_set_Tarjeta_idTarjeta
	//w!

	md_o_Tarjeta_idTarjeta = Tarjeta_idTarjeta;
}
void object_Venta_has_Tarjeta::mf_set_id(_QSTR id)
{
	//function mf_set_id
	//w!

	md_o_id = id;
}
void object_Venta_has_Tarjeta::mf_set_tarjeta(_QSTR tarjeta)
{
	//function mf_set_tarjeta
	//w!

	md_o_tarjeta = tarjeta;
}
void object_Venta_has_Tarjeta::mf_set_referencia(_QSTR referencia)
{
	//function mf_set_referencia
	//w!

	md_o_referencia = referencia;
}
void object_Venta_has_Tarjeta::mf_set_lote(_QSTR lote)
{
	//function mf_set_lote
	//w!

	md_o_lote = lote;
}
void object_Venta_has_Tarjeta::mf_set_fecha(_QSTR fecha)
{
	//function mf_set_fecha
	//w!

	md_o_fecha = fecha;
}
void object_Venta_has_Tarjeta::mf_set_monto(_QSTR monto)
{
	//function mf_set_monto
	//w!

	md_o_monto = monto;
}
void object_Venta_has_Tarjeta::mf_set_codigoAfiliacion(_QSTR codigoAfiliacion)
{
	//function mf_set_codigoAfiliacion
	//w!

	md_o_codigoAfiliacion = codigoAfiliacion;
}
void object_Venta_has_Tarjeta::mf_set_nombre_pagador(_QSTR nombre_pagador)
{
	//function mf_set_nombre_pagador
	//w!

	md_o_nombre_pagador = nombre_pagador;
}
void object_Venta_has_Tarjeta::mf_set_lastIdVenta_has_Tarjeta(_QSTR lastIdVenta_has_Tarjeta)
{
        //function mf_set_codigoAfiliacion
        //w!

        md_o_lastIdVenta_has_Tarjeta = lastIdVenta_has_Tarjeta;
}

_QSTR object_Venta_has_Tarjeta::mf_get_idVenta_has_Tarjeta()
{
	//function mf_get_idVenta_has_Tarjeta
	//w!

	return md_o_idVenta_has_Tarjeta;
}
_QSTR object_Venta_has_Tarjeta::mf_get_Tarjeta_idTarjeta()
{
	//function mf_get_Tarjeta_idTarjeta
	//w!

	return md_o_Tarjeta_idTarjeta;
}
_QSTR object_Venta_has_Tarjeta::mf_get_id()
{
	//function mf_get_id
	//w!

	return md_o_id;
}
_QSTR object_Venta_has_Tarjeta::mf_get_tarjeta()
{
	//function mf_get_tarjeta
	//w!

	return md_o_tarjeta;
}
_QSTR object_Venta_has_Tarjeta::mf_get_referencia()
{
	//function mf_get_referencia
	//w!

	return md_o_referencia;
}
_QSTR object_Venta_has_Tarjeta::mf_get_lote()
{
	//function mf_get_lote
	//w!

	return md_o_lote;
}
_QSTR object_Venta_has_Tarjeta::mf_get_fecha()
{
	//function mf_get_fecha
	//w!

	return md_o_fecha;
}
_QSTR object_Venta_has_Tarjeta::mf_get_monto()
{
	//function mf_get_monto
	//w!

	return md_o_monto;
}
_QSTR object_Venta_has_Tarjeta::mf_get_codigoAfiliacion()
{
	//function mf_get_codigoAfiliacion
	//w!

	return md_o_codigoAfiliacion;
}
_QSTR object_Venta_has_Tarjeta::mf_get_nombre_pagador()
{
	//function mf_get_nombre_pagador
	//w!

	return md_o_nombre_pagador;
}
_QSTR object_Venta_has_Tarjeta::mf_get_lastIdVenta_has_Tarjeta()
{
    return md_o_lastIdVenta_has_Tarjeta;
}

bool object_Venta_has_Tarjeta::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Venta_has_Tarjeta WHERE idVenta_has_Tarjeta = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idVenta_has_Tarjeta = query.value(0).toString();
		md_o_Tarjeta_idTarjeta = query.value(1).toString();
		md_o_id = query.value(2).toString();
		md_o_tarjeta = query.value(3).toString();
		md_o_referencia = query.value(4).toString();
		md_o_lote = query.value(5).toString();
		md_o_fecha = query.value(6).toString();
		md_o_monto = query.value(7).toString();
		md_o_codigoAfiliacion = query.value(8).toString();
		md_o_nombre_pagador = query.value(9).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Venta_has_Tarjeta::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Venta_has_Tarjeta(";
        str_query += " Tarjeta_idTarjeta";
	str_query += ", id";
	str_query += ", tarjeta";
	str_query += ", referencia";
	str_query += ", lote";
	str_query += ", fecha";
	str_query += ", monto";
	str_query += ", codigoAfiliacion";
	str_query += ", nombre_pagador";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;

	query.bindValue(integer++, md_o_Tarjeta_idTarjeta);
	query.bindValue(integer++, md_o_id);
	query.bindValue(integer++, md_o_tarjeta);
	query.bindValue(integer++, md_o_referencia);
	query.bindValue(integer++, md_o_lote);
	query.bindValue(integer++, md_o_fecha);
	query.bindValue(integer++, md_o_monto);
	query.bindValue(integer++, md_o_codigoAfiliacion);
	query.bindValue(integer++, md_o_nombre_pagador);

	if(query.exec())
	{
		//state OK
		//w!
            query.exec("SELECT LAST_INSERT_ID()");
            query.next();
            md_o_lastIdVenta_has_Tarjeta = query.value(0).toString();
		return true;

	}else{
		//state FAILED
		//w!

		return false;
	}
}

bool object_Venta_has_Tarjeta::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Venta_has_Tarjeta SET Tarjeta_idTarjeta = ?, id = ?, tarjeta = ?, referencia = ?, lote = ?, fecha = ?, monto = ?, codigoAfiliacion = ?, nombre_pagador = ? WHERE idVenta_has_Tarjeta = ?");
	query.bindValue(0, md_o_Tarjeta_idTarjeta);
	query.bindValue(1, md_o_id);
	query.bindValue(2, md_o_tarjeta);
	query.bindValue(3, md_o_referencia);
	query.bindValue(4, md_o_lote);
	query.bindValue(5, md_o_fecha);
	query.bindValue(6, md_o_monto);
	query.bindValue(7, md_o_codigoAfiliacion);
	query.bindValue(8, md_o_nombre_pagador);
	query.bindValue(9, md_o_idVenta_has_Tarjeta);

	if(query.exec())
	{
		//state OK
		//w!

		return true;

	}else{
		//state FAILED
		//w!

		return false;
	}
}

bool object_Venta_has_Tarjeta::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Venta_has_Tarjeta FROM idVenta_has_Tarjeta = ?");
	query.bindValue(0, md_o_idVenta_has_Tarjeta);

	if(query.exec())
	{
		//state OK
		//w!

		return true;

	}else{
	//state FAILED
	//w!

		return false;
	}
}

