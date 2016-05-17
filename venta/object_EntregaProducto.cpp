#include "object_EntregaProducto.h"

object_EntregaProducto::object_EntregaProducto()
{
    //file EntregaProducto
    //function construct_0
    //w!
}

object_EntregaProducto::object_EntregaProducto(_QSTR idEntregaProducto, _QSTR Cliente_idCliente, _QSTR Colaborador_idColaborador, _QSTR Producto_idProducto, _QSTR Venta_idVenta, _QSTR estado, _QSTR fecha)
{
    //file EntregaProducto
    //function construct_1
    //w!

    md_o_idEntregaProducto = idEntregaProducto;
    md_o_Cliente_idCliente = Cliente_idCliente;
    md_o_Colaborador_idColaborador = Colaborador_idColaborador;
    md_o_Producto_idProducto = Producto_idProducto;
    md_o_Venta_idVenta = Venta_idVenta;
    md_o_estado = estado;
    md_o_fecha = fecha;
}
object_EntregaProducto::object_EntregaProducto(_QSTR Cliente_idCliente, _QSTR Colaborador_idColaborador, _QSTR Producto_idProducto, _QSTR Venta_idVenta, _QSTR estado, _QSTR fecha)
{
    //file EntregaProducto
    //function construct_2
    //w!

    md_o_Cliente_idCliente = Cliente_idCliente;
    md_o_Colaborador_idColaborador = Colaborador_idColaborador;
    md_o_Producto_idProducto = Producto_idProducto;
    md_o_Venta_idVenta = Venta_idVenta;
    md_o_estado = estado;
    md_o_fecha = fecha;
}
object_EntregaProducto::~object_EntregaProducto()
{

}


void object_EntregaProducto::mf_set_idEntregaProducto(_QSTR idEntregaProducto)
{
    //function mf_set_idEntregaProducto
    //w!

    md_o_idEntregaProducto = idEntregaProducto;
}
void object_EntregaProducto::mf_set_Cliente_idCliente(_QSTR Cliente_idCliente)
{
    //function mf_set_Cliente_idCliente
    //w!

    md_o_Cliente_idCliente = Cliente_idCliente;
}
void object_EntregaProducto::mf_set_Colaborador_idColaborador(_QSTR Colaborador_idColaborador)
{
    //function mf_set_Colaborador_idColaborador
    //w!

    md_o_Colaborador_idColaborador = Colaborador_idColaborador;
}
void object_EntregaProducto::mf_set_Producto_idProducto(_QSTR Producto_idProducto)
{
    //function mf_set_Producto_idProducto
    //w!

    md_o_Producto_idProducto = Producto_idProducto;
}
void object_EntregaProducto::mf_set_Venta_idVenta(_QSTR Venta_idVenta)
{
    //function mf_set_Venta_idVenta
    //w!

    md_o_Venta_idVenta = Venta_idVenta;
}
void object_EntregaProducto::mf_set_estado(_QSTR estado)
{
    //function mf_set_estado
    //w!

    md_o_estado = estado;
}
void object_EntregaProducto::mf_set_fecha(_QSTR fecha)
{
    //function mf_set_fecha
    //w!

    md_o_fecha = fecha;
}

_QSTR object_EntregaProducto::mf_get_idEntregaProducto()
{
    //function mf_get_idEntregaProducto
    //w!

    return md_o_idEntregaProducto;
}
_QSTR object_EntregaProducto::mf_get_Cliente_idCliente()
{
    //function mf_get_Cliente_idCliente
    //w!

    return md_o_Cliente_idCliente;
}
_QSTR object_EntregaProducto::mf_get_Colaborador_idColaborador()
{
    //function mf_get_Colaborador_idColaborador
    //w!

    return md_o_Colaborador_idColaborador;
}
_QSTR object_EntregaProducto::mf_get_Producto_idProducto()
{
    //function mf_get_Producto_idProducto
    //w!

    return md_o_Producto_idProducto;
}
_QSTR object_EntregaProducto::mf_get_Venta_idVenta()
{
    //function mf_get_Venta_idVenta
    //w!

    return md_o_Venta_idVenta;
}
_QSTR object_EntregaProducto::mf_get_estado()
{
    //function mf_get_estado
    //w!

    return md_o_estado;
}
_QSTR object_EntregaProducto::mf_get_fecha()
{
    //function mf_get_fecha
    //w!

    return md_o_fecha;
}

