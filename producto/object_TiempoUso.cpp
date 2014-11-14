#include "object_TiempoUso.h"

object_TiempoUso::object_TiempoUso()
{
	//file TiempoUso
	//function construct_0
	//w!
}

object_TiempoUso::object_TiempoUso(_QSTR idTiempoUso, _QSTR valor)
{
	//file TiempoUso
	//function construct_1
	//w!

	md_o_idTiempoUso = idTiempoUso;
	md_o_valor = valor;
}
object_TiempoUso::object_TiempoUso(_QSTR valor)
{
	//file TiempoUso
	//function construct_2
	//w!

	md_o_valor = valor;
}
object_TiempoUso::~object_TiempoUso()
{

}


void object_TiempoUso::mf_set_idTiempoUso(_QSTR idTiempoUso)
{
	//function mf_set_idTiempoUso
	//w!

	md_o_idTiempoUso = idTiempoUso;
}
void object_TiempoUso::mf_set_valor(_QSTR valor)
{
	//function mf_set_valor
	//w!

	md_o_valor = valor;
}

_QSTR object_TiempoUso::mf_get_idTiempoUso()
{
	//function mf_get_idTiempoUso
	//w!

	return md_o_idTiempoUso;
}
_QSTR object_TiempoUso::mf_get_valor()
{
	//function mf_get_valor
	//w!

	return md_o_valor;
}

bool object_TiempoUso::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM TiempoUso WHERE idTiempoUso = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idTiempoUso = query.value(0).toString();
		md_o_valor = query.value(1).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_TiempoUso::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO TiempoUso(";
	str_query += "idTiempoUso";
	str_query += ", valor";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idTiempoUso != "")
	{
		query.bindValue(integer++, md_o_idTiempoUso);
	}
	else
		query.bindValue(integer++, "NULL");
	query.bindValue(integer++, md_o_valor);

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

bool object_TiempoUso::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE TiempoUso SET valor = ? WHERE idTiempoUso = ?");
	query.bindValue(0, md_o_valor);
	query.bindValue(1, md_o_idTiempoUso);

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

bool object_TiempoUso::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE TiempoUso FROM idTiempoUso = ?");
	query.bindValue(0, md_o_idTiempoUso);

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

