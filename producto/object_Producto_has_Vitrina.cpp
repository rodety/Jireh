#include "object_Producto_has_Vitrina.h"

object_Producto_has_Vitrina::object_Producto_has_Vitrina()
{
	//file Producto_has_Vitrina
	//function construct_0
	//w!
}

object_Producto_has_Vitrina::object_Producto_has_Vitrina(_QSTR idProducto_has_Vitrina, _QSTR Producto_idProducto, _QSTR Vitrina_Ubicacion_idUbicacion, _QSTR Colaborador_Persona_idPersona, _QSTR fila, _QSTR columna, _QSTR nivel, _QSTR fecha, _QSTR estado, _QSTR comentario)
{
	//file Producto_has_Vitrina
	//function construct_1
	//w!

	md_o_idProducto_has_Vitrina = idProducto_has_Vitrina;
	md_o_Producto_idProducto = Producto_idProducto;
	md_o_Vitrina_Ubicacion_idUbicacion = Vitrina_Ubicacion_idUbicacion;
	md_o_Colaborador_Persona_idPersona = Colaborador_Persona_idPersona;
	md_o_fila = fila;
	md_o_columna = columna;
	md_o_nivel = nivel;
	md_o_fecha = fecha;
	md_o_estado = estado;
	md_o_comentario = comentario;
}
object_Producto_has_Vitrina::object_Producto_has_Vitrina(_QSTR Producto_idProducto, _QSTR Vitrina_Ubicacion_idUbicacion, _QSTR Colaborador_Persona_idPersona, _QSTR fila, _QSTR columna, _QSTR nivel, _QSTR fecha, _QSTR estado, _QSTR comentario)
{
	//file Producto_has_Vitrina
	//function construct_2
	//w!

	md_o_Producto_idProducto = Producto_idProducto;
	md_o_Vitrina_Ubicacion_idUbicacion = Vitrina_Ubicacion_idUbicacion;
	md_o_Colaborador_Persona_idPersona = Colaborador_Persona_idPersona;
	md_o_fila = fila;
	md_o_columna = columna;
	md_o_nivel = nivel;
	md_o_fecha = fecha;
	md_o_estado = estado;
	md_o_comentario = comentario;
}
object_Producto_has_Vitrina::~object_Producto_has_Vitrina()
{

}


void object_Producto_has_Vitrina::mf_set_idProducto_has_Vitrina(_QSTR idProducto_has_Vitrina)
{
	//function mf_set_idProducto_has_Vitrina
	//w!

	md_o_idProducto_has_Vitrina = idProducto_has_Vitrina;
}
void object_Producto_has_Vitrina::mf_set_Producto_idProducto(_QSTR Producto_idProducto)
{
	//function mf_set_Producto_idProducto
	//w!

	md_o_Producto_idProducto = Producto_idProducto;
}
void object_Producto_has_Vitrina::mf_set_Vitrina_Ubicacion_idUbicacion(_QSTR Vitrina_Ubicacion_idUbicacion)
{
	//function mf_set_Vitrina_Ubicacion_idUbicacion
	//w!

	md_o_Vitrina_Ubicacion_idUbicacion = Vitrina_Ubicacion_idUbicacion;
}
void object_Producto_has_Vitrina::mf_set_Colaborador_Persona_idPersona(_QSTR Colaborador_Persona_idPersona)
{
	//function mf_set_Colaborador_Persona_idPersona
	//w!

	md_o_Colaborador_Persona_idPersona = Colaborador_Persona_idPersona;
}
void object_Producto_has_Vitrina::mf_set_fila(_QSTR fila)
{
	//function mf_set_fila
	//w!

	md_o_fila = fila;
}
void object_Producto_has_Vitrina::mf_set_columna(_QSTR columna)
{
	//function mf_set_columna
	//w!

	md_o_columna = columna;
}
void object_Producto_has_Vitrina::mf_set_nivel(_QSTR nivel)
{
	//function mf_set_nivel
	//w!

	md_o_nivel = nivel;
}
void object_Producto_has_Vitrina::mf_set_fecha(_QSTR fecha)
{
	//function mf_set_fecha
	//w!

	md_o_fecha = fecha;
}
void object_Producto_has_Vitrina::mf_set_estado(_QSTR estado)
{
	//function mf_set_estado
	//w!

	md_o_estado = estado;
}
void object_Producto_has_Vitrina::mf_set_comentario(_QSTR comentario)
{
	//function mf_set_comentario
	//w!

	md_o_comentario = comentario;
}

