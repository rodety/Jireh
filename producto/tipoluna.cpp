#include "tipoluna.h"

tipoLuna::tipoLuna()
{
}

QString tipoLuna::getIdTipoLuna()
{
    return idTipoLuna;
}
QString tipoLuna::getNombre()
{
    return nombre;
}

void tipoLuna::setIdTipoLuna(QString tmp)
{
    idTipoLuna=tmp;
}
void tipoLuna::setNombre(QString tmp)
{
    nombre=tmp;
}

bool tipoLuna::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TipoLuna(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}

bool tipoLuna::actualizar()
{
    return false;
}

bool tipoLuna::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM TipoLuna WHERE idTipoLuna=?");
    query.bindValue(0,idTipoLuna);
    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel* tipoLuna::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idTipoLuna,nombre FROM TipoLuna ORDER BY nombre ASC");
    return model;
}

bool tipoLuna::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idTipoLuna FROM TipoLuna WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idTipoLuna=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}


