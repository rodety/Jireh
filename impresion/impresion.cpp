#include "impresion.h"

impresion::impresion()
{
}

void impresion::setNombreTienda(QString tmp,QString tmp1)
{
    Ticket1.TextoCentro(tmp); // imprime en el centro "Venta mostrador"
    Ticket1.TextoMensaje("De: "+tmp1); // imprime en el centro "Venta mostrador"
}

void impresion::setDireccionTienda(QString tmp)
{
    Ticket1.TextoCentro(tmp);
}

void impresion::setRucTienda_Telefono(QString tmp, QString tmp1)
{
    Ticket1.TextoExtremos("Ruc: "+tmp," Tel. "+tmp1);
    Ticket1.LineasGuion(); // imprime una linea de guiones
}

void impresion::setNumeroTicket_Fecha(QString tmp, QString tmp1)
{
    Ticket1.TextoExtremos("Ticket nro: "+tmp,tmp1);
}

void impresion::setNumeroFactura_Fecha(QString tmp, QString tmp1)
{
    Ticket1.TextoExtremos("Factura nro: "+tmp,tmp1);
}

void impresion::setNombreCliente(QString tmp)
{
    nombreCliente = tmp;
    Ticket1.TextoIzquierda("Nombre: "+tmp);
}

void impresion::setRucCliente(QString tmp)
{
    Ticket1.TextoIzquierda("Ruc: "+tmp);
}

void impresion::setDireccionCliente(QString tmp)
{
    Ticket1.TextoIzquierda("Direccion: "+tmp);
    Ticket1.LineasGuion(); // imprime una linea de guiones
}

void impresion::setArticuloVector(QVector<articulo> art)
{



    for(int i=0;i<art.size();i++)
    {
        Ticket1.Descripcion();
        Ticket1.TextoAutoFormateado(art[i].get_t_articulo());
        Ticket1.EncabezadoVenta(); // imprime encabezados
        Ticket1.AgregaArticulo(art[i].get_t_entregado(),art[i].get_cantidad().toInt(),art[i].get_p_unitario().toDouble(),art[i].get_descuento().toDouble(),art[i].get_importe().toDouble()); //imprime una linea de descripcion
        Ticket1.LineasGuion(); // imprime una linea de guiones

    }
}



void impresion::setSubTotal(QString tmp)
{
    QString
            text = "VENTA S/. "; text.append(tmp);
    Ticket1.TextoDerecha(text);

}

void impresion::setIgv(QString tmp)
{
    QString
            text = "I.G.V S/. "; text.append(tmp);
    Ticket1.TextoDerecha(text);
}

void impresion::setTotal(QString tmp)
{
    QString
            text = "TOTAL S/. "; text.append(tmp);
    Ticket1.TextoDerecha(text);
}

void impresion::setEntregaEfectivo(QString tmp)
{
    Ticket1.LineasGuion(); // imprime una linea de guiones
    QString
            text = "CANCELADO EFECTIVO S/."; text.append(tmp);
    Ticket1.TextoIzquierda(text);

}

void impresion::setEntregaTarjeta(QString tmp)
{
    QString
            text = "CANCELADO TARJETA  S/."; text.append(tmp);
    Ticket1.TextoIzquierda(text);
}

void impresion::setAdelantoEfectivo(QString tmp)
{
    Ticket1.LineasGuion(); // imprime una linea de guiones
    QString
            text = "ADELANTO EFECTIVO S/."; text.append(tmp);
    Ticket1.TextoIzquierda(text);
}

void impresion::setAdelantoTarjeta(QString tmp)
{
    QString
            text = "ADELANTO TARJETA  S/."; text.append(tmp);
    Ticket1.TextoIzquierda(text);
}

void impresion::setSaldo(QString tmp)
{
    QString
            text = "SALDO  S/. "; text.append(tmp);
    Ticket1.TextoIzquierda(text);
}

void impresion::setFechaEntrega(QString tmp)
{
    QString
            text = "ENTREGA: "; text.append(tmp);
    Ticket1.TextoIzquierda(text);

}

void impresion::setNombreColaborador(QString tmp)
{
    QString
            text = "Ud. fue atendido por: "; text.append(tmp);
    Ticket1.TextoMensaje(text);

}

void impresion::setFirmaCliente(QString nombreCliente1)
{
    Ticket1.TextoMensaje("\n\n");
    Ticket1.LineasGuion(); // imprime una linea de guiones
    QString firma = "Firma: "; firma.append(nombreCliente1);
    Ticket1.TextoCentro(firma);
}
void impresion::setMensajeVenta(QString tmp)
{
    Ticket1.LineasGuion(); // imprime una linea de guiones
    Ticket1.TextoMensaje(tmp); // imprime en el centro "Venta mostrador"
}
void impresion::setMensajeFinal(QString tmp)
{
    Ticket1.LineasGuion(); // imprime una linea de guiones
    Ticket1.TextoMensaje(tmp); // imprime en el centro "Venta mostrador"
}

void impresion::imprimir()
{
    Ticket1.imprime();
}





