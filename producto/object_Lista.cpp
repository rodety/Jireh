#include "object_Lista.h"

object_Lista::object_Lista()
{
	//file Lista
	//function construct_0
	//w!
}

object_Lista::object_Lista(_QSTR idLista, _QSTR nombre)
{
	//file Lista
	//function construct_1
	//w!

	md_o_idLista = idLista;
	md_o_nombre = nombre;
}
object_Lista::object_Lista(_QSTR nombre)
{
	//file Lista
	//function construct_2
	//w!

	md_o_nombre = nombre;
}
object_Lista::~object_Lista()
{

}


void object_Lista::mf_set_idLista(_QSTR idLista)
{
	//function mf_set_idLista
	//w!

	md_o_idLista = idLista;
}
void object_Lista::mf_set_nombre(_QSTR nombre)
{
	//function mf_set_nombre
	//w!

	md_o_nombre = nombre;
}

_QSTR object_Lista::mf_get_idLista()
{
	//function mf_get_idLista
	//w!

	return md_o_idLista;
}
_QSTR object_Lista::mf_get_nombre()
{
	//function mf_get_nombre
	//w!

	return md_o_nombre;
}

bool object_Lista::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Lista WHERE idLista = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idLista = query.value(0).toString();
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
bool object_Lista::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Lista(";
	str_query += "idLista";
	str_query += ", nombre";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idLista != "")
	{
		query.bindValue(integer++, md_o_idLista);
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

bool object_Lista::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Lista SET nombre = ? WHERE idLista = ?");
	query.bindValue(0, md_o_nombre);
	query.bindValue(1, md_o_idLista);

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

bool object_Lista::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Lista FROM idLista = ?");
	query.bindValue(0, md_o_idLista);

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

QSqlQueryModel * object_Lista::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idLista, nombre FROM Lista");
    return model;
}

