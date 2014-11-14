#include "object_Contenedor_has_Producto.h"

object_Contenedor_has_Producto::object_Contenedor_has_Producto()
{
	//file Contenedor_has_Producto
	//function construct_0
	//w!
}

object_Contenedor_has_Producto::object_Contenedor_has_Producto(_QSTR idContenedor, _QSTR Contenedor_idContenedor, _QSTR Producto_idProducto, _QSTR Colaborador_Persona_idPersona, _QSTR fecha, _QSTR cantidadProducto)
{
	//file Contenedor_has_Producto
	//function construct_1
	//w!

	md_o_idContenedor = idContenedor;
	md_o_Contenedor_idContenedor = Contenedor_idContenedor;
	md_o_Producto_idProducto = Producto_idProducto;
	md_o_Colaborador_Persona_idPersona = Colaborador_Persona_idPersona;
	md_o_fecha = fecha;
	md_o_cantidadProducto = cantidadProducto;
}
object_Contenedor_has_Producto::object_Contenedor_has_Producto(_QSTR Contenedor_idContenedor, _QSTR Producto_idProducto, _QSTR Colaborador_Persona_idPersona, _QSTR fecha, _QSTR cantidadProducto)
{
	//file Contenedor_has_Producto
	//function construct_2
	//w!

	md_o_Contenedor_idContenedor = Contenedor_idContenedor;
	md_o_Producto_idProducto = Producto_idProducto;
	md_o_Colaborador_Persona_idPersona = Colaborador_Persona_idPersona;
	md_o_fecha = fecha;
	md_o_cantidadProducto = cantidadProducto;
}
object_Contenedor_has_Producto::~object_Contenedor_has_Producto()
{

}


void object_Contenedor_has_Producto::mf_set_idContenedor(_QSTR idContenedor)
{
	//function mf_set_idContenedor
	//w!

	md_o_idContenedor = idContenedor;
}
void object_Contenedor_has_Producto::mf_set_Contenedor_idContenedor(_QSTR Contenedor_idContenedor)
{
	//function mf_set_Contenedor_idContenedor
	//w!

	md_o_Contenedor_idContenedor = Contenedor_idContenedor;
}
void object_Contenedor_has_Producto::mf_set_Producto_idProducto(_QSTR Producto_idProducto)
{
	//function mf_set_Producto_idProducto
	//w!

	md_o_Producto_idProducto = Producto_idProducto;
}
void object_Contenedor_has_Producto::mf_set_Colaborador_Persona_idPersona(_QSTR Colaborador_Persona_idPersona)
{
	//function mf_set_Colaborador_Persona_idPersona
	//w!

	md_o_Colaborador_Persona_idPersona = Colaborador_Persona_idPersona;
}
void object_Contenedor_has_Producto::mf_set_fecha(_QSTR fecha)
{
	//function mf_set_fecha
	//w!

	md_o_fecha = fecha;
}
void object_Contenedor_has_Producto::mf_set_cantidadProducto(_QSTR cantidadProducto)
{
	//function mf_set_cantidadProducto
	//w!

	md_o_cantidadProducto = cantidadProducto;
}

_QSTR object_Contenedor_has_Producto::mf_get_idContenedor()
{
	//function mf_get_idContenedor
	//w!

	return md_o_idContenedor;
}
_QSTR object_Contenedor_has_Producto::mf_get_Contenedor_idContenedor()
{
	//function mf_get_Contenedor_idContenedor
	//w!

	return md_o_Contenedor_idContenedor;
}
_QSTR object_Contenedor_has_Producto::mf_get_Producto_idProducto()
{
	//function mf_get_Producto_idProducto
	//w!

	return md_o_Producto_idProducto;
}
_QSTR object_Contenedor_has_Producto::mf_get_Colaborador_Persona_idPersona()
{
	//function mf_get_Colaborador_Persona_idPersona
	//w!

	return md_o_Colaborador_Persona_idPersona;
}
_QSTR object_Contenedor_has_Producto::mf_get_fecha()
{
	//function mf_get_fecha
	//w!

	return md_o_fecha;
}
_QSTR object_Contenedor_has_Producto::mf_get_cantidadProducto()
{
	//function mf_get_cantidadProducto
	//w!

	return md_o_cantidadProducto;
}

