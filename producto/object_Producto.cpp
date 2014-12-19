#include "object_Producto.h"
#include "object_Kardex.h"
#include "configuracion/sesion.h"

object_Producto::object_Producto()
{
	//file Producto
	//function construct_0
	//w!
}

object_Producto::object_Producto(_QSTR idProducto, _QSTR codigo, _QSTR descripcion, _QSTR precioCompra, _QSTR precioVenta, _QSTR precioDescuento, _QSTR accesorios, _QSTR stock, _QSTR observaciones, _QSTR Estado_idEstado, _QSTR Marca_idMarca, _QSTR idColaborador, _QSTR cantidadVitrina, _QSTR cantidadAlmacen, _QSTR tipo)
{
	//file Producto
	//function construct_1
	//w!

	md_o_idProducto = idProducto;
	md_o_codigo = codigo;
	md_o_descripcion = descripcion;
	md_o_precioCompra = precioCompra;
	md_o_precioVenta = precioVenta;
	md_o_precioDescuento = precioDescuento;
	md_o_accesorios = accesorios;
	md_o_stock = stock;
	md_o_observaciones = observaciones;
	md_o_Estado_idEstado = Estado_idEstado;
	md_o_Marca_idMarca = Marca_idMarca;
	md_o_idColaborador = idColaborador;
	md_o_cantidadVitrina = cantidadVitrina;
	md_o_cantidadAlmacen = cantidadAlmacen;
	md_o_tipo = tipo;
}
object_Producto::object_Producto(_QSTR codigo, _QSTR descripcion, _QSTR precioCompra, _QSTR precioVenta, _QSTR precioDescuento, _QSTR accesorios, _QSTR stock, _QSTR observaciones, _QSTR Estado_idEstado, _QSTR Marca_idMarca, _QSTR idColaborador, _QSTR cantidadVitrina, _QSTR cantidadAlmacen, _QSTR tipo)
{
	//file Producto
	//function construct_2
	//w!

	md_o_codigo = codigo;
	md_o_descripcion = descripcion;
	md_o_precioCompra = precioCompra;
	md_o_precioVenta = precioVenta;
	md_o_precioDescuento = precioDescuento;
	md_o_accesorios = accesorios;
	md_o_stock = stock;
	md_o_observaciones = observaciones;
	md_o_Estado_idEstado = Estado_idEstado;
	md_o_Marca_idMarca = Marca_idMarca;
	md_o_idColaborador = idColaborador;
	md_o_cantidadVitrina = cantidadVitrina;
	md_o_cantidadAlmacen = cantidadAlmacen;
	md_o_tipo = tipo;
}
object_Producto::~object_Producto()
{

}


void object_Producto::mf_set_idProducto(_QSTR idProducto)
{
	//function mf_set_idProducto
	//w!

	md_o_idProducto = idProducto;
}
void object_Producto::mf_set_codigo(_QSTR codigo)
{
	//function mf_set_codigo
	//w!

	md_o_codigo = codigo;
}
void object_Producto::mf_set_descripcion(_QSTR descripcion)
{
	//function mf_set_descripcion
	//w!

	md_o_descripcion = descripcion;
}
void object_Producto::mf_set_precioCompra(_QSTR precioCompra)
{
	//function mf_set_precioCompra
	//w!

	md_o_precioCompra = precioCompra;
}
void object_Producto::mf_set_precioVenta(_QSTR precioVenta)
{
	//function mf_set_precioVenta
	//w!

	md_o_precioVenta = precioVenta;
}
void object_Producto::mf_set_precioDescuento(_QSTR precioDescuento)
{
	//function mf_set_precioDescuento
	//w!

	md_o_precioDescuento = precioDescuento;
}
void object_Producto::mf_set_accesorios(_QSTR accesorios)
{
	//function mf_set_accesorios
	//w!

	md_o_accesorios = accesorios;
}
void object_Producto::mf_set_stock(_QSTR stock)
{
	//function mf_set_stock
	//w!

	md_o_stock = stock;
}
void object_Producto::mf_set_observaciones(_QSTR observaciones)
{
	//function mf_set_observaciones
	//w!

	md_o_observaciones = observaciones;
}
void object_Producto::mf_set_Estado_idEstado(_QSTR Estado_idEstado)
{
	//function mf_set_Estado_idEstado
	//w!

	md_o_Estado_idEstado = Estado_idEstado;
}
void object_Producto::mf_set_Marca_idMarca(_QSTR Marca_idMarca)
{
	//function mf_set_Marca_idMarca
	//w!

	md_o_Marca_idMarca = Marca_idMarca;
}
void object_Producto::mf_set_idColaborador(_QSTR idColaborador)
{
	//function mf_set_idColaborador
	//w!

	md_o_idColaborador = idColaborador;
}
void object_Producto::mf_set_cantidadVitrina(_QSTR cantidadVitrina)
{
	//function mf_set_cantidadVitrina
	//w!

	md_o_cantidadVitrina = cantidadVitrina;
}
void object_Producto::mf_set_cantidadAlmacen(_QSTR cantidadAlmacen)
{
	//function mf_set_cantidadAlmacen
	//w!

	md_o_cantidadAlmacen = cantidadAlmacen;
}
void object_Producto::mf_set_tipo(_QSTR tipo)
{
	//function mf_set_tipo
	//w!

	md_o_tipo = tipo;
}

