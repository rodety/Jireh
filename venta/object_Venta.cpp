#include "object_Venta.h"

object_Venta::object_Venta()
{
	//file Venta
	//function construct_0
	//w!
}

object_Venta::object_Venta(_QSTR idVenta, _QSTR fechaPreVenta, _QSTR fechaCancelacion, _QSTR serieDocumento, _QSTR numeroDocumento, _QSTR formaPago, _QSTR codigoTransaccion, _QSTR plazo, _QSTR montoTotal, _QSTR fechaEntrega, _QSTR montoAdelanto, _QSTR Entregado, _QSTR Anulado, _QSTR pendiente, _QSTR Tienda_idTienda, _QSTR Cliente_idCliente, _QSTR Colaborador_idColaborador, _QSTR tipoDocumento)
{
	//file Venta
	//function construct_1
	//w!

	md_o_idVenta = idVenta;
	md_o_fechaPreVenta = fechaPreVenta;
	md_o_fechaCancelacion = fechaCancelacion;
	md_o_serieDocumento = serieDocumento;
	md_o_numeroDocumento = numeroDocumento;
	md_o_formaPago = formaPago;
	md_o_codigoTransaccion = codigoTransaccion;
	md_o_plazo = plazo;
	md_o_montoTotal = montoTotal;
	md_o_fechaEntrega = fechaEntrega;
	md_o_montoAdelanto = montoAdelanto;
	md_o_Entregado = Entregado;
	md_o_Anulado = Anulado;
	md_o_pendiente = pendiente;
	md_o_Tienda_idTienda = Tienda_idTienda;
	md_o_Cliente_idCliente = Cliente_idCliente;
	md_o_Colaborador_idColaborador = Colaborador_idColaborador;
	md_o_tipoDocumento = tipoDocumento;
}
object_Venta::object_Venta(_QSTR fechaPreVenta, _QSTR fechaCancelacion, _QSTR serieDocumento, _QSTR numeroDocumento, _QSTR formaPago, _QSTR codigoTransaccion, _QSTR plazo, _QSTR montoTotal, _QSTR fechaEntrega, _QSTR montoAdelanto, _QSTR Entregado, _QSTR Anulado, _QSTR pendiente, _QSTR Tienda_idTienda, _QSTR Cliente_idCliente, _QSTR Colaborador_idColaborador, _QSTR tipoDocumento)
{
	//file Venta
	//function construct_2
	//w!

	md_o_fechaPreVenta = fechaPreVenta;
	md_o_fechaCancelacion = fechaCancelacion;
	md_o_serieDocumento = serieDocumento;
	md_o_numeroDocumento = numeroDocumento;
	md_o_formaPago = formaPago;
	md_o_codigoTransaccion = codigoTransaccion;
	md_o_plazo = plazo;
	md_o_montoTotal = montoTotal;
	md_o_fechaEntrega = fechaEntrega;
	md_o_montoAdelanto = montoAdelanto;
	md_o_Entregado = Entregado;
	md_o_Anulado = Anulado;
	md_o_pendiente = pendiente;
	md_o_Tienda_idTienda = Tienda_idTienda;
	md_o_Cliente_idCliente = Cliente_idCliente;
	md_o_Colaborador_idColaborador = Colaborador_idColaborador;
	md_o_tipoDocumento = tipoDocumento;
}
object_Venta::~object_Venta()
{

}