_QSTR object_Producto_has_Vitrina::mf_get_idProducto_has_Vitrina()
{
	//function mf_get_idProducto_has_Vitrina
	//w!

	return md_o_idProducto_has_Vitrina;
}
_QSTR object_Producto_has_Vitrina::mf_get_Producto_idProducto()
{
	//function mf_get_Producto_idProducto
	//w!

	return md_o_Producto_idProducto;
}
_QSTR object_Producto_has_Vitrina::mf_get_Vitrina_Ubicacion_idUbicacion()
{
	//function mf_get_Vitrina_Ubicacion_idUbicacion
	//w!

	return md_o_Vitrina_Ubicacion_idUbicacion;
}
_QSTR object_Producto_has_Vitrina::mf_get_Colaborador_Persona_idPersona()
{
	//function mf_get_Colaborador_Persona_idPersona
	//w!

	return md_o_Colaborador_Persona_idPersona;
}
_QSTR object_Producto_has_Vitrina::mf_get_fila()
{
	//function mf_get_fila
	//w!

	return md_o_fila;
}
_QSTR object_Producto_has_Vitrina::mf_get_columna()
{
	//function mf_get_columna
	//w!

	return md_o_columna;
}
_QSTR object_Producto_has_Vitrina::mf_get_nivel()
{
	//function mf_get_nivel
	//w!

	return md_o_nivel;
}
_QSTR object_Producto_has_Vitrina::mf_get_fecha()
{
	//function mf_get_fecha
	//w!

	return md_o_fecha;
}
_QSTR object_Producto_has_Vitrina::mf_get_estado()
{
	//function mf_get_estado
	//w!

	return md_o_estado;
}
_QSTR object_Producto_has_Vitrina::mf_get_comentario()
{
	//function mf_get_comentario
	//w!

	return md_o_comentario;
}