bool object_Contenedor_has_Producto::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Contenedor_has_Producto WHERE idContenedor = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idContenedor = query.value(0).toString();
		md_o_Contenedor_idContenedor = query.value(1).toString();
		md_o_Producto_idProducto = query.value(2).toString();
		md_o_Colaborador_Persona_idPersona = query.value(3).toString();
		md_o_fecha = query.value(4).toString();
		md_o_cantidadProducto = query.value(5).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Contenedor_has_Producto::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Contenedor_has_Producto(";
	str_query += "idContenedor";
	str_query += ", Contenedor_idContenedor";
	str_query += ", Producto_idProducto";
	str_query += ", Colaborador_Persona_idPersona";
	str_query += ", fecha";
	str_query += ", cantidadProducto";
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
	if (md_o_idContenedor != "")
	{
		query.bindValue(integer++, md_o_idContenedor);
	}
	else
        query.bindValue(integer++, NULL);
	query.bindValue(integer++, md_o_Contenedor_idContenedor);
	query.bindValue(integer++, md_o_Producto_idProducto);
	query.bindValue(integer++, md_o_Colaborador_Persona_idPersona);
	query.bindValue(integer++, md_o_fecha);
	query.bindValue(integer++, md_o_cantidadProducto);    

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

bool object_Contenedor_has_Producto::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;
    if(md_o_cantidadProducto.toInt() > 0)
    {
        query.prepare("UPDATE Contenedor_has_Producto SET Contenedor_idContenedor = ?, Producto_idProducto = ?, Colaborador_Persona_idPersona = ?, fecha = ?, cantidadProducto = cantidadProducto + ? WHERE idContenedor = ?");
        query.bindValue(0, md_o_Contenedor_idContenedor);
        query.bindValue(1, md_o_Producto_idProducto);
        query.bindValue(2, md_o_Colaborador_Persona_idPersona);
        query.bindValue(3, md_o_fecha);
        query.bindValue(4, md_o_cantidadProducto);
        query.bindValue(5, md_o_idContenedor);
    }
    else
    {        
        query.prepare("UPDATE Contenedor_has_Producto SET Contenedor_idContenedor = '"+md_o_Contenedor_idContenedor+"', Producto_idProducto = '"+md_o_Producto_idProducto+"', Colaborador_Persona_idPersona = '"+md_o_Colaborador_Persona_idPersona+"', fecha = '"+md_o_fecha+"', cantidadProducto = cantidadProducto "+md_o_cantidadProducto+" WHERE Contenedor_idContenedor = '"+md_o_Contenedor_idContenedor+"'");
    }

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

bool object_Contenedor_has_Producto::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

    query.prepare("DELETE FROM Contenedor_has_Producto WHERE Producto_idProducto = ? AND Contenedor_idContenedor = ?");
    query.bindValue(0, md_o_Producto_idProducto);
    query.bindValue(1, md_o_Contenedor_idContenedor);

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

bool object_Contenedor_has_Producto::mf_exist_product()
{
    //function mf_remove
    //w!

    QSqlQuery query;

    query.prepare("SELECT idContenedor FROM Contenedor_has_Producto WHERE Contenedor_idContenedor = ? AND Producto_idProducto = ?");
    query.bindValue(0, md_o_Contenedor_idContenedor);
    query.bindValue(1, md_o_Producto_idProducto);    

    if(query.exec())
    {
        //state OK
        //w!
        if(query.next())
        {
            md_o_idContenedor = query.value(0).toString();
            return true;

        }
        else
            return false;

    }else{
    //state FAILED
    //w!
        return false;
    }
}
QSqlQueryModel *object_Contenedor_has_Producto::mf_show()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    QString consulta;

    consulta = "SELECT cp.Producto_idProducto as 'Id', p.codigo as 'Codigo', cp.cantidadProducto as 'Cant.', cp.fecha as 'Fecha', CONCAT(c.nombres,' ',c.primer_apellido) as 'Colaborador' FROM Producto p, Contenedor_has_Producto cp, Colaborador c WHERE p.idProducto = cp.Producto_idProducto AND cp.Contenedor_idContenedor ='"+md_o_idContenedor+"' AND c.idColaborador = cp.Colaborador_Persona_idPersona ORDER BY cp.fecha";

    QSqlQuery query(consulta);
    model->setQuery(query);
    return model;
}