void object_Venta::mf_set_idVenta(_QSTR idVenta)
{
	//function mf_set_idVenta
	//w!

	md_o_idVenta = idVenta;
}
void object_Venta::mf_set_fechaPreVenta(_QSTR fechaPreVenta)
{
	//function mf_set_fechaPreVenta
	//w!

	md_o_fechaPreVenta = fechaPreVenta;
}
void object_Venta::mf_set_fechaCancelacion(_QSTR fechaCancelacion)
{
	//function mf_set_fechaCancelacion
	//w!

	md_o_fechaCancelacion = fechaCancelacion;
}
void object_Venta::mf_set_serieDocumento(_QSTR serieDocumento)
{
	//function mf_set_serieDocumento
	//w!

	md_o_serieDocumento = serieDocumento;
}
void object_Venta::mf_set_numeroDocumento(_QSTR numeroDocumento)
{
	//function mf_set_numeroDocumento
	//w!

	md_o_numeroDocumento = numeroDocumento;
}
void object_Venta::mf_set_formaPago(_QSTR formaPago)
{
	//function mf_set_formaPago
	//w!

	md_o_formaPago = formaPago;
}
void object_Venta::mf_set_codigoTransaccion(_QSTR codigoTransaccion)
{
	//function mf_set_codigoTransaccion
	//w!

	md_o_codigoTransaccion = codigoTransaccion;
}
void object_Venta::mf_set_plazo(_QSTR plazo)
{
	//function mf_set_plazo
	//w!

	md_o_plazo = plazo;
}
void object_Venta::mf_set_montoTotal(_QSTR montoTotal)
{
	//function mf_set_montoTotal
	//w!

	md_o_montoTotal = montoTotal;
}
void object_Venta::mf_set_fechaEntrega(_QSTR fechaEntrega)
{
	//function mf_set_fechaEntrega
	//w!

	md_o_fechaEntrega = fechaEntrega;
}
void object_Venta::mf_set_montoAdelanto(_QSTR montoAdelanto)
{
	//function mf_set_montoAdelanto
	//w!

	md_o_montoAdelanto = montoAdelanto;
}
void object_Venta::mf_set_Entregado(_QSTR Entregado)
{
	//function mf_set_Entregado
	//w!

	md_o_Entregado = Entregado;
}
void object_Venta::mf_set_Anulado(_QSTR Anulado)
{
	//function mf_set_Anulado
	//w!

	md_o_Anulado = Anulado;
}
void object_Venta::mf_set_pendiente(_QSTR pendiente)
{
	//function mf_set_pendiente
	//w!

	md_o_pendiente = pendiente;
}
void object_Venta::mf_set_Tienda_idTienda(_QSTR Tienda_idTienda)
{
	//function mf_set_Tienda_idTienda
	//w!

	md_o_Tienda_idTienda = Tienda_idTienda;
}
void object_Venta::mf_set_Cliente_idCliente(_QSTR Cliente_idCliente)
{
	//function mf_set_Cliente_idCliente
	//w!

	md_o_Cliente_idCliente = Cliente_idCliente;
}
void object_Venta::mf_set_Colaborador_idColaborador(_QSTR Colaborador_idColaborador)
{
	//function mf_set_Colaborador_idColaborador
	//w!

	md_o_Colaborador_idColaborador = Colaborador_idColaborador;
}
void object_Venta::mf_set_tipoDocumento(_QSTR tipoDocumento)
{
	//function mf_set_tipoDocumento
	//w!

	md_o_tipoDocumento = tipoDocumento;
}

_QSTR object_Venta::mf_get_idVenta()
{
	//function mf_get_idVenta
	//w!

	return md_o_idVenta;
}
_QSTR object_Venta::mf_get_fechaPreVenta()
{
	//function mf_get_fechaPreVenta
	//w!

	return md_o_fechaPreVenta;
}
_QSTR object_Venta::mf_get_fechaCancelacion()
{
	//function mf_get_fechaCancelacion
	//w!

	return md_o_fechaCancelacion;
}
_QSTR object_Venta::mf_get_serieDocumento()
{
	//function mf_get_serieDocumento
	//w!

	return md_o_serieDocumento;
}
_QSTR object_Venta::mf_get_numeroDocumento()
{
	//function mf_get_numeroDocumento
	//w!

	return md_o_numeroDocumento;
}
_QSTR object_Venta::mf_get_formaPago()
{
	//function mf_get_formaPago
	//w!

	return md_o_formaPago;
}
_QSTR object_Venta::mf_get_codigoTransaccion()
{
	//function mf_get_codigoTransaccion
	//w!

	return md_o_codigoTransaccion;
}
_QSTR object_Venta::mf_get_plazo()
{
	//function mf_get_plazo
	//w!

	return md_o_plazo;
}
_QSTR object_Venta::mf_get_montoTotal()
{
	//function mf_get_montoTotal
	//w!

	return md_o_montoTotal;
}
_QSTR object_Venta::mf_get_fechaEntrega()
{
	//function mf_get_fechaEntrega
	//w!

	return md_o_fechaEntrega;
}
_QSTR object_Venta::mf_get_montoAdelanto()
{
	//function mf_get_montoAdelanto
	//w!

	return md_o_montoAdelanto;
}
_QSTR object_Venta::mf_get_Entregado()
{
	//function mf_get_Entregado
	//w!

	return md_o_Entregado;
}
_QSTR object_Venta::mf_get_Anulado()
{
	//function mf_get_Anulado
	//w!

	return md_o_Anulado;
}
_QSTR object_Venta::mf_get_pendiente()
{
	//function mf_get_pendiente
	//w!

	return md_o_pendiente;
}
_QSTR object_Venta::mf_get_Tienda_idTienda()
{
	//function mf_get_Tienda_idTienda
	//w!

	return md_o_Tienda_idTienda;
}
_QSTR object_Venta::mf_get_Cliente_idCliente()
{
	//function mf_get_Cliente_idCliente
	//w!

	return md_o_Cliente_idCliente;
}
_QSTR object_Venta::mf_get_Colaborador_idColaborador()
{
	//function mf_get_Colaborador_idColaborador
	//w!

	return md_o_Colaborador_idColaborador;
}
_QSTR object_Venta::mf_get_tipoDocumento()
{
	//function mf_get_tipoDocumento
	//w!

	return md_o_tipoDocumento;
}