bool object_EntregaProducto::mf_load(_QSTR pk)
{
    //function mf_load
    //w!

    QSqlQuery query;

    query.prepare("SELECT * FROM EntregaProducto WHERE idEntregaProducto = ?");
    query.bindValue(0,pk);
    query.exec();

    if(query.next())
    {
        md_o_idEntregaProducto = query.value(0).toString();
        md_o_Cliente_idCliente = query.value(1).toString();
        md_o_Colaborador_idColaborador = query.value(2).toString();
        md_o_Producto_idProducto = query.value(3).toString();
        md_o_Venta_idVenta = query.value(4).toString();
        md_o_estado = query.value(5).toString();
        md_o_fecha = query.value(6).toString();

        //state OK
        //w!

        return true;
    }else{
        //state FAILED
        //w!

        return false;
    }
}
bool object_EntregaProducto::mf_add()
{
    //function mf_add
    //w!

    QSqlQuery query;

    string str_query = "INSERT INTO EntregaProducto(";
    str_query += "idEntregaProducto";
    str_query += ", Cliente_idCliente";
    str_query += ", Colaborador_idColaborador";
    str_query += ", Producto_idProducto";
    str_query += ", Venta_idVenta";
    str_query += ", estado";
    str_query += ", fecha";
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
    if (md_o_idEntregaProducto != "")
    {
        query.bindValue(integer++, md_o_idEntregaProducto);
    }
    else
        query.bindValue(integer++, "NULL");
    query.bindValue(integer++, md_o_Cliente_idCliente);
    query.bindValue(integer++, md_o_Colaborador_idColaborador);
    query.bindValue(integer++, md_o_Producto_idProducto);
    query.bindValue(integer++, md_o_Venta_idVenta);
    query.bindValue(integer++, md_o_estado);
    query.bindValue(integer++, md_o_fecha);

    if(query.exec())
    {
        //state OK
        //w!

        return true;

    }else{
        //state FAILED
        //w!

        qDebug()<<md_o_Cliente_idCliente<<" "<<md_o_Colaborador_idColaborador<<" "<<" "<<md_o_Producto_idProducto<<" "<<
                  " "<<md_o_Venta_idVenta<<" "<<md_o_estado<<" "<<md_o_fecha<<" "<< str_query.c_str()<<endl;

        return false;
    }
}

bool object_EntregaProducto::mf_update()
{
    //function mf_update
    //w!

    QSqlQuery query;

    query.prepare("UPDATE EntregaProducto SET Cliente_idCliente = ?, Colaborador_idColaborador = ?, Producto_idProducto = ?, Venta_idVenta = ?, estado = ?, fecha = ? WHERE idEntregaProducto = ?");
    query.bindValue(0, md_o_Cliente_idCliente);
    query.bindValue(1, md_o_Colaborador_idColaborador);
    query.bindValue(2, md_o_Producto_idProducto);
    query.bindValue(3, md_o_Venta_idVenta);
    query.bindValue(4, md_o_estado);
    query.bindValue(5, md_o_fecha);
    query.bindValue(6, md_o_idEntregaProducto);

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

bool object_EntregaProducto::mf_remove()
{
    //function mf_remove
    //w!

    QSqlQuery query;

    query.prepare("DELETE EntregaProducto FROM idEntregaProducto = ?");
    query.bindValue(0, md_o_idEntregaProducto);

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
vector<_QSTR> object_EntregaProducto::mf_listPk(_QSTR pk)
{
    vector<_QSTR> salida;
    QSqlQuery query;
    query.prepare("SELECT idEntregaProducto FROM EntregaProducto WHERE Venta_idVenta = ?");
    query.bindValue(0, pk);
    query.exec();
    while(query.next())
    {
        salida.push_back(query.value(0).toString());
    }
    return salida;
}
