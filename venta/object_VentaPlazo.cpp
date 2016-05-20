#include "object_VentaPlazo.h"

object_VentaPlazo::object_VentaPlazo()
{
//file VentaPlazo
//function construct_0
//w!
}

object_VentaPlazo::object_VentaPlazo(_QSTR idVentaPlazo, _QSTR Venta_idVenta, _QSTR Venta_has_Tarjeta_idVenta_has_Tarjeta, _QSTR Colaborador_idColaborador, _QSTR Tienda_idTienda, _QSTR montoEfectivo, _QSTR montoTarjeta, _QSTR fecha, _QSTR numeroDocumento, _QSTR serieDocumento, _QSTR registro)
{
//file VentaPlazo
//function construct_1
//w!

    md_o_idVentaPlazo = idVentaPlazo;
    md_o_Venta_idVenta = Venta_idVenta;
    md_o_Venta_has_Tarjeta_idVenta_has_Tarjeta = Venta_has_Tarjeta_idVenta_has_Tarjeta;
    md_o_Colaborador_idColaborador = Colaborador_idColaborador;
    md_o_Tienda_idTienda = Tienda_idTienda;
    md_o_montoEfectivo = montoEfectivo;
    md_o_montoTarjeta = montoTarjeta;
    md_o_fecha = fecha;
    md_o_numeroDocumento = numeroDocumento;
    md_o_serieDocumento = serieDocumento;
    md_o_registro = registro;
}
object_VentaPlazo::object_VentaPlazo(_QSTR Venta_idVenta, _QSTR Venta_has_Tarjeta_idVenta_has_Tarjeta, _QSTR Colaborador_idColaborador, _QSTR Tienda_idTienda, _QSTR montoEfectivo, _QSTR montoTarjeta, _QSTR fecha, _QSTR numeroDocumento, _QSTR serieDocumento, _QSTR registro)
{
    //file VentaPlazo
    //function construct_2
    //w!

    md_o_Venta_idVenta = Venta_idVenta;
    md_o_Venta_has_Tarjeta_idVenta_has_Tarjeta = Venta_has_Tarjeta_idVenta_has_Tarjeta;
    md_o_Colaborador_idColaborador = Colaborador_idColaborador;
    md_o_Tienda_idTienda = Tienda_idTienda;
    md_o_montoEfectivo = montoEfectivo;
    md_o_montoTarjeta = montoTarjeta;
    md_o_fecha = fecha;
    md_o_numeroDocumento = numeroDocumento;
    md_o_serieDocumento = serieDocumento;
    md_o_registro = registro;
}
object_VentaPlazo::~object_VentaPlazo()
{

}


void object_VentaPlazo::mf_set_idVentaPlazo(_QSTR idVentaPlazo)
{
//function mf_set_idVentaPlazo
//w!

md_o_idVentaPlazo = idVentaPlazo;
}
void object_VentaPlazo::mf_set_Venta_idVenta(_QSTR Venta_idVenta)
{
    //function mf_set_Venta_idVenta
    //w!

    md_o_Venta_idVenta = Venta_idVenta;
}
void object_VentaPlazo::mf_set_Venta_has_Tarjeta_idVenta_has_Tarjeta(_QSTR Venta_has_Tarjeta_idVenta_has_Tarjeta)
{
    //function mf_set_Venta_has_Tarjeta_idVenta_has_Tarjeta
    //w!

    md_o_Venta_has_Tarjeta_idVenta_has_Tarjeta = Venta_has_Tarjeta_idVenta_has_Tarjeta;
}
void object_VentaPlazo::mf_set_Colaborador_idColaborador(_QSTR Colaborador_idColaborador)
{
    //function mf_set_Colaborador_idColaborador
    //w!

    md_o_Colaborador_idColaborador = Colaborador_idColaborador;
}
void object_VentaPlazo::mf_set_Tienda_idTienda(_QSTR Tienda_idTienda)
{
    //function mf_set_Tienda_idTienda
    //w!

    md_o_Tienda_idTienda = Tienda_idTienda;
}
void object_VentaPlazo::mf_set_montoEfectivo(_QSTR montoEfectivo)
{
    //function mf_set_montoEfectivo
    //w!

    md_o_montoEfectivo = montoEfectivo;
}
void object_VentaPlazo::mf_set_montoTarjeta(_QSTR montoTarjeta)
{
    //function mf_set_montoTarjeta
    //w!

    md_o_montoTarjeta = montoTarjeta;
}
void object_VentaPlazo::mf_set_fecha(_QSTR fecha)
{
    //function mf_set_fecha
    //w!

    md_o_fecha = fecha;
}
void object_VentaPlazo::mf_set_numeroDocumento(_QSTR numeroDocumento)
{
    //function mf_set_numeroDocumento
    //w!

    md_o_numeroDocumento = numeroDocumento;
}
void object_VentaPlazo::mf_set_serieDocumento(_QSTR serieDocumento)
{
    //function mf_set_serieDocumento
    //w!

    md_o_serieDocumento = serieDocumento;
}
void object_VentaPlazo::mf_set_registro(_QSTR registro)
{
    //function mf_set_registro
    //w!

    md_o_registro = registro;
}

