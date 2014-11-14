#include "object_Tarjeta.h"

object_Tarjeta::object_Tarjeta()
{
	//file Tarjeta
	//function construct_0
	//w!
}

object_Tarjeta::object_Tarjeta(_QSTR idTarjeta, _QSTR nombre, _QSTR descripcion)
{
	//file Tarjeta
	//function construct_1
	//w!

	md_o_idTarjeta = idTarjeta;
	md_o_nombre = nombre;
	md_o_descripcion = descripcion;
}
object_Tarjeta::object_Tarjeta(_QSTR nombre, _QSTR descripcion)
{
	//file Tarjeta
	//function construct_2
	//w!

	md_o_nombre = nombre;
	md_o_descripcion = descripcion;
}
object_Tarjeta::~object_Tarjeta()
{

}


void object_Tarjeta::mf_set_idTarjeta(_QSTR idTarjeta)
{
	//function mf_set_idTarjeta
	//w!

	md_o_idTarjeta = idTarjeta;
}
void object_Tarjeta::mf_set_nombre(_QSTR nombre)
{
	//function mf_set_nombre
	//w!

	md_o_nombre = nombre;
}
void object_Tarjeta::mf_set_descripcion(_QSTR descripcion)
{
	//function mf_set_descripcion
	//w!

	md_o_descripcion = descripcion;
}

_QSTR object_Tarjeta::mf_get_idTarjeta()
{
	//function mf_get_idTarjeta
	//w!

	return md_o_idTarjeta;
}
_QSTR object_Tarjeta::mf_get_nombre()
{
	//function mf_get_nombre
	//w!

	return md_o_nombre;
}
_QSTR object_Tarjeta::mf_get_descripcion()
{
	//function mf_get_descripcion
	//w!

	return md_o_descripcion;
}

bool object_Tarjeta::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Tarjeta WHERE idTarjeta = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idTarjeta = query.value(0).toString();
		md_o_nombre = query.value(1).toString();
		md_o_descripcion = query.value(2).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Tarjeta::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Tarjeta(";
	str_query += "idTarjeta";
	str_query += ", nombre";
	str_query += ", descripcion";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idTarjeta != "")
	{
		query.bindValue(integer++, md_o_idTarjeta);
	}
	else
        query.bindValue(integer++, NULL);
	query.bindValue(integer++, md_o_nombre);
	query.bindValue(integer++, md_o_descripcion);

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

bool object_Tarjeta::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Tarjeta SET nombre = ?, descripcion = ? WHERE idTarjeta = ?");
	query.bindValue(0, md_o_nombre);
	query.bindValue(1, md_o_descripcion);
	query.bindValue(2, md_o_idTarjeta);

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

bool object_Tarjeta::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Tarjeta FROM idTarjeta = ?");
	query.bindValue(0, md_o_idTarjeta);

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

QSqlQueryModel* object_Tarjeta::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idTarjeta,nombre FROM Tarjeta");
    return model;
}

bool object_Tarjeta::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idTarjeta FROM Tarjeta WHERE nombre=?");
    query.bindValue(0,md_o_nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            md_o_idTarjeta=query.value(0).toString();            
            return true;
        }
        return false;
    }
    else
        return false;
}