bool object_Venta::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Venta WHERE idVenta = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idVenta = query.value(0).toString();
		md_o_fechaPreVenta = query.value(1).toString();
		md_o_fechaCancelacion = query.value(2).toString();
		md_o_serieDocumento = query.value(3).toString();
		md_o_numeroDocumento = query.value(4).toString();
		md_o_formaPago = query.value(5).toString();
		md_o_codigoTransaccion = query.value(6).toString();
		md_o_plazo = query.value(7).toString();
		md_o_montoTotal = query.value(8).toString();
		md_o_fechaEntrega = query.value(9).toString();
		md_o_montoAdelanto = query.value(10).toString();
		md_o_Entregado = query.value(11).toString();
		md_o_Anulado = query.value(12).toString();
		md_o_pendiente = query.value(13).toString();
		md_o_Tienda_idTienda = query.value(14).toString();
		md_o_Cliente_idCliente = query.value(15).toString();
		md_o_Colaborador_idColaborador = query.value(16).toString();
		md_o_tipoDocumento = query.value(17).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Venta::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Venta(";	
    str_query += " fechaPreVenta";
	str_query += ", fechaCancelacion";
	str_query += ", serieDocumento";
	str_query += ", numeroDocumento";
	str_query += ", formaPago";
	str_query += ", codigoTransaccion";
	str_query += ", plazo";
	str_query += ", montoTotal";
	str_query += ", fechaEntrega";
	str_query += ", montoAdelanto";
	str_query += ", Entregado";
	str_query += ", Anulado";
	str_query += ", pendiente";
	str_query += ", Tienda_idTienda";
	str_query += ", Cliente_idCliente";
	str_query += ", Colaborador_idColaborador";
	str_query += ", tipoDocumento";
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
	str_query += ", ?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;

	query.bindValue(integer++, md_o_fechaPreVenta);
	query.bindValue(integer++, md_o_fechaCancelacion);
	query.bindValue(integer++, md_o_serieDocumento);
	query.bindValue(integer++, md_o_numeroDocumento);
	query.bindValue(integer++, md_o_formaPago);
	query.bindValue(integer++, md_o_codigoTransaccion);
	query.bindValue(integer++, md_o_plazo);
	query.bindValue(integer++, md_o_montoTotal);
	query.bindValue(integer++, md_o_fechaEntrega);
	query.bindValue(integer++, md_o_montoAdelanto);
	query.bindValue(integer++, md_o_Entregado);
	query.bindValue(integer++, md_o_Anulado);
	query.bindValue(integer++, md_o_pendiente);
	query.bindValue(integer++, md_o_Tienda_idTienda);
	query.bindValue(integer++, md_o_Cliente_idCliente);
	query.bindValue(integer++, md_o_Colaborador_idColaborador);
	query.bindValue(integer++, md_o_tipoDocumento);

	if(query.exec())
	{
		//state OK
		//w!
        query.exec("SELECT LAST_INSERT_ID()");
        query.next();
        md_o_lastIdVenta = query.value(0).toString();
        return true;

	}else{
		//state FAILED
		//w!

		return false;
	}
}

