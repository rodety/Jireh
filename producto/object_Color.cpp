#include "object_Color.h"

object_Color::object_Color()
{
	//file Color
	//function construct_0
	//w!
}

object_Color::object_Color(_QSTR idColor, _QSTR nombre)
{
	//file Color
	//function construct_1
	//w!

	md_o_idColor = idColor;
	md_o_nombre = nombre;
}
object_Color::object_Color(_QSTR nombre)
{
	//file Color
	//function construct_2
	//w!

	md_o_nombre = nombre;
}
object_Color::~object_Color()
{

}


void object_Color::mf_set_idColor(_QSTR idColor)
{
	//function mf_set_idColor
	//w!

	md_o_idColor = idColor;
}
void object_Color::mf_set_nombre(_QSTR nombre)
{
	//function mf_set_nombre
	//w!

	md_o_nombre = nombre;
}

_QSTR object_Color::mf_get_idColor()
{
	//function mf_get_idColor
	//w!

	return md_o_idColor;
}
_QSTR object_Color::mf_get_nombre()
{
	//function mf_get_nombre
	//w!

	return md_o_nombre;
}

bool object_Color::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Color WHERE idColor = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idColor = query.value(0).toString();
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
bool object_Color::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Color(";
	str_query += "idColor";
	str_query += ", nombre";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idColor != "")
	{
		query.bindValue(integer++, md_o_idColor);
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

bool object_Color::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Color SET nombre = ? WHERE idColor = ?");
	query.bindValue(0, md_o_nombre);
	query.bindValue(1, md_o_idColor);

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

bool object_Color::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Color FROM idColor = ?");
	query.bindValue(0, md_o_idColor);

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

