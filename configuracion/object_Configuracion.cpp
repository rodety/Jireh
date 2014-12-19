#include "object_Configuracion.h"

object_Configuracion::object_Configuracion()
{
	//file Configuracion
	//function construct_0
	//w!
}

object_Configuracion::object_Configuracion(_QSTR idConfiguracion, _QSTR Tienda_idTienda, _QSTR igv, _QSTR serieBoleta, _QSTR serieFactura, _QSTR serieCotizacion, _QSTR codigoPos)
{
	//file Configuracion
	//function construct_1
	//w!

	md_o_idConfiguracion = idConfiguracion;
	md_o_Tienda_idTienda = Tienda_idTienda;
	md_o_igv = igv;
	md_o_serieBoleta = serieBoleta;
	md_o_serieFactura = serieFactura;
	md_o_serieCotizacion = serieCotizacion;
	md_o_codigoPos = codigoPos;
}
object_Configuracion::object_Configuracion(_QSTR Tienda_idTienda, _QSTR igv, _QSTR serieBoleta, _QSTR serieFactura, _QSTR serieCotizacion, _QSTR codigoPos)
{
	//file Configuracion
	//function construct_2
	//w!

	md_o_Tienda_idTienda = Tienda_idTienda;
	md_o_igv = igv;
	md_o_serieBoleta = serieBoleta;
	md_o_serieFactura = serieFactura;
	md_o_serieCotizacion = serieCotizacion;
	md_o_codigoPos = codigoPos;
}
object_Configuracion::~object_Configuracion()
{

}


void object_Configuracion::mf_set_idConfiguracion(_QSTR idConfiguracion)
{
	//function mf_set_idConfiguracion
	//w!

	md_o_idConfiguracion = idConfiguracion;
}
void object_Configuracion::mf_set_Tienda_idTienda(_QSTR Tienda_idTienda)
{
	//function mf_set_Tienda_idTienda
	//w!

	md_o_Tienda_idTienda = Tienda_idTienda;
}
void object_Configuracion::mf_set_igv(_QSTR igv)
{
	//function mf_set_igv
	//w!

	md_o_igv = igv;
}
void object_Configuracion::mf_set_serieBoleta(_QSTR serieBoleta)
{
	//function mf_set_serieBoleta
	//w!

	md_o_serieBoleta = serieBoleta;
}
void object_Configuracion::mf_set_serieFactura(_QSTR serieFactura)
{
	//function mf_set_serieFactura
	//w!

	md_o_serieFactura = serieFactura;
}
void object_Configuracion::mf_set_serieCotizacion(_QSTR serieCotizacion)
{
	//function mf_set_serieCotizacion
	//w!

	md_o_serieCotizacion = serieCotizacion;
}
void object_Configuracion::mf_set_codigoPos(_QSTR codigoPos)
{
	//function mf_set_codigoPos
	//w!

	md_o_codigoPos = codigoPos;
}

_QSTR object_Configuracion::mf_get_idConfiguracion()
{
	//function mf_get_idConfiguracion
	//w!

	return md_o_idConfiguracion;
}
_QSTR object_Configuracion::mf_get_Tienda_idTienda()
{
	//function mf_get_Tienda_idTienda
	//w!

	return md_o_Tienda_idTienda;
}
_QSTR object_Configuracion::mf_get_igv()
{
	//function mf_get_igv
	//w!

	return md_o_igv;
}
_QSTR object_Configuracion::mf_get_serieBoleta()
{
	//function mf_get_serieBoleta
	//w!

	return md_o_serieBoleta;
}
_QSTR object_Configuracion::mf_get_serieFactura()
{
	//function mf_get_serieFactura
	//w!

	return md_o_serieFactura;
}
_QSTR object_Configuracion::mf_get_serieCotizacion()
{
	//function mf_get_serieCotizacion
	//w!

	return md_o_serieCotizacion;
}
_QSTR object_Configuracion::mf_get_codigoPos()
{
	//function mf_get_codigoPos
	//w!

	return md_o_codigoPos;
}

bool object_Configuracion::mf_load(_QSTR pk)
{

    //Busqueda por IdTienda

	QSqlQuery query;

    query.prepare("SELECT * FROM Configuracion WHERE Tienda_idTienda = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idConfiguracion = query.value(0).toString();
		md_o_Tienda_idTienda = query.value(1).toString();
		md_o_igv = query.value(2).toString();
		md_o_serieBoleta = query.value(3).toString();
		md_o_serieFactura = query.value(4).toString();
		md_o_serieCotizacion = query.value(5).toString();
		md_o_codigoPos = query.value(6).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Configuracion::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Configuracion(";
	str_query += "idConfiguracion";
	str_query += ", Tienda_idTienda";
	str_query += ", igv";
	str_query += ", serieBoleta";
	str_query += ", serieFactura";
	str_query += ", serieCotizacion";
	str_query += ", codigoPos";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idConfiguracion != "")
	{
		query.bindValue(integer++, md_o_idConfiguracion);
	}
	else
        query.bindValue(integer++, "NULL");
	query.bindValue(integer++, md_o_Tienda_idTienda);
	query.bindValue(integer++, md_o_igv);
	query.bindValue(integer++, md_o_serieBoleta);
	query.bindValue(integer++, md_o_serieFactura);
	query.bindValue(integer++, md_o_serieCotizacion);
	query.bindValue(integer++, md_o_codigoPos);

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

bool object_Configuracion::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Configuracion SET Tienda_idTienda = ?, igv = ?, serieBoleta = ?, serieFactura = ?, serieCotizacion = ?, codigoPos = ? WHERE idConfiguracion = ?");
	query.bindValue(0, md_o_Tienda_idTienda);
	query.bindValue(1, md_o_igv);
	query.bindValue(2, md_o_serieBoleta);
	query.bindValue(3, md_o_serieFactura);
	query.bindValue(4, md_o_serieCotizacion);
	query.bindValue(5, md_o_codigoPos);
	query.bindValue(6, md_o_idConfiguracion);

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

bool object_Configuracion::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Configuracion FROM idConfiguracion = ?");
	query.bindValue(0, md_o_idConfiguracion);

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

