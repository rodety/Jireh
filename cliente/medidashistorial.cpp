#include "medidashistorial.h"

medidasHistorial::medidasHistorial()
{
}

QString medidasHistorial::getIdMedidasHistorial()
{
    return idMedidasHistorial;
}

QString medidasHistorial::getEsferico()
{
    return esferico;
}

QString medidasHistorial::getCilindrico()
{
    return cilindrico;
}

QString medidasHistorial::getEje()
{
    return eje;
}

QString medidasHistorial::getDistanciaPupilar()
{
    return distanciaPupilar;
}

void medidasHistorial::setIdMedidasHistorial(QString tmp)
{
    idMedidasHistorial = tmp;
}

void medidasHistorial::setEsferico(QString tmp)
{
    esferico = tmp;
}

void medidasHistorial::setCilindrico(QString tmp)
{
    cilindrico = tmp;
}

void medidasHistorial::setEje(QString tmp)
{
    eje = tmp;
}

void medidasHistorial::setDistanciaPupilar(QString tmp)
{
    distanciaPupilar = tmp;
}

bool medidasHistorial::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO MedidaHistorial(esferico,cilindrico,eje,distanciaPupilar) VALUES(?,?,?,?);");
    query.bindValue(0,esferico);
    query.bindValue(1,cilindrico);
    query.bindValue(2,eje);
    query.bindValue(3,distanciaPupilar);
    if(query.exec())
    {
        query.clear();
        query.prepare("SELECT @@identity AS id;");
        query.exec();
        if(query.size()!=0)
        {
            query.first();
            idMedidasHistorial=query.value(0).toString();
            return true;
        }
        return false;

    }
    else
        return false;
    return true;
}

bool medidasHistorial::actualizar()
{
    QSqlQuery query;
    query.prepare("UPDATE MedidaHistorial SET esferico=?,cilindrico=?,eje=?,distanciaPupilar=? where idMedidaHistorial=?");
    query.bindValue(0,esferico);
    query.bindValue(1,cilindrico);
    query.bindValue(2,eje);
    query.bindValue(3,distanciaPupilar);
    query.bindValue(4,idMedidasHistorial);
    if(query.exec())
        return true;
    else
        return false;
}

bool medidasHistorial::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM MedidaHistorial WHERE idMedidaHistorial=?");
    query.bindValue(0,idMedidasHistorial);
    if(query.exec())
        return true;
    else
        return false;
}

bool medidasHistorial::buscar()
{
    QSqlQuery query;
    query.prepare("select * from MedidaHistorial where idMedidaHistorial=?");
    query.bindValue(0,idMedidasHistorial);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            esferico=query.value(1).toString();
            cilindrico=query.value(2).toString();
            eje=query.value(3).toString();
            distanciaPupilar=query.value(4).toString();
            return true;
        }
        return false;
    }
    else
        return false;
    return false;
}
