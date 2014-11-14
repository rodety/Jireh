#include "object_Producto_has_Compra.h"

object_Producto_has_Compra::object_Producto_has_Compra()
{
    //file Producto_has_Compra
    //function construct_0
    //w!
}

object_Producto_has_Compra::object_Producto_has_Compra(_QSTR idProducto_has_Compra, _QSTR Producto_idProducto, _QSTR Compra_idCompra, _QSTR cantidad, _QSTR precio, _QSTR descripcion)
{
    //file Producto_has_Compra
    //function construct_1
    //w!

    md_o_idProducto_has_Compra = idProducto_has_Compra;
    md_o_Producto_idProducto = Producto_idProducto;
    md_o_Compra_idCompra = Compra_idCompra;
    md_o_cantidad = cantidad;
    md_o_precio = precio;
    md_o_descripcion = descripcion;
}
object_Producto_has_Compra::object_Producto_has_Compra(_QSTR Producto_idProducto, _QSTR Compra_idCompra, _QSTR cantidad, _QSTR precio, _QSTR descripcion)
{
    //file Producto_has_Compra
    //function construct_2
    //w!

    md_o_Producto_idProducto = Producto_idProducto;
    md_o_Compra_idCompra = Compra_idCompra;
    md_o_cantidad = cantidad;
    md_o_precio = precio;
    md_o_descripcion = descripcion;
}
object_Producto_has_Compra::~object_Producto_has_Compra()
{

}


void object_Producto_has_Compra::mf_set_idProducto_has_Compra(_QSTR idProducto_has_Compra)
{
    //function mf_set_idProducto_has_Compra
    //w!

    md_o_idProducto_has_Compra = idProducto_has_Compra;
}
void object_Producto_has_Compra::mf_set_Producto_idProducto(_QSTR Producto_idProducto)
{
    //function mf_set_Producto_idProducto
    //w!

    md_o_Producto_idProducto = Producto_idProducto;
}
void object_Producto_has_Compra::mf_set_Compra_idCompra(_QSTR Compra_idCompra)
{
    //function mf_set_Compra_idCompra
    //w!

    md_o_Compra_idCompra = Compra_idCompra;
}
void object_Producto_has_Compra::mf_set_cantidad(_QSTR cantidad)
{
    //function mf_set_cantidad
    //w!

    md_o_cantidad = cantidad;
}
void object_Producto_has_Compra::mf_set_precio(_QSTR precio)
{
    //function mf_set_precio
    //w!

    md_o_precio = precio;
}
void object_Producto_has_Compra::mf_set_descripcion(_QSTR descripcion)
{
    //function mf_set_descripcion
    //w!

    md_o_descripcion = descripcion;
}

_QSTR object_Producto_has_Compra::mf_get_idProducto_has_Compra()
{
    //function mf_get_idProducto_has_Compra
    //w!

    return md_o_idProducto_has_Compra;
}
_QSTR object_Producto_has_Compra::mf_get_Producto_idProducto()
{
    //function mf_get_Producto_idProducto
    //w!

    return md_o_Producto_idProducto;
}
_QSTR object_Producto_has_Compra::mf_get_Compra_idCompra()
{
    //function mf_get_Compra_idCompra
    //w!

    return md_o_Compra_idCompra;
}
_QSTR object_Producto_has_Compra::mf_get_cantidad()
{
    //function mf_get_cantidad
    //w!

    return md_o_cantidad;
}
_QSTR object_Producto_has_Compra::mf_get_precio()
{
    //function mf_get_precio
    //w!

    return md_o_precio;
}
_QSTR object_Producto_has_Compra::mf_get_descripcion()
{
    //function mf_get_descripcion
    //w!

    return md_o_descripcion;
}

bool object_Producto_has_Compra::mf_load(_QSTR pk)
{
    //function mf_load
    //w!

    QSqlQuery query;

    query.prepare("SELECT * FROM Producto_has_Compra WHERE idProducto_has_Compra = ?");
    query.bindValue(0,pk);
    query.exec();

    if(query.next())
    {
        md_o_idProducto_has_Compra = query.value(0).toString();
        md_o_Producto_idProducto = query.value(1).toString();
        md_o_Compra_idCompra = query.value(2).toString();
        md_o_cantidad = query.value(3).toString();
        md_o_precio = query.value(4).toString();
        md_o_descripcion = query.value(5).toString();

        //state OK
        //w!

        return true;
    }else{
        //state FAILED
        //w!

        return false;
    }
}
bool object_Producto_has_Compra::mf_add()
{
    //function mf_add
    //w!

    QSqlQuery query;

    string str_query = "INSERT INTO Producto_has_Compra(";
    str_query += "idProducto_has_Compra";
    str_query += ", Producto_idProducto";
    str_query += ", Compra_idCompra";
    str_query += ", cantidad";
    str_query += ", precio";
    str_query += ", descripcion";
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
    if (md_o_idProducto_has_Compra != "")
    {
        query.bindValue(integer++, md_o_idProducto_has_Compra);
    }
    else
        query.bindValue(integer++, NULL);
    query.bindValue(integer++, md_o_Producto_idProducto);
    query.bindValue(integer++, md_o_Compra_idCompra);
    query.bindValue(integer++, md_o_cantidad);
    query.bindValue(integer++, md_o_precio);
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

bool object_Producto_has_Compra::mf_update()
{
    //function mf_update
    //w!

    QSqlQuery query;

    query.prepare("UPDATE Producto_has_Compra SET Producto_idProducto = ?, Compra_idCompra = ?, cantidad = ?, precio = ?, descripcion = ? WHERE idProducto_has_Compra = ?");
    query.bindValue(0, md_o_Producto_idProducto);
    query.bindValue(1, md_o_Compra_idCompra);
    query.bindValue(2, md_o_cantidad);
    query.bindValue(3, md_o_precio);
    query.bindValue(4, md_o_descripcion);
    query.bindValue(5, md_o_idProducto_has_Compra);

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

bool object_Producto_has_Compra::mf_remove()
{
    //function mf_remove
    //w!

    QSqlQuery query;

    query.prepare("DELETE Producto_has_Compra FROM idProducto_has_Compra = ?");
    query.bindValue(0, md_o_idProducto_has_Compra);

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
