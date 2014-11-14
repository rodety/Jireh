#include "tiempouso.h"

tiempoUso::tiempoUso()
{
}

QString tiempoUso::getIdTiempoUso()
{
    return idTiempoUso;
}
QString tiempoUso::getValor()
{
    return valor;
}

void tiempoUso::setIdTiempoUso(QString tmp)
{
    idTiempoUso=tmp;
}
void tiempoUso::setValor(QString tmp)
{
    valor=tmp;
}

bool tiempoUso::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TiempoUso(valor) VALUES(?)");
    query.bindValue(0,valor);
    if(query.exec())
        return true;
    else
        return false;
}

bool tiempoUso::actualizar()
{
    return false;
}

bool tiempoUso::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM TiempoUso WHERE idTiempoUso=?");
    query.bindValue(0,idTiempoUso);
    if(query.exec())
        return true;
    else
        return false;
}


bool tiempoUso::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idTiempoUso FROM TiempoUso WHERE valor=?");
    query.bindValue(0,valor);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idTiempoUso=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

QSqlQueryModel * tiempoUso::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idTiempoUso,valor FROM TiempoUso");
    return model;
}
