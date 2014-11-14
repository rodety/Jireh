#include "object_Otros.h"

object_Otros::object_Otros()
{
	//file Otros
	//function construct_0
	//w!
}

object_Otros::object_Otros(_QSTR Producto_idProducto, _QSTR Color_idColor, _QSTR Talla_idTalla, _QSTR Calidad_idCalidad, _QSTR TipoOtros_idTipoOtros, _QSTR Genero_idGenero)
{
	//file Otros
	//function construct_1
	//w!

	md_o_Producto_idProducto = Producto_idProducto;
	md_o_Color_idColor = Color_idColor;
	md_o_Talla_idTalla = Talla_idTalla;
	md_o_Calidad_idCalidad = Calidad_idCalidad;
	md_o_TipoOtros_idTipoOtros = TipoOtros_idTipoOtros;
	md_o_Genero_idGenero = Genero_idGenero;
}
object_Otros::object_Otros(_QSTR Color_idColor, _QSTR Talla_idTalla, _QSTR Calidad_idCalidad, _QSTR TipoOtros_idTipoOtros, _QSTR Genero_idGenero)
{
	//file Otros
	//function construct_2
	//w!

	md_o_Color_idColor = Color_idColor;
	md_o_Talla_idTalla = Talla_idTalla;
	md_o_Calidad_idCalidad = Calidad_idCalidad;
	md_o_TipoOtros_idTipoOtros = TipoOtros_idTipoOtros;
	md_o_Genero_idGenero = Genero_idGenero;
}
object_Otros::~object_Otros()
{

}


void object_Otros::mf_set_Producto_idProducto(_QSTR Producto_idProducto)
{
	//function mf_set_Producto_idProducto
	//w!

	md_o_Producto_idProducto = Producto_idProducto;
}
void object_Otros::mf_set_Color_idColor(_QSTR Color_idColor)
{
	//function mf_set_Color_idColor
	//w!

	md_o_Color_idColor = Color_idColor;
}
void object_Otros::mf_set_Talla_idTalla(_QSTR Talla_idTalla)
{
	//function mf_set_Talla_idTalla
	//w!

	md_o_Talla_idTalla = Talla_idTalla;
}
void object_Otros::mf_set_Calidad_idCalidad(_QSTR Calidad_idCalidad)
{
	//function mf_set_Calidad_idCalidad
	//w!

	md_o_Calidad_idCalidad = Calidad_idCalidad;
}
void object_Otros::mf_set_TipoOtros_idTipoOtros(_QSTR TipoOtros_idTipoOtros)
{
	//function mf_set_TipoOtros_idTipoOtros
	//w!

	md_o_TipoOtros_idTipoOtros = TipoOtros_idTipoOtros;
}
void object_Otros::mf_set_Genero_idGenero(_QSTR Genero_idGenero)
{
	//function mf_set_Genero_idGenero
	//w!

	md_o_Genero_idGenero = Genero_idGenero;
}

_QSTR object_Otros::mf_get_Producto_idProducto()
{
	//function mf_get_Producto_idProducto
	//w!

	return md_o_Producto_idProducto;
}
_QSTR object_Otros::mf_get_Color_idColor()
{
	//function mf_get_Color_idColor
	//w!

	return md_o_Color_idColor;
}
_QSTR object_Otros::mf_get_Talla_idTalla()
{
	//function mf_get_Talla_idTalla
	//w!

	return md_o_Talla_idTalla;
}
_QSTR object_Otros::mf_get_Calidad_idCalidad()
{
	//function mf_get_Calidad_idCalidad
	//w!

	return md_o_Calidad_idCalidad;
}
_QSTR object_Otros::mf_get_TipoOtros_idTipoOtros()
{
	//function mf_get_TipoOtros_idTipoOtros
	//w!

	return md_o_TipoOtros_idTipoOtros;
}
_QSTR object_Otros::mf_get_Genero_idGenero()
{
	//function mf_get_Genero_idGenero
	//w!

	return md_o_Genero_idGenero;
}

