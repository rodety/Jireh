#include "object_Marca.h"

object_Marca::object_Marca()
{
	//file Marca
	//function construct_0
	//w!
}

object_Marca::object_Marca(_QSTR idMarca, _QSTR nombre)
{
	//file Marca
	//function construct_1
	//w!

	md_o_idMarca = idMarca;
	md_o_nombre = nombre;
}
object_Marca::object_Marca(_QSTR nombre)
{
	//file Marca
	//function construct_2
	//w!

	md_o_nombre = nombre;
}
object_Marca::~object_Marca()
{

}


void object_Marca::mf_set_idMarca(_QSTR idMarca)
{
	//function mf_set_idMarca
	//w!

	md_o_idMarca = idMarca;
}
void object_Marca::mf_set_nombre(_QSTR nombre)
{
	//function mf_set_nombre
	//w!

	md_o_nombre = nombre;
}

_QSTR object_Marca::mf_get_idMarca()
{
	//function mf_get_idMarca
	//w!

	return md_o_idMarca;
}
_QSTR object_Marca::mf_get_nombre()
{
	//function mf_get_nombre
	//w!

	return md_o_nombre;
}

bool object_Marca::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Marca WHERE idMarca = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idMarca = query.value(0).toString();
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
bool object_Marca::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Marca(";
	str_query += "idMarca";
	str_query += ", nombre";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idMarca != "")
	{
		query.bindValue(integer++, md_o_idMarca);
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

bool object_Marca::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Marca SET nombre = ? WHERE idMarca = ?");
	query.bindValue(0, md_o_nombre);
	query.bindValue(1, md_o_idMarca);

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

bool object_Marca::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Marca FROM idMarca = ?");
	query.bindValue(0, md_o_idMarca);

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

