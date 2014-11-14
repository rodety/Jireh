#include "object_Compra.h"

object_Compra::object_Compra()
{
    //file Compra
    //function construct_0
    //w!
}

object_Compra::object_Compra(_QSTR idCompra, _QSTR fecha, _QSTR montoTotal, _QSTR anulado, _QSTR tipo, _QSTR serie, _QSTR numero)
{
    //file Compra
    //function construct_1
    //w!

    md_o_idCompra = idCompra;
    md_o_fecha = fecha;
    md_o_montoTotal = montoTotal;
    md_o_anulado = anulado;
    md_o_tipo = tipo;
    md_o_serie = serie;
    md_o_numero = numero;
    md_o_lastId = "0";
}
object_Compra::object_Compra(_QSTR fecha, _QSTR montoTotal, _QSTR anulado, _QSTR tipo, _QSTR serie, _QSTR numero)
{
    //file Compra
    //function construct_2
    //w!

    md_o_fecha = fecha;
    md_o_montoTotal = montoTotal;
    md_o_anulado = anulado;
    md_o_tipo = tipo;
    md_o_serie = serie;
    md_o_numero = numero;
}
object_Compra::~object_Compra()
{

}


void object_Compra::mf_set_idCompra(_QSTR idCompra)
{
    //function mf_set_idCompra
    //w!

    md_o_idCompra = idCompra;
}
void object_Compra::mf_set_fecha(_QSTR fecha)
{
    //function mf_set_fecha
    //w!

    md_o_fecha = fecha;
}
void object_Compra::mf_set_montoTotal(_QSTR montoTotal)
{
    //function mf_set_montoTotal
    //w!

    md_o_montoTotal = montoTotal;
}
void object_Compra::mf_set_anulado(_QSTR anulado)
{
    //function mf_set_anulado
    //w!

    md_o_anulado = anulado;
}
void object_Compra::mf_set_tipo(_QSTR tipo)
{
    //function mf_set_tipo
    //w!

    md_o_tipo = tipo;
}
void object_Compra::mf_set_serie(_QSTR serie)
{
    //function mf_set_serie
    //w!

    md_o_serie = serie;
}
void object_Compra::mf_set_numero(_QSTR numero)
{
    //function mf_set_numero
    //w!

    md_o_numero = numero;
}

_QSTR object_Compra::mf_get_idCompra()
{
    //function mf_get_idCompra
    //w!

    return md_o_idCompra;
}
_QSTR object_Compra::mf_get_fecha()
{
    //function mf_get_fecha
    //w!

    return md_o_fecha;
}
_QSTR object_Compra::mf_get_montoTotal()
{
    //function mf_get_montoTotal
    //w!

    return md_o_montoTotal;
}
_QSTR object_Compra::mf_get_anulado()
{
    //function mf_get_anulado
    //w!

    return md_o_anulado;
}
_QSTR object_Compra::mf_get_tipo()
{
    //function mf_get_tipo
    //w!

    return md_o_tipo;
}
_QSTR object_Compra::mf_get_serie()
{
    //function mf_get_serie
    //w!

    return md_o_serie;
}
_QSTR object_Compra::mf_get_numero()
{
    //function mf_get_numero
    //w!

    return md_o_numero;
}

_QSTR object_Compra::mf_get_lastId()
{
    //function mf_get_numero
    //w!

    return md_o_lastId;
}

bool object_Compra::mf_load(_QSTR pk)
{
    //function mf_load
    //w!

    QSqlQuery query;

    query.prepare("SELECT * FROM Compra WHERE idCompra = ?");
    query.bindValue(0,pk);
    query.exec();

    if(query.next())
    {
        md_o_idCompra = query.value(0).toString();
        md_o_fecha = query.value(1).toString();
        md_o_montoTotal = query.value(2).toString();
        md_o_anulado = query.value(3).toString();
        md_o_tipo = query.value(4).toString();
        md_o_serie = query.value(5).toString();
        md_o_numero = query.value(6).toString();

        //state OK
        //w!

        return true;
    }else{
        //state FAILED
        //w!

        return false;
    }
}
bool object_Compra::mf_add()
{
    //function mf_add
    //w!

    QSqlQuery query;

    string str_query = "INSERT INTO Compra(";
    str_query += "idCompra";
    str_query += ", fecha";
    str_query += ", montoTotal";
    str_query += ", anulado";
    str_query += ", tipo";
    str_query += ", serie";
    str_query += ", numero";
    str_query += ") VALUES(";
    str_query += "?";
    str_query += ", ?";
    str_query += ", ?";
    str_query += ", ?";
    str_query += ", ?";
    str_query += ", ?";
    str_query += ", ?";
    str_query += ")";

    query.prepare(QString(str_query.c_str()));
    int integer = 0;
    if (md_o_idCompra != "")
    {
        query.bindValue(integer++, md_o_idCompra);
    }
    else
        query.bindValue(integer++, NULL);
    query.bindValue(integer++, md_o_fecha);
    query.bindValue(integer++, md_o_montoTotal);
    query.bindValue(integer++, md_o_anulado);
    query.bindValue(integer++, md_o_tipo);
    query.bindValue(integer++, md_o_serie);
    query.bindValue(integer++, md_o_numero);

    if(query.exec())
    {
        //state OK
        //w!
        query.exec("SELECT LAST_INSERT_ID()");
        query.next();
        md_o_lastId = query.value(0).toString();
        return true;

    }else{
        //state FAILED
        //w!

        return false;
    }
}