QSqlQueryModel *object_Contenedor_has_Producto::mf_show_ubication()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    QString consulta;    

    consulta = "SELECT cp.idContenedor as 'id', p.codigo as 'Codigo', t.nombre 'Tienda', a.nombre as 'Almacen', CONCAT(an.nombre,' ',an.fila,',',an.columna) as 'Andamio', CONCAT(co.nombre,' ',co.posFila,',',co.posColumna) as 'Contenedor', cp.cantidadProducto as 'Cant.', cp.fecha as 'Fecha', CONCAT(c.nombres,' ',c.primer_apellido) as 'Colaborador' FROM Producto p, Tienda t,Almacen a, Andamio an, Contenedor co, Contenedor_has_Producto cp, Colaborador c WHERE p.idProducto = '"+md_o_Producto_idProducto+"' AND co.idContenedor = cp.Contenedor_idContenedor AND an.idAndamio = co.Andamio_idAndamio AND a.idAlmacen = an.Almacen_idAlmacen AND t.idTienda = a.Tienda_idTienda AND c.idColaborador = cp.Colaborador_Persona_idPersona AND cp.Producto_idProducto = '"+md_o_Producto_idProducto+"' ORDER BY cp.fecha";
    QSqlQuery query(consulta);
    model->setQuery(query);
    return model;
}

bool object_Contenedor_has_Producto::mf_update_cant(int cant)
{
    //function mf_update
    //w!
    QSqlQuery query;
    if(cant > 0)
        query.prepare("UPDATE Contenedor_has_Producto SET cantidadProducto = cantidadProducto + ? WHERE idContenedor = ? AND Producto_idProducto = ?");
    else
        query.prepare("UPDATE Contenedor_has_Producto SET cantidadProducto = cantidadProducto ? WHERE idContenedor = ? AND Producto_idProducto = ?");

    query.bindValue(0, cant);
    query.bindValue(1, md_o_idContenedor);
    query.bindValue(2, md_o_Producto_idProducto);

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

bool object_Contenedor_has_Producto::mf_remove_cant(int cantRemove)
{
    QSqlQuery query;
    query.prepare("SELECT cantidadProducto FROM Contenedor_has_Producto WHERE Contenedor_idContenedor = ? AND Producto_idProducto = ?");
    query.bindValue(0,md_o_Contenedor_idContenedor);
    query.bindValue(1,md_o_Producto_idProducto);
    query.exec();

    if(!query.next())
    {
        return false;
    }
    int cantidadProducto = query.value(0).toInt();
    /**
     *BORRAR EL REGISTRO
     **/
    if(cantRemove >= cantidadProducto)
    {
        if(!mf_remove())
            return false;
    }
    else
    {
        query.prepare("UPDATE Contenedor_has_Producto SET cantidadProducto = cantidadProducto - ? WHERE idContenedor = ? AND Producto_idProducto = ?");
        query.bindValue(0, cantRemove);
        query.bindValue(1, md_o_idContenedor);
        query.bindValue(2, md_o_Producto_idProducto);
        if(!query.exec())
        {
            return false;
        }
    }
    return true;

}