bool object_Venta::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Venta SET fechaPreVenta = ?, fechaCancelacion = ?, serieDocumento = ?, numeroDocumento = ?, formaPago = ?, codigoTransaccion = ?, plazo = ?, montoTotal = ?, fechaEntrega = ?, montoAdelanto = ?, Entregado = ?, Anulado = ?, pendiente = ?, Tienda_idTienda = ?, Cliente_idCliente = ?, Colaborador_idColaborador = ?, tipoDocumento = ? WHERE idVenta = ?");
	query.bindValue(0, md_o_fechaPreVenta);
	query.bindValue(1, md_o_fechaCancelacion);
	query.bindValue(2, md_o_serieDocumento);
	query.bindValue(3, md_o_numeroDocumento);
	query.bindValue(4, md_o_formaPago);
	query.bindValue(5, md_o_codigoTransaccion);
	query.bindValue(6, md_o_plazo);
	query.bindValue(7, md_o_montoTotal);
	query.bindValue(8, md_o_fechaEntrega);
	query.bindValue(9, md_o_montoAdelanto);
	query.bindValue(10, md_o_Entregado);
	query.bindValue(11, md_o_Anulado);
	query.bindValue(12, md_o_pendiente);
	query.bindValue(13, md_o_Tienda_idTienda);
	query.bindValue(14, md_o_Cliente_idCliente);
	query.bindValue(15, md_o_Colaborador_idColaborador);
	query.bindValue(16, md_o_tipoDocumento);
	query.bindValue(17, md_o_idVenta);

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

bool object_Venta::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Venta FROM idVenta = ?");
	query.bindValue(0, md_o_idVenta);

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

