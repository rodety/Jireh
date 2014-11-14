#include "object_Calidad.h"

object_Calidad::object_Calidad()
{
	//file Calidad
	//function construct_0
	//w!
}

object_Calidad::object_Calidad(_QSTR idCalidad, _QSTR nombre)
{
	//file Calidad
	//function construct_1
	//w!

	md_o_idCalidad = idCalidad;
	md_o_nombre = nombre;
}
object_Calidad::object_Calidad(_QSTR nombre)
{
	//file Calidad
	//function construct_2
	//w!

	md_o_nombre = nombre;
}
object_Calidad::~object_Calidad()
{

}


void object_Calidad::mf_set_idCalidad(_QSTR idCalidad)
{
	//function mf_set_idCalidad
	//w!

	md_o_idCalidad = idCalidad;
}
void object_Calidad::mf_set_nombre(_QSTR nombre)
{
	//function mf_set_nombre
	//w!

	md_o_nombre = nombre;
}

_QSTR object_Calidad::mf_get_idCalidad()
{
	//function mf_get_idCalidad
	//w!

	return md_o_idCalidad;
}
_QSTR object_Calidad::mf_get_nombre()
{
	//function mf_get_nombre
	//w!

	return md_o_nombre;
}

bool object_Calidad::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Calidad WHERE idCalidad = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idCalidad = query.value(0).toString();
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
bool object_Calidad::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Calidad(";
	str_query += "idCalidad";
	str_query += ", nombre";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idCalidad != "")
	{
		query.bindValue(integer++, md_o_idCalidad);
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

bool object_Calidad::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Calidad SET nombre = ? WHERE idCalidad = ?");
	query.bindValue(0, md_o_nombre);
	query.bindValue(1, md_o_idCalidad);

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

bool object_Calidad::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Calidad FROM idCalidad = ?");
	query.bindValue(0, md_o_idCalidad);

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

