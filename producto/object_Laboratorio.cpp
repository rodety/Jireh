#include "object_Laboratorio.h"

object_Laboratorio::object_Laboratorio()
{
	//file Laboratorio
	//function construct_0
	//w!
}

object_Laboratorio::object_Laboratorio(_QSTR idLaboratorio, _QSTR nombre)
{
	//file Laboratorio
	//function construct_1
	//w!

	md_o_idLaboratorio = idLaboratorio;
	md_o_nombre = nombre;
}
object_Laboratorio::object_Laboratorio(_QSTR nombre)
{
	//file Laboratorio
	//function construct_2
	//w!

	md_o_nombre = nombre;
}
object_Laboratorio::~object_Laboratorio()
{

}


void object_Laboratorio::mf_set_idLaboratorio(_QSTR idLaboratorio)
{
	//function mf_set_idLaboratorio
	//w!

	md_o_idLaboratorio = idLaboratorio;
}
void object_Laboratorio::mf_set_nombre(_QSTR nombre)
{
	//function mf_set_nombre
	//w!

	md_o_nombre = nombre;
}

_QSTR object_Laboratorio::mf_get_idLaboratorio()
{
	//function mf_get_idLaboratorio
	//w!

	return md_o_idLaboratorio;
}
_QSTR object_Laboratorio::mf_get_nombre()
{
	//function mf_get_nombre
	//w!

	return md_o_nombre;
}

bool object_Laboratorio::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Laboratorio WHERE idLaboratorio = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idLaboratorio = query.value(0).toString();
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
bool object_Laboratorio::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Laboratorio(";
	str_query += "idLaboratorio";
	str_query += ", nombre";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idLaboratorio != "")
	{
		query.bindValue(integer++, md_o_idLaboratorio);
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

bool object_Laboratorio::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Laboratorio SET nombre = ? WHERE idLaboratorio = ?");
	query.bindValue(0, md_o_nombre);
	query.bindValue(1, md_o_idLaboratorio);

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

bool object_Laboratorio::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Laboratorio FROM idLaboratorio = ?");
	query.bindValue(0, md_o_idLaboratorio);

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

QSqlQueryModel * object_Laboratorio::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idLaboratorio, nombre FROM Laboratorio");
    return model;
}