_QSTR object_Producto::mf_get_idProducto()
{
	//function mf_get_idProducto
	//w!

	return md_o_idProducto;
}
_QSTR object_Producto::mf_get_codigo()
{
	//function mf_get_codigo
	//w!

	return md_o_codigo;
}
_QSTR object_Producto::mf_get_descripcion()
{
	//function mf_get_descripcion
	//w!

	return md_o_descripcion;
}
_QSTR object_Producto::mf_get_precioCompra()
{
	//function mf_get_precioCompra
	//w!

	return md_o_precioCompra;
}
_QSTR object_Producto::mf_get_precioVenta()
{
	//function mf_get_precioVenta
	//w!

	return md_o_precioVenta;
}
_QSTR object_Producto::mf_get_precioDescuento()
{
	//function mf_get_precioDescuento
	//w!

	return md_o_precioDescuento;
}
_QSTR object_Producto::mf_get_accesorios()
{
	//function mf_get_accesorios
	//w!

	return md_o_accesorios;
}
_QSTR object_Producto::mf_get_stock()
{
	//function mf_get_stock
	//w!

	return md_o_stock;
}
_QSTR object_Producto::mf_get_observaciones()
{
	//function mf_get_observaciones
	//w!

	return md_o_observaciones;
}
_QSTR object_Producto::mf_get_Estado_idEstado()
{
	//function mf_get_Estado_idEstado
	//w!

	return md_o_Estado_idEstado;
}
_QSTR object_Producto::mf_get_Marca_idMarca()
{
	//function mf_get_Marca_idMarca
	//w!

	return md_o_Marca_idMarca;
}
_QSTR object_Producto::mf_get_idColaborador()
{
	//function mf_get_idColaborador
	//w!

	return md_o_idColaborador;
}
_QSTR object_Producto::mf_get_cantidadVitrina()
{
	//function mf_get_cantidadVitrina
	//w!

	return md_o_cantidadVitrina;
}
_QSTR object_Producto::mf_get_cantidadAlmacen()
{
	//function mf_get_cantidadAlmacen
	//w!

	return md_o_cantidadAlmacen;
}
_QSTR object_Producto::mf_get_tipo()
{
	//function mf_get_tipo
	//w!

	return md_o_tipo;
}

