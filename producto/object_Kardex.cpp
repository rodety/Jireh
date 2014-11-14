#include "object_Kardex.h"

object_Kardex::object_Kardex()
{
	//file Kardex
	//function construct_0
	//w!
}

object_Kardex::object_Kardex(_QSTR idKardex, _QSTR Producto_idProducto, _QSTR fecha, _QSTR detalle, _QSTR cant, _QSTR costo_unit, _QSTR costo_total, _QSTR costo_promedio, _QSTR saldo_total, _QSTR tipo)
{
	//file Kardex
	//function construct_1
	//w!

	md_o_idKardex = idKardex;
	md_o_Producto_idProducto = Producto_idProducto;
	md_o_fecha = fecha;
	md_o_detalle = detalle;
	md_o_cant = cant;
	md_o_costo_unit = costo_unit;
	md_o_costo_total = costo_total;
	md_o_costo_promedio = costo_promedio;
	md_o_saldo_total = saldo_total;
	md_o_tipo = tipo;
}
object_Kardex::object_Kardex(_QSTR Producto_idProducto, _QSTR fecha, _QSTR detalle, _QSTR cant, _QSTR costo_unit, _QSTR costo_total, _QSTR costo_promedio, _QSTR saldo_total, _QSTR tipo)
{
	//file Kardex
	//function construct_2
	//w!

	md_o_Producto_idProducto = Producto_idProducto;
	md_o_fecha = fecha;
	md_o_detalle = detalle;
	md_o_cant = cant;
	md_o_costo_unit = costo_unit;
	md_o_costo_total = costo_total;
	md_o_costo_promedio = costo_promedio;
	md_o_saldo_total = saldo_total;
	md_o_tipo = tipo;
}
object_Kardex::~object_Kardex()
{

}


void object_Kardex::mf_set_idKardex(_QSTR idKardex)
{
	//function mf_set_idKardex
	//w!

	md_o_idKardex = idKardex;
}
void object_Kardex::mf_set_Producto_idProducto(_QSTR Producto_idProducto)
{
	//function mf_set_Producto_idProducto
	//w!

    md_o_Producto_idProducto = Producto_idProducto;
}

void object_Kardex::mf_set_Colaborador_idColaborador(_QSTR Colaborador_idColaborador)
{
    md_o_Colaborador_idColaborador = Colaborador_idColaborador;
}
void object_Kardex::mf_set_fecha(_QSTR fecha)
{
	//function mf_set_fecha
	//w!

	md_o_fecha = fecha;
}
void object_Kardex::mf_set_detalle(_QSTR detalle)
{
	//function mf_set_detalle
	//w!

	md_o_detalle = detalle;
}
void object_Kardex::mf_set_cant(_QSTR cant)
{
	//function mf_set_cant
	//w!

	md_o_cant = cant;
}
void object_Kardex::mf_set_costo_unit(_QSTR costo_unit)
{
	//function mf_set_costo_unit
	//w!

	md_o_costo_unit = costo_unit;
}
void object_Kardex::mf_set_costo_total(_QSTR costo_total)
{
	//function mf_set_costo_total
	//w!

	md_o_costo_total = costo_total;
}
void object_Kardex::mf_set_costo_promedio(_QSTR costo_promedio)
{
	//function mf_set_costo_promedio
	//w!

	md_o_costo_promedio = costo_promedio;
}
void object_Kardex::mf_set_saldo_total(_QSTR saldo_total)
{
	//function mf_set_saldo_total
	//w!

	md_o_saldo_total = saldo_total;
}
void object_Kardex::mf_set_tipo(_QSTR tipo)
{
	//function mf_set_tipo
	//w!

	md_o_tipo = tipo;
}

_QSTR object_Kardex::mf_get_idKardex()
{
	//function mf_get_idKardex
	//w!

	return md_o_idKardex;
}
_QSTR object_Kardex::mf_get_Producto_idProducto()
{
	//function mf_get_Producto_idProducto
	//w!

    return md_o_Producto_idProducto;
}

