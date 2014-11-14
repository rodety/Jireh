#include "object_TipoLente.h"

object_TipoLente::object_TipoLente()
{
	//file TipoLente
	//function construct_0
	//w!
}

object_TipoLente::object_TipoLente(_QSTR idTipoLente, _QSTR nombre)
{
	//file TipoLente
	//function construct_1
	//w!

	md_o_idTipoLente = idTipoLente;
	md_o_nombre = nombre;
}
object_TipoLente::object_TipoLente(_QSTR nombre)
{
	//file TipoLente
	//function construct_2
	//w!

	md_o_nombre = nombre;
}
object_TipoLente::~object_TipoLente()
{

}


void object_TipoLente::mf_set_idTipoLente(_QSTR idTipoLente)
{
	//function mf_set_idTipoLente
	//w!

	md_o_idTipoLente = idTipoLente;
}
void object_TipoLente::mf_set_nombre(_QSTR nombre)
{
	//function mf_set_nombre
	//w!

	md_o_nombre = nombre;
}

_QSTR object_TipoLente::mf_get_idTipoLente()
{
	//function mf_get_idTipoLente
	//w!

	return md_o_idTipoLente;
}
_QSTR object_TipoLente::mf_get_nombre()
{
	//function mf_get_nombre
	//w!

	return md_o_nombre;
}

bool object_TipoLente::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM TipoLente WHERE idTipoLente = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idTipoLente = query.value(0).toString();
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
bool object_TipoLente::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO TipoLente(";
	str_query += "idTipoLente";
	str_query += ", nombre";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idTipoLente != "")
	{
		query.bindValue(integer++, md_o_idTipoLente);
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

bool object_TipoLente::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE TipoLente SET nombre = ? WHERE idTipoLente = ?");
	query.bindValue(0, md_o_nombre);
	query.bindValue(1, md_o_idTipoLente);

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

bool object_TipoLente::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE TipoLente FROM idTipoLente = ?");
	query.bindValue(0, md_o_idTipoLente);

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

