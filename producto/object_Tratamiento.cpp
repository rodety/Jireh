#include "object_Tratamiento.h"

object_Tratamiento::object_Tratamiento()
{
	//file Tratamiento
	//function construct_0
	//w!
}

object_Tratamiento::object_Tratamiento(_QSTR idTratamiento, _QSTR nombre)
{
	//file Tratamiento
	//function construct_1
	//w!

	md_o_idTratamiento = idTratamiento;
	md_o_nombre = nombre;
}
object_Tratamiento::object_Tratamiento(_QSTR nombre)
{
	//file Tratamiento
	//function construct_2
	//w!

	md_o_nombre = nombre;
}
object_Tratamiento::~object_Tratamiento()
{

}


void object_Tratamiento::mf_set_idTratamiento(_QSTR idTratamiento)
{
	//function mf_set_idTratamiento
	//w!

	md_o_idTratamiento = idTratamiento;
}
void object_Tratamiento::mf_set_nombre(_QSTR nombre)
{
	//function mf_set_nombre
	//w!

	md_o_nombre = nombre;
}

_QSTR object_Tratamiento::mf_get_idTratamiento()
{
	//function mf_get_idTratamiento
	//w!

	return md_o_idTratamiento;
}
_QSTR object_Tratamiento::mf_get_nombre()
{
	//function mf_get_nombre
	//w!

	return md_o_nombre;
}

bool object_Tratamiento::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Tratamiento WHERE idTratamiento = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idTratamiento = query.value(0).toString();
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
bool object_Tratamiento::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Tratamiento(";
	str_query += "idTratamiento";
	str_query += ", nombre";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idTratamiento != "")
	{
		query.bindValue(integer++, md_o_idTratamiento);
	}
	else
        query.bindValue(integer++, NULL);
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

bool object_Tratamiento::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Tratamiento SET nombre = ? WHERE idTratamiento = ?");
	query.bindValue(0, md_o_nombre);
	query.bindValue(1, md_o_idTratamiento);

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

bool object_Tratamiento::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Tratamiento FROM idTratamiento = ?");
	query.bindValue(0, md_o_idTratamiento);

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