bool object_Producto_has_Vitrina::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Producto_has_Vitrina WHERE idProducto_has_Vitrina = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idProducto_has_Vitrina = query.value(0).toString();
		md_o_Producto_idProducto = query.value(1).toString();
		md_o_Vitrina_Ubicacion_idUbicacion = query.value(2).toString();
		md_o_Colaborador_Persona_idPersona = query.value(3).toString();
		md_o_fila = query.value(4).toString();
		md_o_columna = query.value(5).toString();
		md_o_nivel = query.value(6).toString();
		md_o_fecha = query.value(7).toString();
		md_o_estado = query.value(8).toString();
		md_o_comentario = query.value(9).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Producto_has_Vitrina::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Producto_has_Vitrina(";
	if (md_o_idProducto_has_Vitrina != "")
		str_query += "idProducto_has_Vitrina, ";
	str_query += "Producto_idProducto";
	str_query += ", Vitrina_Ubicacion_idUbicacion";
	str_query += ", Colaborador_Persona_idPersona";
	str_query += ", fila";
	str_query += ", columna";
	str_query += ", nivel";
	str_query += ", fecha";
	str_query += ", estado";
	str_query += ", comentario";
	str_query += ") VALUES(";
	if (md_o_idProducto_has_Vitrina!= "")
	{
		str_query += "?, ";
	}
	str_query += "?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idProducto_has_Vitrina != "")
	{
		query.bindValue(integer++, md_o_idProducto_has_Vitrina);
	}
	query.bindValue(integer++, md_o_Producto_idProducto);
	query.bindValue(integer++, md_o_Vitrina_Ubicacion_idUbicacion);
	query.bindValue(integer++, md_o_Colaborador_Persona_idPersona);
	query.bindValue(integer++, md_o_fila);
	query.bindValue(integer++, md_o_columna);
	query.bindValue(integer++, md_o_nivel);
	query.bindValue(integer++, md_o_fecha);
	query.bindValue(integer++, md_o_estado);
	query.bindValue(integer++, md_o_comentario);

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

bool object_Producto_has_Vitrina::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Producto_has_Vitrina SET Producto_idProducto = ?, Vitrina_Ubicacion_idUbicacion = ?, Colaborador_Persona_idPersona = ?, fila = ?, columna = ?, nivel = ?, fecha = ?, estado = ?, comentario = ? WHERE idProducto_has_Vitrina = ?");
	query.bindValue(0, md_o_Producto_idProducto);
	query.bindValue(1, md_o_Vitrina_Ubicacion_idUbicacion);
	query.bindValue(2, md_o_Colaborador_Persona_idPersona);
	query.bindValue(3, md_o_fila);
	query.bindValue(4, md_o_columna);
	query.bindValue(5, md_o_nivel);
	query.bindValue(6, md_o_fecha);
	query.bindValue(7, md_o_estado);
	query.bindValue(8, md_o_comentario);
	query.bindValue(9, md_o_idProducto_has_Vitrina);

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

bool object_Producto_has_Vitrina::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

    query.prepare("DELETE FROM Producto_has_Vitrina WHERE idProducto_has_Vitrina = ?");
	query.bindValue(0, md_o_idProducto_has_Vitrina);
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

QSqlQueryModel *object_Producto_has_Vitrina::mf_show()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    QString consulta;

    //consulta = "SELECT p.codigo as 'Codigo', t.nombre as 'Tienda', v.nombre as 'Vitrina', pv.fila as 'Fila', pv.columna as 'Columna', pv.nivel as 'Nivel',pv.fecha as 'Fecha', CONCAT(c.nombres,' ',c.primer_apellido) as 'Colaborador' FROM Producto p, Tienda t, Vitrina v, Producto_has_Vitrina pv, Colaborador c WHERE p.idProducto = '"+md_o_Producto_idProducto+"' AND v.Tienda_idTienda = t.idTienda AND v.Ubicacion_idUbicacion = pv.Vitrina_Ubicacion_idUbicacion AND pv.Producto_idProducto = '"+md_o_Producto_idProducto+"' AND c.idColaborador = pv.Colaborador_Persona_idPersona ORDER BY pv.fecha";

    consulta = "SELECT pv.idProducto_has_Vitrina as 'id', p.codigo as 'Codigo', t.nombre as 'Tienda', v.nombre as 'Vitrina', pv.fila as 'Fila', pv.columna as 'Columna', pv.nivel as 'Nivel',pv.fecha as 'Fecha', CONCAT(c.nombres,' ',c.primer_apellido) as 'Colaborador' FROM Producto p, Tienda t, Vitrina v, Producto_has_Vitrina pv, Colaborador c WHERE p.idProducto = '"+md_o_Producto_idProducto+"' AND v.Tienda_idTienda = t.idTienda AND v.Ubicacion_idUbicacion = pv.Vitrina_Ubicacion_idUbicacion AND pv.Producto_idProducto = '"+md_o_Producto_idProducto+"' AND c.idColaborador = pv.Colaborador_Persona_idPersona ORDER BY pv.fecha";

    QSqlQuery query(consulta);
    model->setQuery(query);
    return model;
}

bool object_Producto_has_Vitrina::mf_update_comentario()
{
    QSqlQuery query;
    query.prepare("UPDATE Producto_has_Vitrina SET comentario = ? WHERE idProducto_has_Vitrina = ?");
    query.bindValue(0, md_o_comentario);
    query.bindValue(1, md_o_idProducto_has_Vitrina);

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

bool object_Producto_has_Vitrina::mf_update_estado()
{
    QSqlQuery query;
    query.prepare("UPDATE Producto_has_Vitrina SET estado = ?,comentario = ? WHERE idProducto_has_Vitrina = ?");
    query.bindValue(0, md_o_estado);
    query.bindValue(1, md_o_comentario);
    query.bindValue(2, md_o_idProducto_has_Vitrina);

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
