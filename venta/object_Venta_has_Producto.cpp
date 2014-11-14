#include "object_Venta_has_Producto.h"

object_Venta_has_Producto::object_Venta_has_Producto()
{
    //file Venta_has_Producto
    //function construct_0
    //w!
}

object_Venta_has_Producto::object_Venta_has_Producto(_QSTR idVenta_has_Producto, _QSTR Venta_idVenta, _QSTR Producto_idProducto, _QSTR cantidad, _QSTR precio, _QSTR descuento, _QSTR descripcion)
{
    //file Venta_has_Producto
    //function construct_1
    //w!

    md_o_idVenta_has_Producto = idVenta_has_Producto;
    md_o_Venta_idVenta = Venta_idVenta;
    md_o_Producto_idProducto = Producto_idProducto;
    md_o_cantidad = cantidad;
    md_o_precio = precio;
    md_o_descuento = descuento;
    md_o_descripcion = descripcion;
}
object_Venta_has_Producto::object_Venta_has_Producto(_QSTR Venta_idVenta, _QSTR Producto_idProducto, _QSTR cantidad, _QSTR precio, _QSTR descuento, _QSTR descripcion)
{
    //file Venta_has_Producto
    //function construct_2
    //w!

    md_o_Venta_idVenta = Venta_idVenta;
    md_o_Producto_idProducto = Producto_idProducto;
    md_o_cantidad = cantidad;
    md_o_precio = precio;
    md_o_descuento = descuento;
    md_o_descripcion = descripcion;
}
object_Venta_has_Producto::~object_Venta_has_Producto()
{

}


void object_Venta_has_Producto::mf_set_idVenta_has_Producto(_QSTR idVenta_has_Producto)
{
    //function mf_set_idVenta_has_Producto
    //w!

    md_o_idVenta_has_Producto = idVenta_has_Producto;
}
void object_Venta_has_Producto::mf_set_Venta_idVenta(_QSTR Venta_idVenta)
{
    //function mf_set_Venta_idVenta
    //w!

    md_o_Venta_idVenta = Venta_idVenta;
}
void object_Venta_has_Producto::mf_set_Producto_idProducto(_QSTR Producto_idProducto)
{
    //function mf_set_Producto_idProducto
    //w!

    md_o_Producto_idProducto = Producto_idProducto;
}
void object_Venta_has_Producto::mf_set_cantidad(_QSTR cantidad)
{
    //function mf_set_cantidad
    //w!

    md_o_cantidad = cantidad;
}
void object_Venta_has_Producto::mf_set_precio(_QSTR precio)
{
    //function mf_set_precio
    //w!

    md_o_precio = precio;
}
void object_Venta_has_Producto::mf_set_descuento(_QSTR descuento)
{
    //function mf_set_descuento
    //w!

    md_o_descuento = descuento;
}
void object_Venta_has_Producto::mf_set_descripcion(_QSTR descripcion)
{
    //function mf_set_descripcion
    //w!

    md_o_descripcion = descripcion;
}

_QSTR object_Venta_has_Producto::mf_get_idVenta_has_Producto()
{
    //function mf_get_idVenta_has_Producto
    //w!

    return md_o_idVenta_has_Producto;
}
_QSTR object_Venta_has_Producto::mf_get_Venta_idVenta()
{
    //function mf_get_Venta_idVenta
    //w!

    return md_o_Venta_idVenta;
}
_QSTR object_Venta_has_Producto::mf_get_Producto_idProducto()
{
    //function mf_get_Producto_idProducto
    //w!

    return md_o_Producto_idProducto;
}
_QSTR object_Venta_has_Producto::mf_get_cantidad()
{
    //function mf_get_cantidad
    //w!

    return md_o_cantidad;
}
_QSTR object_Venta_has_Producto::mf_get_precio()
{
    //function mf_get_precio
    //w!

    return md_o_precio;
}
_QSTR object_Venta_has_Producto::mf_get_descuento()
{
    //function mf_get_descuento
    //w!

    return md_o_descuento;
}
_QSTR object_Venta_has_Producto::mf_get_descripcion()
{
    //function mf_get_descripcion
    //w!

    return md_o_descripcion;
}

bool object_Venta_has_Producto::mf_load(_QSTR pk)
{
    //function mf_load
    //w!

    QSqlQuery query;

    query.prepare("SELECT * FROM Venta_has_Producto WHERE idVenta_has_Producto = ?");
    query.bindValue(0,pk);
    query.exec();

    if(query.next())
    {
        md_o_idVenta_has_Producto = query.value(0).toString();
        md_o_Venta_idVenta = query.value(1).toString();
        md_o_Producto_idProducto = query.value(2).toString();
        md_o_cantidad = query.value(3).toString();
        md_o_precio = query.value(4).toString();
        md_o_descuento = query.value(5).toString();
        md_o_descripcion = query.value(6).toString();

        //state OK
        //w!

        return true;
    }else{
        //state FAILED
        //w!

        return false;
    }
}
bool object_Venta_has_Producto::mf_add()
{
    //function mf_add
    //w!

    QSqlQuery query;

    string str_query = "INSERT INTO Venta_has_Producto(";
    str_query += "idVenta_has_Producto";
    str_query += ", Venta_idVenta";
    str_query += ", Producto_idProducto";
    str_query += ", cantidad";
    str_query += ", precio";
    str_query += ", descuento";
    str_query += ", descripcion";
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
    if (md_o_idVenta_has_Producto != "")
    {
        query.bindValue(integer++, md_o_idVenta_has_Producto);
    }
    else
        query.bindValue(integer++, NULL);
    query.bindValue(integer++, md_o_Venta_idVenta);
    query.bindValue(integer++, md_o_Producto_idProducto);
    query.bindValue(integer++, md_o_cantidad);
    query.bindValue(integer++, md_o_precio);
    query.bindValue(integer++, md_o_descuento);
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

bool object_Venta_has_Producto::mf_update()
{
    //function mf_update
    //w!

    QSqlQuery query;

    query.prepare("UPDATE Venta_has_Producto SET Venta_idVenta = ?, Producto_idProducto = ?, cantidad = ?, precio = ?, descuento = ?, descripcion = ? WHERE idVenta_has_Producto = ?");
    query.bindValue(0, md_o_Venta_idVenta);
    query.bindValue(1, md_o_Producto_idProducto);
    query.bindValue(2, md_o_cantidad);
    query.bindValue(3, md_o_precio);
    query.bindValue(4, md_o_descuento);
    query.bindValue(5, md_o_descripcion);
    query.bindValue(6, md_o_idVenta_has_Producto);

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

bool object_Venta_has_Producto::mf_remove()
{
    //function mf_remove
    //w!

    QSqlQuery query;

    query.prepare("DELETE Venta_has_Producto FROM idVenta_has_Producto = ?");
    query.bindValue(0, md_o_idVenta_has_Producto);

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

vector<_QSTR> object_Venta_has_Producto::mf_listPk(_QSTR pk)
{
    vector<_QSTR> salida;
    QSqlQuery query;

    query.prepare("SELECT idVenta_has_Producto FROM Venta_has_Producto WHERE Venta_idVenta = ?");
    query.bindValue(0, pk);
    query.exec();
    while(query.next())
    {
        salida.push_back(query.value(0).toString());
    }
    return salida;
}
