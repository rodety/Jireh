#include "estado.h"

estado::estado()
{
}

QString estado::getIdEstado()
{
    return idEstado;
}
QString estado::getNombre()
{
    return nombre;
}


void estado::setIdEstado(QString tmp)
{
    idEstado=tmp;
}
void estado::setNombre(QString tmp)
{
    nombre=tmp;
}


bool estado::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Estado(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}
bool estado::actualizar()
{
    return false;
}
bool estado::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Estado WHERE idEstado=?");
    query.bindValue(0,idEstado);
    if(query.exec())
        return true;
    else
        return false;
}


QSqlQueryModel* estado::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idEstado,nombre FROM Estado ORDER BY nombre ASC");
    return model;
}
bool estado::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idEstado FROM Estado WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idEstado=query.value(0).toString();
            return true;
        }
        return false;
    }
    else
        return false;
}
