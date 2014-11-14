#include "object_TipoOtros.h"

object_TipoOtros::object_TipoOtros()
{
	//file TipoOtros
	//function construct_0
	//w!
}

object_TipoOtros::object_TipoOtros(_QSTR idTipoOtros, _QSTR nombre)
{
	//file TipoOtros
	//function construct_1
	//w!

	md_o_idTipoOtros = idTipoOtros;
	md_o_nombre = nombre;
}
object_TipoOtros::object_TipoOtros(_QSTR nombre)
{
	//file TipoOtros
	//function construct_2
	//w!

	md_o_nombre = nombre;
}
object_TipoOtros::~object_TipoOtros()
{

}


void object_TipoOtros::mf_set_idTipoOtros(_QSTR idTipoOtros)
{
	//function mf_set_idTipoOtros
	//w!

	md_o_idTipoOtros = idTipoOtros;
}
void object_TipoOtros::mf_set_nombre(_QSTR nombre)
{
	//function mf_set_nombre
	//w!

	md_o_nombre = nombre;
}

_QSTR object_TipoOtros::mf_get_idTipoOtros()
{
	//function mf_get_idTipoOtros
	//w!

	return md_o_idTipoOtros;
}
_QSTR object_TipoOtros::mf_get_nombre()
{
	//function mf_get_nombre
	//w!

	return md_o_nombre;
}

bool object_TipoOtros::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM TipoOtros WHERE idTipoOtros = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idTipoOtros = query.value(0).toString();
		md_o_nombre = query.value(1).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_TipoOtros::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO TipoOtros(";
	str_query += "idTipoOtros";
	str_query += ", nombre";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idTipoOtros != "")
	{
		query.bindValue(integer++, md_o_idTipoOtros);
	}
	else
		query.bindValue(integer++, "NULL");
	query.bindValue(integer++, md_o_nombre);

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

bool object_TipoOtros::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE TipoOtros SET nombre = ? WHERE idTipoOtros = ?");
	query.bindValue(0, md_o_nombre);
	query.bindValue(1, md_o_idTipoOtros);

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

bool object_TipoOtros::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE TipoOtros FROM idTipoOtros = ?");
	query.bindValue(0, md_o_idTipoOtros);

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