_QSTR object_Venta::mf_get_lastIdVenta()
{
    return md_o_lastIdVenta;
}
QSqlQueryModel* object_Venta::mf_show(int tipo)
{
    QSqlQueryModel* model=new QSqlQueryModel;
    QString consulta;
    //[1,2,3] [Forma de Pago,Tipo Documento,Colaborador]

    if(md_o_tipoDocumento == "0")
        md_o_tipoDocumento = "%";
    if(md_o_formaPago == "0")
        md_o_formaPago = "%";
    if(md_o_Colaborador_idColaborador == "0")
        md_o_Colaborador_idColaborador = "%";



    switch(tipo)
    {
        //TODOS
        case 0:
        {


        consulta = "SELECT v.idVenta as 'Id', v.fechaEntrega as 'Fecha Entrega',v.numeroDocumento as 'Num Doc.', CONCAT(c.nombres,', ',c.primer_apellido) as 'Raz. Social', v.montoTotal as 'M. Total', v.montoAdelanto as 'M. Adelanto', if(v.Entregado = '0','No Entregado','Entregado') as 'Estado', if(v.pendiente = '0', 'No Registrado','Registrado') as 'Reg. Tarjeta' FROM Venta v, Cliente c WHERE  v.Tienda_idTienda = "+md_o_Tienda_idTienda+" AND  v.fechaEntrega >= '"+md_o_dateFrom+"' AND c.idCliente = v.Cliente_idCliente AND v.Anulado != '1' AND (v.montoAdelanto < v.montoTotal OR v.Entregado = '0' OR v.pendiente = '0' ) ORDER BY v.fechaEntrega";
            break;
        }
        //CONSULTAS ESPECIFICAS DE AGENDA

        // PENDIENTE DE PAGO
        case 8:
        {
            consulta = "SELECT v.idVenta as 'Id', v.fechaEntrega as 'Fecha Entrega',v.numeroDocumento as 'Num Doc.', CONCAT(c.nombres,', ',c.primer_apellido) as 'Raz. Social', v.montoTotal as 'M. Total', v.montoAdelanto as 'M. Adelanto', if(v.Entregado = '0','No Entregado','Entregado') as 'Estado', if(v.pendiente = '0', 'No Registrado','Registrado') as 'Reg. Tarjeta' FROM Venta v, Cliente c WHERE  v.Tienda_idTienda = "+md_o_Tienda_idTienda+" AND  v.fechaEntrega >= '"+md_o_dateFrom+"' AND c.idCliente = v.Cliente_idCliente AND v.montoAdelanto < v.montoTotal AND v.Anulado != '1' ORDER BY v.fechaEntrega";
            break;
        }
        // PENDIENTE DE ENTREGA
        case 9:
        {
            consulta = "SELECT v.idVenta as 'Id', v.fechaEntrega as 'Fecha Entrega',v.numeroDocumento as 'Num Doc.', CONCAT(c.nombres,', ',c.primer_apellido) as 'Raz. Social', v.montoTotal as 'M. Total', v.montoAdelanto as 'M. Adelanto', if(v.Entregado = '0','No Entregado','Entregado') as 'Estado', if(v.pendiente = '0', 'No Registrado','Registrado') as 'Reg. Tarjeta' FROM Venta v, Cliente c WHERE  v.Tienda_idTienda = "+md_o_Tienda_idTienda+" AND v.fechaEntrega >= '"+md_o_dateFrom+"' AND c.idCliente = v.Cliente_idCliente AND v.Entregado = '0' AND v.Anulado != '1' ORDER BY v.fechaEntrega";
            qDebug()<<consulta<<endl;
            break;
        }
        // PENDIENTE DE REGISTRO DE TARJETA
        case 10:
        {
        consulta = "SELECT v.idVenta as 'Id', v.fechaEntrega as 'Fecha Entrega',v.numeroDocumento as 'Num Doc.', CONCAT(c.nombres,', ',c.primer_apellido) as 'Raz. Social', v.montoTotal as 'M. Total', v.montoAdelanto as 'M. Adelanto', if(v.Entregado = '0','No Entregado','Entregado') as 'Estado', if(v.pendiente = '0', 'No Registrado','Registrado') as 'Reg. Tarjeta' FROM Venta v, Cliente c WHERE  v.Tienda_idTienda = "+md_o_Tienda_idTienda+" AND v.fechaEntrega >= '"+md_o_dateFrom+"' AND c.idCliente = v.Cliente_idCliente AND v.pendiente = '0' AND v.Anulado != '1' ORDER BY v.fechaEntrega";
            break;
        }
        case 11:
        {
        consulta = "SELECT v.idVenta as 'Id', v.fechaPreventa as 'Fecha - Hora',v.numeroDocumento as 'Num Doc.', CONCAT(c.nombres,', ',c.primer_apellido) as 'Raz. Social', v.montoTotal as 'M. Total', v.montoAdelanto as 'M. Adelanto', if(v.Entregado = '0','No Entregado','Entregado') as 'Estado', if(v.pendiente = '0', 'No Registrado','Registrado') as 'Reg. Tarjeta' FROM Venta v, Cliente c WHERE  v.Tienda_idTienda = "+md_o_Tienda_idTienda+" AND v.fechaPreventa >= '"+md_o_dateFrom+"' AND v.tipoDocumento like '"+md_o_tipoDocumento+"' AND v.formaPago like '"+md_o_formaPago+"' AND v.Colaborador_idColaborador like '"+md_o_Colaborador_idColaborador+"' AND c.idCliente = v.Cliente_idCliente AND v.Anulado != '1' ORDER BY v.idVenta";
            break;
        }
        case 12:
        {
        consulta = "SELECT v.idVenta as 'Id', v.fechaPreventa as 'Fecha - Hora',v.numeroDocumento as 'Num Doc.', CONCAT(c.nombres,', ',c.primer_apellido) as 'Raz. Social', v.montoTotal as 'M. Total', v.montoAdelanto as 'M. Adelanto', if(v.Entregado = '0','No Entregado','Entregado') as 'Estado', if(v.pendiente = '0', 'No Registrado','Registrado') as 'Reg. Tarjeta' FROM Venta v INNER JOIN Cliente c ON v.Cliente_idCliente =c.idCliente WHERE v.Tienda_idTienda = "+md_o_Tienda_idTienda+" AND v.numeroDocumento = "+md_o_numeroDocumento+" ORDER BY v.idVenta";
            break;
        }
        case 13:
        {
        consulta = "SELECT v.idVenta as 'Id', v.fechaPreventa as 'Fecha - Hora',v.numeroDocumento as 'Num Doc.', CONCAT(c.nombres,', ',c.primer_apellido) as 'Raz. Social', v.montoTotal as 'M. Total', v.montoAdelanto as 'M. Adelanto', if(v.Entregado = '0','No Entregado','Entregado') as 'Estado', if(v.pendiente = '0', 'No Registrado','Registrado') as 'Reg. Tarjeta' FROM Venta v INNER JOIN Cliente c ON v.Cliente_idCliente =c.idCliente WHERE v.Cliente_idCliente = '"+md_o_Cliente_idCliente+"' ORDER BY v.idVenta";
            break;
        }

    }

    QSqlQuery query(consulta);
    model->setQuery(query);
    return model;
}

void object_Venta::mf_set_dateFrom(_QSTR dateFrom)
{
    md_o_dateFrom = dateFrom;
}
void object_Venta::mf_set_dateTo(_QSTR dateTo)
{
    md_o_dateTo = dateTo;
}

bool object_Venta::mf_update_register(_QSTR pk, _QSTR flag)
{
     QSqlQuery query;

    query.prepare("UPDATE Venta SET pendiente = ? WHERE idVenta = ?");

    query.bindValue(0, flag);
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

bool object_Venta::mf_update_anulado(_QSTR pk,_QSTR estado)
{
    //function mf_update
    //w!

    QSqlQuery query;

    query.prepare("UPDATE Venta SET Anulado = ? WHERE idVenta = ?");

    query.bindValue(0, estado);
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