_QSTR object_VentaPlazo::mf_get_idVentaPlazo()
{
    //function mf_get_idVentaPlazo
    //w!

    return md_o_idVentaPlazo;
}
_QSTR object_VentaPlazo::mf_get_Venta_idVenta()
{
    //function mf_get_Venta_idVenta
    //w!

    return md_o_Venta_idVenta;
}
_QSTR object_VentaPlazo::mf_get_Venta_has_Tarjeta_idVenta_has_Tarjeta()
{
    //function mf_get_Venta_has_Tarjeta_idVenta_has_Tarjeta
    //w!

    return md_o_Venta_has_Tarjeta_idVenta_has_Tarjeta;
}
_QSTR object_VentaPlazo::mf_get_Colaborador_idColaborador()
{
    //function mf_get_Colaborador_idColaborador
    //w!

    return md_o_Colaborador_idColaborador;
}
_QSTR object_VentaPlazo::mf_get_Tienda_idTienda()
{
    //function mf_get_Tienda_idTienda
    //w!

    return md_o_Tienda_idTienda;
}
_QSTR object_VentaPlazo::mf_get_montoEfectivo()
{
    //function mf_get_montoEfectivo
    //w!

    return md_o_montoEfectivo;
}
_QSTR object_VentaPlazo::mf_get_montoTarjeta()
{
    //function mf_get_montoTarjeta
    //w!

    return md_o_montoTarjeta;
}
_QSTR object_VentaPlazo::mf_get_fecha()
{
    //function mf_get_fecha
    //w!

    return md_o_fecha;
}
_QSTR object_VentaPlazo::mf_get_numeroDocumento()
{
    //function mf_get_numeroDocumento
    //w!

    return md_o_numeroDocumento;
}
_QSTR object_VentaPlazo::mf_get_serieDocumento()
{
    //function mf_get_serieDocumento
    //w!

    return md_o_serieDocumento;
}
_QSTR object_VentaPlazo::mf_get_registro()
{
    //function mf_get_registro
    //w!

    return md_o_registro;
}