_QSTR object_Kardex::mf_get_Colaborador_idColaborador()
{
    return md_o_Colaborador_idColaborador;
}
_QSTR object_Kardex::mf_get_fecha()
{
	//function mf_get_fecha
	//w!

	return md_o_fecha;
}
_QSTR object_Kardex::mf_get_detalle()
{
	//function mf_get_detalle
	//w!

	return md_o_detalle;
}
_QSTR object_Kardex::mf_get_cant()
{
	//function mf_get_cant
	//w!

	return md_o_cant;
}
_QSTR object_Kardex::mf_get_costo_unit()
{
	//function mf_get_costo_unit
	//w!

	return md_o_costo_unit;
}
_QSTR object_Kardex::mf_get_costo_total()
{
	//function mf_get_costo_total
	//w!

	return md_o_costo_total;
}
_QSTR object_Kardex::mf_get_costo_promedio()
{
	//function mf_get_costo_promedio
	//w!
    QSqlQuery query;
    query.prepare("select costo_promedio from Kardex where Producto_idProducto = ? order by idKardex desc limit 1");
    query.bindValue(0,md_o_Producto_idProducto);
    query.exec();

    if(query.next())
        md_o_costo_promedio = query.value(0).toString();
    else
        md_o_costo_promedio = "0";

	return md_o_costo_promedio;
}
_QSTR object_Kardex::mf_get_saldo_total()
{
	//function mf_get_saldo_total
	//w!

	return md_o_saldo_total;
}
_QSTR object_Kardex::mf_get_tipo()
{
	//function mf_get_tipo
	//w!

	return md_o_tipo;
}

bool object_Kardex::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Kardex WHERE idKardex = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idKardex = query.value(0).toString();
		md_o_Producto_idProducto = query.value(1).toString();
		md_o_fecha = query.value(2).toString();
		md_o_detalle = query.value(3).toString();
		md_o_cant = query.value(4).toString();
		md_o_costo_unit = query.value(5).toString();
		md_o_costo_total = query.value(6).toString();
		md_o_costo_promedio = query.value(7).toString();
		md_o_saldo_total = query.value(8).toString();
		md_o_tipo = query.value(9).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Kardex::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

    QString str_query = "INSERT INTO Kardex(";

    str_query += "Producto_idProducto";
    str_query += ", Colaborador_idColaborador";
	str_query += ", fecha";
	str_query += ", detalle";
	str_query += ", cant";
	str_query += ", costo_unit";
	str_query += ", costo_total";
	str_query += ", costo_promedio";
	str_query += ", saldo_total";
	str_query += ", tipo";
    str_query += ") VALUES( '";
    str_query += md_o_Producto_idProducto;
    str_query += "',' "+md_o_Colaborador_idColaborador;
    str_query += "',' "+md_o_fecha;
    str_query += "',' "+md_o_detalle;
    str_query += "',' "+md_o_cant;
    str_query += "',' "+md_o_costo_unit;
    str_query += "',' "+md_o_costo_total;
    str_query += "',' "+md_o_costo_promedio;
    str_query += "',' "+md_o_saldo_total;
    str_query += "',' "+md_o_tipo;
    str_query += "')";
    if(query.exec(str_query))
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

bool object_Kardex::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Kardex SET Producto_idProducto = ?, fecha = ?, detalle = ?, cant = ?, costo_unit = ?, costo_total = ?, costo_promedio = ?, saldo_total = ?, tipo = ? WHERE idKardex = ?");
	query.bindValue(0, md_o_Producto_idProducto);
	query.bindValue(1, md_o_fecha);
	query.bindValue(2, md_o_detalle);
	query.bindValue(3, md_o_cant);
	query.bindValue(4, md_o_costo_unit);
	query.bindValue(5, md_o_costo_total);
	query.bindValue(6, md_o_costo_promedio);
	query.bindValue(7, md_o_saldo_total);
	query.bindValue(8, md_o_tipo);
	query.bindValue(9, md_o_idKardex);

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

bool object_Kardex::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Kardex FROM idKardex = ?");
	query.bindValue(0, md_o_idKardex);

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

QSqlQueryModel* object_Kardex::mf_show()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    string str_query = "SELECT ";
    str_query += "k.idKardex";
    str_query += ", k.fecha";
    str_query += ", k.detalle";
    str_query += ", k.cant";
    str_query += ", k.costo_unit";
    str_query += ", k.costo_total";
    str_query += ", k.costo_promedio";
    str_query += ", k.saldo_total";
    str_query += ", CONCAT(c.nombres,', ',c.primer_apellido) as 'Colaborador'";
    str_query += ", IF(k.tipo = 1, 'Entrada', 'Salida') as 'Tipo'";
    str_query += " FROM Kardex k, Colaborador c WHERE Producto_idProducto = ";
    str_query += md_o_Producto_idProducto.toStdString();
    str_query += " AND c.idColaborador = k.Colaborador_idColaborador order by k.idKardex";

    model->setQuery(str_query.c_str());
    return model;
}