bool object_Otros::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Otros WHERE Producto_idProducto = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_Producto_idProducto = query.value(0).toString();
		md_o_Color_idColor = query.value(1).toString();
		md_o_Talla_idTalla = query.value(2).toString();
		md_o_Calidad_idCalidad = query.value(3).toString();
		md_o_TipoOtros_idTipoOtros = query.value(4).toString();
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
bool object_Otros::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Otros(";
	str_query += "Producto_idProducto";
	str_query += ", Color_idColor";
	str_query += ", Talla_idTalla";
	str_query += ", Calidad_idCalidad";
	str_query += ", TipoOtros_idTipoOtros";
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
        query.bindValue(integer++, NULL);
	query.bindValue(integer++, md_o_Color_idColor);
	query.bindValue(integer++, md_o_Talla_idTalla);
	query.bindValue(integer++, md_o_Calidad_idCalidad);
	query.bindValue(integer++, md_o_TipoOtros_idTipoOtros);
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

bool object_Otros::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Otros SET Color_idColor = ?, Talla_idTalla = ?, Calidad_idCalidad = ?, TipoOtros_idTipoOtros = ?, Genero_idGenero = ? WHERE Producto_idProducto = ?");
	query.bindValue(0, md_o_Color_idColor);
	query.bindValue(1, md_o_Talla_idTalla);
	query.bindValue(2, md_o_Calidad_idCalidad);
	query.bindValue(3, md_o_TipoOtros_idTipoOtros);
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

bool object_Otros::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Otros FROM Producto_idProducto = ?");
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

QSqlQueryModel* object_Otros::mf_show(object_Producto myProducto)
{
    QSqlQueryModel* model=new QSqlQueryModel;
//AQUI ESTA LA PENDEJADA, MYSQL ES LO MAXIMO
    QString idMarca = myProducto.mf_get_Marca_idMarca();
    if(idMarca == "0")
        idMarca = "%";
    if(md_o_TipoOtros_idTipoOtros == "0")
        md_o_TipoOtros_idTipoOtros = "%";
    if(md_o_Calidad_idCalidad == "0")
        md_o_Calidad_idCalidad = "%";
    if(md_o_Color_idColor == "0")
        md_o_Color_idColor = "%";
    if(md_o_Talla_idTalla == "0")
        md_o_Talla_idTalla = "%";
    if(md_o_Genero_idGenero == "0")
        md_o_Genero_idGenero = "%";

    model->setQuery("SELECT Producto_idProducto as 'Id',codigo,descripcion,e.nombre as 'Estado',precioCompra,precioVenta,precioDescuento,stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Talla',ca.nombre as 'Calidad',tpo.nombre as 'Tipo',ge.nombre as 'Genero', p.cantidadVitrina as 'Cnt. Vitrina', p.cantidadAlmacen as 'Cnt. Almacen', p.accesorios as 'Acces.', p.observaciones as 'Obs.' FROM Producto p,Otros o,Estado e,Marca m,Color c,Talla t,Calidad ca,TipoOtros tpo, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=o.Producto_idProducto AND o.Color_idColor=c.idColor AND o.Talla_idTalla=t.idTalla AND o.Calidad_idCalidad=ca.idCalidad AND o.TipoOtros_idTipoOtros=tpo.idTipoOtros AND o.Genero_idGenero=ge.idGenero AND p.Marca_idMarca like '"+idMarca+"' AND tpo.idTipoOtros like '"+md_o_TipoOtros_idTipoOtros+"' AND ca.idCalidad like '"+md_o_Calidad_idCalidad+"' AND c.idColor like '"+md_o_Color_idColor+"' AND t.idTalla like '"+md_o_Talla_idTalla+"' AND ge.idGenero like'"+md_o_Genero_idGenero+"' order by idProducto");
    return model;
}

QSqlQueryModel* object_Otros::mf_show_search(QString id)
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT Producto_idProducto as 'Id',codigo,descripcion,e.nombre as 'Estado',precioCompra,precioVenta,precioDescuento,stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Talla',ca.nombre as 'Calidad',tpo.nombre as 'Tipo',ge.nombre as 'Genero', p.cantidadVitrina as 'Cnt. Vitrina', p.cantidadAlmacen as 'Cnt. Almacen', p.accesorios as 'Acces.', p.observaciones as 'Obs.' FROM Producto p,Otros o,Estado e,Marca m,Color c,Talla t,Calidad ca,TipoOtros tpo, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=o.Producto_idProducto AND o.Color_idColor=c.idColor AND o.Talla_idTalla=t.idTalla AND o.Calidad_idCalidad=ca.idCalidad AND o.TipoOtros_idTipoOtros=tpo.idTipoOtros AND o.Genero_idGenero=ge.idGenero AND p.codigo REGEXP '"+id+"' order by idProducto");
    return model;
}