bool object_VentaPlazo::mf_load(_QSTR pk)
{
    //function mf_load
    //w!

    QSqlQuery query;

    query.prepare("SELECT * FROM VentaPlazo WHERE idVentaPlazo = ?");
    query.bindValue(0,pk);
    query.exec();

    if(query.next())
    {
        md_o_idVentaPlazo = query.value(0).toString();
        md_o_Venta_idVenta = query.value(1).toString();
        md_o_Venta_has_Tarjeta_idVenta_has_Tarjeta = query.value(2).toString();
        md_o_Colaborador_idColaborador = query.value(3).toString();
        md_o_Tienda_idTienda = query.value(4).toString();
        md_o_montoEfectivo = query.value(5).toString();
        md_o_montoTarjeta = query.value(6).toString();
        md_o_fecha = query.value(7).toString();
        md_o_numeroDocumento = query.value(8).toString();
        md_o_serieDocumento = query.value(9).toString();
        md_o_registro = query.value(10).toString();

        //state OK
        //w!

        return true;
    }else{
        //state FAILED
        //w!

        return false;
    }
}
bool object_VentaPlazo::mf_add()
{
    //function mf_add
    //w!

    QSqlQuery query;

    QString str_query = "INSERT INTO VentaPlazo(";
    str_query += "idVentaPlazo";
    str_query += ", Venta_idVenta";
    str_query += ", Venta_has_Tarjeta_idVenta_has_Tarjeta";
    str_query += ", Colaborador_idColaborador";
    str_query += ", Tienda_idTienda";
    str_query += ", montoEfectivo";
    str_query += ", montoTarjeta";
    str_query += ", fecha";
    str_query += ", numeroDocumento";
    str_query += ", serieDocumento";
    str_query += ", registro";
    str_query += ") VALUES(";
    str_query += "NULL";
    str_query += ", "+md_o_Venta_idVenta;
    str_query += ", "+md_o_Venta_has_Tarjeta_idVenta_has_Tarjeta;
    str_query += ", "+md_o_Colaborador_idColaborador;
    str_query += ", "+md_o_Tienda_idTienda;
    str_query += ", "+md_o_montoEfectivo;
    str_query += ", "+md_o_montoTarjeta;
    str_query += ", '"+md_o_fecha;
    str_query += "', "+md_o_numeroDocumento;
    str_query += ", '"+md_o_serieDocumento;
    str_query += "', "+md_o_registro;
    str_query += ")";


    qDebug()<<str_query<<endl;
    if(query.exec(str_query))
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

bool object_VentaPlazo::mf_update()
{
//function mf_update
//w!

    QSqlQuery query;

    query.prepare("UPDATE VentaPlazo SET Venta_idVenta = ?, Venta_has_Tarjeta_idVenta_has_Tarjeta = ?, Colaborador_idColaborador = ?, Tienda_idTienda = ?, montoEfectivo = ?, montoTarjeta = ?, fecha = ?, numeroDocumento = ?, serieDocumento = ?, registro = ? WHERE idVentaPlazo = ?");
    query.bindValue(0, md_o_Venta_idVenta);
    query.bindValue(1, md_o_Venta_has_Tarjeta_idVenta_has_Tarjeta);
    query.bindValue(2, md_o_Colaborador_idColaborador);
    query.bindValue(3, md_o_Tienda_idTienda);
    query.bindValue(4, md_o_montoEfectivo);
    query.bindValue(5, md_o_montoTarjeta);
    query.bindValue(6, md_o_fecha);
    query.bindValue(7, md_o_numeroDocumento);
    query.bindValue(8, md_o_serieDocumento);
    query.bindValue(9, md_o_registro);
    query.bindValue(10, md_o_idVentaPlazo);

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

bool object_VentaPlazo::mf_remove()
{
//function mf_remove
//w!

QSqlQuery query;

query.prepare("DELETE VentaPlazo FROM idVentaPlazo = ?");
query.bindValue(0, md_o_idVentaPlazo);

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
vector<_QSTR> object_VentaPlazo::mf_listPk(_QSTR pk)
{
    vector<_QSTR> salida;
    QSqlQuery query;
    query.prepare("SELECT idVentaPlazo FROM VentaPlazo WHERE Venta_idVenta = ?");
    query.bindValue(0, pk);
    query.exec();
    while(query.next())
    {
        salida.push_back(query.value(0).toString());
    }
    return salida;
}
QSqlQueryModel *object_VentaPlazo::mf_show()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    QString consulta;
    consulta = "SELECT  v.Venta_has_Tarjeta_idVenta_has_Tarjeta as id, v.idVentaPlazo, v.fecha as 'Fecha', CONCAT(v.serieDocumento,'-',v.numeroDocumento) as 'Numero', v.montoEfectivo as 'Efectivo',v.montoTarjeta as 'Tarjeta', c.nombres as 'Colaborador', t.nombre as 'Tienda', if(v.registro = '0','No Registrado','Registrado') as 'Registro' FROM VentaPlazo v, Colaborador c, Tienda t WHERE v.Venta_idVenta = '"+md_o_Venta_idVenta+"' AND c.idColaborador = '"+ md_o_Colaborador_idColaborador+"' AND  t.idTienda ='"+md_o_Tienda_idTienda+"' ORDER BY v.fecha";
    QSqlQuery query(consulta);
    model->setQuery(query);
    return model;
}
bool object_VentaPlazo::mf_verifyRegister(_QSTR id)
{
    QSqlQuery query("select count(*) from VentaPlazo where Venta_idVenta = '"+id+"' and registro = '0'");
    qDebug()<<"id "<<id<<endl;
    query.next();
    if(query.value(0).toInt() == 0)
        return true;
    else
        return false;
}
bool object_VentaPlazo::mf_register(_QSTR pk)
{
    QSqlQuery query;

    query.prepare("UPDATE VentaPlazo SET registro = ? WHERE idVentaPlazo = ?");

    query.bindValue(0, "1");
    query.bindValue(1, pk);

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
