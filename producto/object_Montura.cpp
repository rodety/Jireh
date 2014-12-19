#include "object_Montura.h"

object_Montura::object_Montura()
{
	//file Montura
	//function construct_0
	//w!
}

object_Montura::object_Montura(_QSTR Producto_idProducto, _QSTR Forma_idForma, _QSTR Color_idColor, _QSTR Tamanio_idTamanio, _QSTR Calidad_idCalidad, _QSTR Genero_idGenero)
{
	//file Montura
	//function construct_1
	//w!

	md_o_Producto_idProducto = Producto_idProducto;
	md_o_Forma_idForma = Forma_idForma;
	md_o_Color_idColor = Color_idColor;
	md_o_Tamanio_idTamanio = Tamanio_idTamanio;
	md_o_Calidad_idCalidad = Calidad_idCalidad;
	md_o_Genero_idGenero = Genero_idGenero;
}
object_Montura::object_Montura(_QSTR Forma_idForma, _QSTR Color_idColor, _QSTR Tamanio_idTamanio, _QSTR Calidad_idCalidad, _QSTR Genero_idGenero)
{
	//file Montura
	//function construct_2
	//w!

	md_o_Forma_idForma = Forma_idForma;
	md_o_Color_idColor = Color_idColor;
	md_o_Tamanio_idTamanio = Tamanio_idTamanio;
	md_o_Calidad_idCalidad = Calidad_idCalidad;
	md_o_Genero_idGenero = Genero_idGenero;
}
object_Montura::~object_Montura()
{

}


void object_Montura::mf_set_Producto_idProducto(_QSTR Producto_idProducto)
{
	//function mf_set_Producto_idProducto
	//w!

	md_o_Producto_idProducto = Producto_idProducto;
}
void object_Montura::mf_set_Forma_idForma(_QSTR Forma_idForma)
{
	//function mf_set_Forma_idForma
	//w!

	md_o_Forma_idForma = Forma_idForma;
}
void object_Montura::mf_set_Color_idColor(_QSTR Color_idColor)
{
	//function mf_set_Color_idColor
	//w!

	md_o_Color_idColor = Color_idColor;
}
void object_Montura::mf_set_Tamanio_idTamanio(_QSTR Tamanio_idTamanio)
{
	//function mf_set_Tamanio_idTamanio
	//w!

	md_o_Tamanio_idTamanio = Tamanio_idTamanio;
}
void object_Montura::mf_set_Calidad_idCalidad(_QSTR Calidad_idCalidad)
{
	//function mf_set_Calidad_idCalidad
	//w!

	md_o_Calidad_idCalidad = Calidad_idCalidad;
}
void object_Montura::mf_set_Genero_idGenero(_QSTR Genero_idGenero)
{
	//function mf_set_Genero_idGenero
	//w!

	md_o_Genero_idGenero = Genero_idGenero;
}

_QSTR object_Montura::mf_get_Producto_idProducto()
{
	//function mf_get_Producto_idProducto
	//w!

	return md_o_Producto_idProducto;
}
_QSTR object_Montura::mf_get_Forma_idForma()
{
	//function mf_get_Forma_idForma
	//w!

	return md_o_Forma_idForma;
}
_QSTR object_Montura::mf_get_Color_idColor()
{
	//function mf_get_Color_idColor
	//w!

	return md_o_Color_idColor;
}
_QSTR object_Montura::mf_get_Tamanio_idTamanio()
{
	//function mf_get_Tamanio_idTamanio
	//w!

	return md_o_Tamanio_idTamanio;
}
_QSTR object_Montura::mf_get_Calidad_idCalidad()
{
	//function mf_get_Calidad_idCalidad
	//w!

	return md_o_Calidad_idCalidad;
}
_QSTR object_Montura::mf_get_Genero_idGenero()
{
	//function mf_get_Genero_idGenero
	//w!

	return md_o_Genero_idGenero;
}

