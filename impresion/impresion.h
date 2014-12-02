#ifndef IMPRESION_H
#define IMPRESION_H
#include <vector>
#include <QVector>
#include "impresion/creaticket.h"
#include "impresion/articulo.h"


class articulo;
class impresion
{
private:
    CreaTicket Ticket1;
    QString nombreCliente;
public:
    impresion();
    void setNombreTienda(QString tmp,QString tmp1);
    void setDireccionTienda(QString tmp);
    void setRucTienda_Telefono(QString tmp,QString tmp1);

    void setNumeroTicket_Fecha(QString tmp,QString tmp1);

    void setNombreCliente(QString tmp);
    void setRucCliente(QString tmp);
    void setDireccionCliente(QString tmp);
    void setArticuloVector(QVector<articulo> art);

    void setSubTotal(QString tmp);
    void setIgv(QString tmp);
    void setTotal(QString tmp);
    void setEntregaEfectivo(QString tmp);
    void setEntregaTarjeta(QString tmp);
    void setAdelantoEfectivo(QString tmp);
    void setAdelantoTarjeta(QString tmp);
    void setSaldo(QString tmp);
    void setFechaEntrega(QString tmp);
    void setNombreColaborador(QString tmp);
    void setMensajeVenta(QString tmp);
    void setMensajeFinal(QString tmp);
    void imprimir();



};

#endif // IMPRESION_H