bool object_Compra::mf_update()
{
    //function mf_update
    //w!

    QSqlQuery query;

    query.prepare("UPDATE Compra SET fecha = ?, montoTotal = ?, anulado = ?, tipo = ?, serie = ?, numero = ? WHERE idCompra = ?");
    query.bindValue(0, md_o_fecha);
    query.bindValue(1, md_o_montoTotal);
    query.bindValue(2, md_o_anulado);
    query.bindValue(3, md_o_tipo);
    query.bindValue(4, md_o_serie);
    query.bindValue(5, md_o_numero);
    query.bindValue(6, md_o_idCompra);

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

bool object_Compra::mf_remove()
{
    //function mf_remove
    //w!

    QSqlQuery query;

    query.prepare("DELETE Compra FROM idCompra = ?");
    query.bindValue(0, md_o_idCompra);

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


QSqlQueryModel* object_Compra::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    //model->setQuery("SELECT codigo,descripcion,e.nombre as 'Estado',precioCompra,precioVenta,precioDescuento,stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Talla',ca.nombre as 'Calidad',tpo.nombre as 'Tipo',ge.nombre as 'Genero' FROM Producto p,Otros o,Estado e,Marca m,Color c,Talla t,Calidad ca,TipoOtros tpo, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=o.Producto_idProducto AND o.Color_idColor=c.idColor AND o.Talla_idTalla=t.idTalla AND o.Calidad_idCalidad=ca.idCalidad AND o.TipoOtros_idTipoOtros=tpo.idTipoOtros AND o.Genero_idGenero=ge.idGenero");
    model->setQuery("SELECT c.idCompra as 'id', c.fecha as 'Fecha', CONCAT(c.serie,'-',c.numero) as 'Numero', p.raz_social as 'Proveedor', c.montoTotal as Total, if(c.tipo = '0','Factura','Boleta') as 'Documento', CONCAT(t.nombres,', ',t.primer_apellido) as 'Nombre' FROM Compra c, Proveedor p, Colaborador t, Compra_has_Proveedor cp WHERE c.idCompra = cp.Compra_idCompra  AND p.idProveedor = cp.Proveedor_idProveedor AND t.idColaborador = cp.Colaborador_idColaborador");
    return model;
}
QVector<object_Producto_has_Compra>  object_Compra::mf_get_listProducto_has_Compra()
{
    //function mf_load
    //w!

    QSqlQuery query;
    QVector<object_Producto_has_Compra> vProducto_has_Compra;


    query.prepare(" select * from Producto_has_Compra where Compra_idCompra = ?");
    query.bindValue(0,md_o_idCompra);
    query.exec();

    while(query.next())
    {
        object_Producto_has_Compra pc;
        pc.mf_set_idProducto_has_Compra(query.value(0).toString());
        pc.mf_set_Producto_idProducto(query.value(1).toString());
        pc.mf_set_Compra_idCompra(query.value(2).toString());
        pc.mf_set_cantidad(query.value(3).toString());
        pc.mf_set_precio(query.value(4).toString());
        pc.mf_set_descripcion(query.value(5).toString());
        vProducto_has_Compra.push_back(pc);

    }
    return vProducto_has_Compra;

}

QSqlQueryModel * object_Compra::mostrarByProduct(_QSTR idProducto)
{
    QSqlQueryModel* model=new QSqlQueryModel;
    //model->setQuery("SELECT codigo,descripcion,e.nombre as 'Estado',precioCompra,precioVenta,precioDescuento,stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Talla',ca.nombre as 'Calidad',tpo.nombre as 'Tipo',ge.nombre as 'Genero' FROM Producto p,Otros o,Estado e,Marca m,Color c,Talla t,Calidad ca,TipoOtros tpo, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=o.Producto_idProducto AND o.Color_idColor=c.idColor AND o.Talla_idTalla=t.idTalla AND o.Calidad_idCalidad=ca.idCalidad AND o.TipoOtros_idTipoOtros=tpo.idTipoOtros AND o.Genero_idGenero=ge.idGenero");
    model->setQuery("SELECT idCompra,fecha,montoTotal,anulado,serie,numero,cantidad,precio,descripcion FROM Compra c, Producto_has_Compra pc WHERE c.idCompra = pc.Compra_idCompra AND pc.Producto_idProducto = " +idProducto);
    return model;
}
