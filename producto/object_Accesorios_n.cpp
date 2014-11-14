#include "object_Accesorios_n.h"

object_Accesorios_n::object_Accesorios_n()
{
	//file Accesorios
	//function construct_0
	//w!
}

object_Accesorios_n::object_Accesorios_n(_QSTR Producto_idProducto, _QSTR Color_idColor, _QSTR Tamanio_idTamanio, _QSTR Calidad_idCalidad, _QSTR Genero_idGenero)
{
	//file Accesorios
	//function construct_1
	//w!

	md_o_Producto_idProducto = Producto_idProducto;
	md_o_Color_idColor = Color_idColor;
	md_o_Tamanio_idTamanio = Tamanio_idTamanio;
	md_o_Calidad_idCalidad = Calidad_idCalidad;
	md_o_Genero_idGenero = Genero_idGenero;
}
object_Accesorios_n::object_Accesorios_n(_QSTR Color_idColor, _QSTR Tamanio_idTamanio, _QSTR Calidad_idCalidad, _QSTR Genero_idGenero)
{
	//file Accesorios
	//function construct_2
	//w!

	md_o_Color_idColor = Color_idColor;
	md_o_Tamanio_idTamanio = Tamanio_idTamanio;
	md_o_Calidad_idCalidad = Calidad_idCalidad;
	md_o_Genero_idGenero = Genero_idGenero;
}
object_Accesorios_n::~object_Accesorios_n()
{

}


void object_Accesorios_n::mf_set_Producto_idProducto(_QSTR Producto_idProducto)
{
	//function mf_set_Producto_idProducto
	//w!

	md_o_Producto_idProducto = Producto_idProducto;
}
void object_Accesorios_n::mf_set_Color_idColor(_QSTR Color_idColor)
{
	//function mf_set_Color_idColor
	//w!

	md_o_Color_idColor = Color_idColor;
}
void object_Accesorios_n::mf_set_Tamanio_idTamanio(_QSTR Tamanio_idTamanio)
{
	//function mf_set_Tamanio_idTamanio
	//w!

	md_o_Tamanio_idTamanio = Tamanio_idTamanio;
}
void object_Accesorios_n::mf_set_Calidad_idCalidad(_QSTR Calidad_idCalidad)
{
	//function mf_set_Calidad_idCalidad
	//w!

	md_o_Calidad_idCalidad = Calidad_idCalidad;
}
void object_Accesorios_n::mf_set_Genero_idGenero(_QSTR Genero_idGenero)
{
	//function mf_set_Genero_idGenero
	//w!

	md_o_Genero_idGenero = Genero_idGenero;
}

_QSTR object_Accesorios_n::mf_get_Producto_idProducto()
{
	//function mf_get_Producto_idProducto
	//w!

	return md_o_Producto_idProducto;
}
_QSTR object_Accesorios_n::mf_get_Color_idColor()
{
	//function mf_get_Color_idColor
	//w!

	return md_o_Color_idColor;
}
_QSTR object_Accesorios_n::mf_get_Tamanio_idTamanio()
{
	//function mf_get_Tamanio_idTamanio
	//w!

	return md_o_Tamanio_idTamanio;
}
_QSTR object_Accesorios_n::mf_get_Calidad_idCalidad()
{
	//function mf_get_Calidad_idCalidad
	//w!

	return md_o_Calidad_idCalidad;
}
_QSTR object_Accesorios_n::mf_get_Genero_idGenero()
{
	//function mf_get_Genero_idGenero
	//w!

	return md_o_Genero_idGenero;
}

bool object_Accesorios_n::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Accesorios WHERE Producto_idProducto = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_Producto_idProducto = query.value(0).toString();
		md_o_Color_idColor = query.value(1).toString();
		md_o_Tamanio_idTamanio = query.value(2).toString();
		md_o_Calidad_idCalidad = query.value(3).toString();
		md_o_Genero_idGenero = query.value(4).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Accesorios_n::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Accesorios(";
	str_query += "Producto_idProducto";
	str_query += ", Color_idColor";
	str_query += ", Tamanio_idTamanio";
	str_query += ", Calidad_idCalidad";
	str_query += ", Genero_idGenero";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_Producto_idProducto != "")
	{
		query.bindValue(integer++, md_o_Producto_idProducto);
	}
	else
		query.bindValue(integer++, "NULL");
	query.bindValue(integer++, md_o_Color_idColor);
	query.bindValue(integer++, md_o_Tamanio_idTamanio);
	query.bindValue(integer++, md_o_Calidad_idCalidad);
	query.bindValue(integer++, md_o_Genero_idGenero);

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

bool object_Accesorios_n::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Accesorios SET Color_idColor = ?, Tamanio_idTamanio = ?, Calidad_idCalidad = ?, Genero_idGenero = ? WHERE Producto_idProducto = ?");
	query.bindValue(0, md_o_Color_idColor);
	query.bindValue(1, md_o_Tamanio_idTamanio);
	query.bindValue(2, md_o_Calidad_idCalidad);
	query.bindValue(3, md_o_Genero_idGenero);
	query.bindValue(4, md_o_Producto_idProducto);

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

bool object_Accesorios_n::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Accesorios FROM Producto_idProducto = ?");
	query.bindValue(0, md_o_Producto_idProducto);

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