bool object_Producto::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Producto WHERE idProducto = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idProducto = query.value(0).toString();
		md_o_codigo = query.value(1).toString();
		md_o_descripcion = query.value(2).toString();
		md_o_precioCompra = query.value(3).toString();
		md_o_precioVenta = query.value(4).toString();
		md_o_precioDescuento = query.value(5).toString();
		md_o_accesorios = query.value(6).toString();
		md_o_stock = query.value(7).toString();
		md_o_observaciones = query.value(8).toString();
		md_o_Estado_idEstado = query.value(9).toString();
		md_o_Marca_idMarca = query.value(10).toString();
		md_o_idColaborador = query.value(11).toString();
		md_o_cantidadVitrina = query.value(12).toString();
		md_o_cantidadAlmacen = query.value(13).toString();
		md_o_tipo = query.value(14).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Producto::mf_load_stock(_QSTR pk)
{
    //function mf_load
    //w!

    QSqlQuery query;

    query.prepare("SELECT stock FROM Producto WHERE idProducto = ?");
    query.bindValue(0,pk);
    query.exec();

    if(query.next())
    {

            md_o_stock = query.value(0).toString();


            //state OK
            //w!

            return true;
    }else{
            //state FAILED
            //w!

            return false;
    }
}
bool object_Producto::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Producto(";
	str_query += "idProducto";
	str_query += ", codigo";
	str_query += ", descripcion";
	str_query += ", precioCompra";
	str_query += ", precioVenta";
	str_query += ", precioDescuento";
	str_query += ", accesorios";
	str_query += ", stock";
	str_query += ", observaciones";
	str_query += ", Estado_idEstado";
	str_query += ", Marca_idMarca";
	str_query += ", idColaborador";
	str_query += ", cantidadVitrina";
	str_query += ", cantidadAlmacen";
	str_query += ", tipo";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
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
	if (md_o_idProducto != "")
	{
		query.bindValue(integer++, md_o_idProducto);
	}
	else
        query.bindValue(integer++, "NULL");
	query.bindValue(integer++, md_o_codigo);
	query.bindValue(integer++, md_o_descripcion);
	query.bindValue(integer++, md_o_precioCompra);
	query.bindValue(integer++, md_o_precioVenta);
	query.bindValue(integer++, md_o_precioDescuento);
	query.bindValue(integer++, md_o_accesorios);
	query.bindValue(integer++, md_o_stock);
	query.bindValue(integer++, md_o_observaciones);
	query.bindValue(integer++, md_o_Estado_idEstado);
	query.bindValue(integer++, md_o_Marca_idMarca);
	query.bindValue(integer++, md_o_idColaborador);
	query.bindValue(integer++, md_o_cantidadVitrina);
	query.bindValue(integer++, md_o_cantidadAlmacen);
	query.bindValue(integer++, md_o_tipo);

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

bool object_Producto::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Producto SET codigo = ?, descripcion = ?, precioCompra = ?, precioVenta = ?, precioDescuento = ?, accesorios = ?, stock = ?, observaciones = ?, Estado_idEstado = ?, Marca_idMarca = ?, idColaborador = ?, cantidadVitrina = ?, cantidadAlmacen = ?, tipo = ? WHERE idProducto = ?");
	query.bindValue(0, md_o_codigo);
	query.bindValue(1, md_o_descripcion);
	query.bindValue(2, md_o_precioCompra);
	query.bindValue(3, md_o_precioVenta);
	query.bindValue(4, md_o_precioDescuento);
	query.bindValue(5, md_o_accesorios);
	query.bindValue(6, md_o_stock);
	query.bindValue(7, md_o_observaciones);
	query.bindValue(8, md_o_Estado_idEstado);
	query.bindValue(9, md_o_Marca_idMarca);
	query.bindValue(10, md_o_idColaborador);
	query.bindValue(11, md_o_cantidadVitrina);
	query.bindValue(12, md_o_cantidadAlmacen);
	query.bindValue(13, md_o_tipo);
	query.bindValue(14, md_o_idProducto);

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

bool object_Producto::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Producto FROM idProducto = ?");
	query.bindValue(0, md_o_idProducto);

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

bool object_Producto::mf_update_cant_vitrina(int cant)
{
    //function mf_update
    //w!

    QSqlQuery query;
    if(cant > 0)
        query.prepare("UPDATE Producto SET cantidadVitrina = cantidadVitrina + ? WHERE idProducto = ?");
    else
        query.prepare("UPDATE Producto SET cantidadVitrina = cantidadVitrina ? WHERE idProducto = ?");

    query.bindValue(0, cant);
    query.bindValue(1, md_o_idProducto);

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

bool object_Producto::mf_update_cant_almacen(int cant)
{
    //function mf_update
    //w!

    QSqlQuery query;
    if(cant > 0)
        query.prepare("UPDATE Producto SET cantidadAlmacen = cantidadAlmacen + ? WHERE idProducto = ?");
    else
        query.prepare("UPDATE Producto SET cantidadAlmacen = cantidadAlmacen  ? WHERE idProducto = ?");

    query.bindValue(0, cant);
    query.bindValue(1, md_o_idProducto);

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

QSqlQueryModel* object_Producto::mf_search(_QSTR cod)
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT p.idProducto as 'Id', p.codigo as 'Codigo',m.nombre as 'Marca',p.descripcion as 'Descrip.', p.precioVenta as 'Precio', p.precioDescuento as 'Descuento',p.accesorios as 'Accesorios', p.stock as 'Cant', p.cantidadVitrina as 'Vitrina', p.cantidadAlmacen as 'Almacen'  FROM Producto p, Marca m WHERE m.idMarca = p.Marca_idMarca AND p.codigo REGEXP '"+cod+"'");
    return model;
}

bool object_Producto::mf_load_code(_QSTR code)
{
    //function mf_load_code
    //w!

    QSqlQuery query;
    md_o_codigo = code;
    query.prepare("SELECT * FROM Producto WHERE codigo = ?");
    query.bindValue(0,md_o_codigo);
    query.exec();

    if(query.next())
    {
        md_o_idProducto = query.value(0).toString();
        md_o_codigo = query.value(1).toString();
        md_o_descripcion = query.value(2).toString();
        md_o_precioCompra = query.value(3).toString();
        md_o_precioVenta = query.value(4).toString();
        md_o_precioDescuento = query.value(5).toString();
        md_o_accesorios = query.value(6).toString();
        md_o_stock = query.value(7).toString();
        md_o_observaciones = query.value(8).toString();
        md_o_Estado_idEstado = query.value(9).toString();
        md_o_Marca_idMarca = query.value(10).toString();
        md_o_idColaborador = query.value(11).toString();
        md_o_cantidadVitrina = query.value(12).toString();
        md_o_cantidadAlmacen = query.value(13).toString();
        md_o_tipo = query.value(14).toString();

        //state OK
        //w!

        return true;
    }else{
        //state FAILED
        //w!

        return false;
    }

}

bool object_Producto::mf_update_cant_stock(int cant)
{
    //function mf_update
    //w!

    QSqlQuery query;
    if(cant > 0)
        query.prepare("UPDATE Producto SET stock = stock + ? WHERE idProducto = ?");
    else
        query.prepare("UPDATE Producto SET stock = stock ? WHERE idProducto = ?");

    query.bindValue(0, cant);
    query.bindValue(1, md_o_idProducto);

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

bool object_Producto::mf_update_cant_stock_price(int cant, double price)
{
    //function mf_update
    //w!

    QSqlQuery query;
    if(cant > 0)
        query.prepare("UPDATE Producto SET stock = stock + ?, precioCompra = ? WHERE idProducto = ?");
    else
        query.prepare("UPDATE Producto SET stock = stock ?, precioCompra = ? WHERE idProducto = ?");

    query.bindValue(0, cant);
    query.bindValue(1, price);
    query.bindValue(2, md_o_idProducto);

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

bool object_Producto::mf_registrarKardex(int cant_k,int stock_k,QString detalle, int tipo)//cant CANTIDAD DE VARIACION SIEMPRE, Stock del Producto
{
    object_Kardex kardex;
    kardex.mf_set_Producto_idProducto(md_o_idProducto);
    kardex.mf_set_Colaborador_idColaborador(QString::number(Sesion::getIdColaborador()));
    kardex.mf_set_fecha(QDateTime::currentDateTime().toString(Qt::ISODate));
    kardex.mf_set_detalle(detalle);
    kardex.mf_set_cant(QString::number(cant_k));
    kardex.mf_set_costo_unit(md_o_precioCompra);
    kardex.mf_set_costo_total(QString::number(cant_k * md_o_precioCompra.toDouble()));
    double costoPromedio = kardex.mf_get_costo_promedio().toDouble();

    //TIPO 1 = NUEVO,AUMENTAR, 2 = QUITAR
    if(tipo == 1)
    {
        costoPromedio = ((costoPromedio * stock_k) + md_o_precioCompra.toDouble())/(stock_k+1);
        kardex.mf_set_costo_promedio(QString::number(costoPromedio));
        kardex.mf_set_saldo_total(QString::number(stock_k+cant_k));
        qDebug()<<"Saldo Total "<<stock_k<<" "<<cant_k<<endl;
        kardex.mf_set_tipo("1"); //1 INGRESO 2 SALIDA
    }

    if(tipo == 2)
    {
        kardex.mf_set_costo_promedio(QString::number(costoPromedio));
        kardex.mf_set_saldo_total(QString::number(stock_k-cant_k));
        kardex.mf_set_tipo("2"); //1 INGRESO 2 SALIDA
    }

    if(!kardex.mf_add())
    {
        return false;
    }
    return true;
}