bool object_Montura::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Montura WHERE Producto_idProducto = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_Producto_idProducto = query.value(0).toString();
		md_o_Forma_idForma = query.value(1).toString();
		md_o_Color_idColor = query.value(2).toString();
		md_o_Tamanio_idTamanio = query.value(3).toString();
		md_o_Calidad_idCalidad = query.value(4).toString();
		md_o_Genero_idGenero = query.value(5).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Montura::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Montura(";
	str_query += "Producto_idProducto";
	str_query += ", Forma_idForma";
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
	query.bindValue(integer++, md_o_Forma_idForma);
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

bool object_Montura::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Montura SET Forma_idForma = ?, Color_idColor = ?, Tamanio_idTamanio = ?, Calidad_idCalidad = ?, Genero_idGenero = ? WHERE Producto_idProducto = ?");
	query.bindValue(0, md_o_Forma_idForma);
	query.bindValue(1, md_o_Color_idColor);
	query.bindValue(2, md_o_Tamanio_idTamanio);
	query.bindValue(3, md_o_Calidad_idCalidad);
	query.bindValue(4, md_o_Genero_idGenero);
	query.bindValue(5, md_o_Producto_idProducto);

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

bool object_Montura::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Montura FROM Producto_idProducto = ?");
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

QSqlQueryModel* object_Montura::mf_show(object_Producto myProducto)
{
    QSqlQueryModel* model=new QSqlQueryModel;
//AQUI ESTA LA PENDEJADA, MYSQL ES LO MAXIMO
    QString idMarca = myProducto.mf_get_Marca_idMarca();
    if(idMarca == "0")
        idMarca = "%";
    if(md_o_Tamanio_idTamanio == "0")
        md_o_Tamanio_idTamanio = "%";
    if(md_o_Forma_idForma == "0")
        md_o_Forma_idForma = "%";
    if(md_o_Calidad_idCalidad == "0")
        md_o_Calidad_idCalidad = "%";
    if(md_o_Color_idColor == "0")
        md_o_Color_idColor = "%";
    if(md_o_Genero_idGenero == "0")
        md_o_Genero_idGenero = "%";

    QString consulta = "SELECT Producto_idProducto as 'Id',codigo as 'Cod',descripcion as 'Descp',e.nombre as 'Estado',precioCompra as 'Compra',precioVenta as 'Venta',precioDescuento as 'Desct',stock,m.nombre as 'Marca',f.nombre as 'Forma',c.nombre as 'Color',t.nombre as 'Tamaño',ca.nombre as 'Calidad',ge.nombre as 'Genero', p.cantidadVitrina as 'Cnt. Vitrina', p.cantidadAlmacen as 'Cnt. Almacen', p.accesorios as 'Acces.', p.observaciones as 'Obsv.' FROM Producto p,Estado e,Montura mn,Marca m,Forma f,Color c,Tamanio t,Calidad ca, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=mn.Producto_idProducto AND mn.Forma_idForma=f.idForma AND mn.Color_idColor=c.idColor AND mn.Tamanio_idTamanio=t.idTamanio AND mn.Calidad_idCalidad=ca.idCalidad AND mn.Genero_idGenero=ge.idGenero AND m.idMarca like '"+idMarca+"' AND t.idTamanio like '"+md_o_Tamanio_idTamanio+"' AND f.idForma like '"+md_o_Forma_idForma+"' AND ca.idCalidad like '"+md_o_Calidad_idCalidad+"' AND c.idColor like '"+md_o_Color_idColor+"' AND ge.idGenero like '"+md_o_Genero_idGenero+"' order by idProducto";
    model->setQuery(consulta);

    return model;

}


QSqlQueryModel* object_Montura::mf_show_search(QString id)
{
    QSqlQueryModel* model=new QSqlQueryModel;
//AQUI ESTA LA PENDEJADA, MYSQL ES LO MAXIMO


    QString consulta = "SELECT Producto_idProducto as 'Id',codigo as 'Cod',descripcion as 'Descp',e.nombre as 'Estado',precioCompra as 'Compra',precioVenta as 'Venta',precioDescuento as 'Desct',stock,m.nombre as 'Marca',f.nombre as 'Forma',c.nombre as 'Color',t.nombre as 'Tamaño',ca.nombre as 'Calidad',ge.nombre as 'Genero', p.cantidadVitrina as 'Cnt. Vitrina', p.cantidadAlmacen as 'Cnt. Almacen', p.accesorios as 'Acces.', p.observaciones as 'Obsv.' FROM Producto p,Estado e,Montura mn,Marca m,Forma f,Color c,Tamanio t,Calidad ca, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=mn.Producto_idProducto AND mn.Forma_idForma=f.idForma AND mn.Color_idColor=c.idColor AND mn.Tamanio_idTamanio=t.idTamanio AND mn.Calidad_idCalidad=ca.idCalidad AND mn.Genero_idGenero=ge.idGenero AND p.codigo REGEXP '"+id+"' order by idProducto";
    model->setQuery(consulta);    
    return model;

}
