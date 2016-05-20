#include "calidadluna.h"

calidadluna::calidadluna()
{
}

QString calidadluna::getIdCalidad()
{
    return idCalidad;
}
QString calidadluna::getNombre()
{
    return nombre;
}


void calidadluna::setIdCalidad(QString tmp)
{
    idCalidad=tmp;
}
void calidadluna::setNombre(QString tmp)
{
    nombre=tmp;
}


bool calidadluna::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CalidadLuna(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}
bool calidadluna::actualizar()
{
    return false;
}
bool calidadluna::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM CalidadLuna WHERE idCalidadLuna=?");
    query.bindValue(0,idCalidad);
    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel* calidadluna::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idCalidadLuna,nombre FROM CalidadLuna ORDER BY nombre ASC;");
    return model;
}

bool calidadluna::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idCalidadLuna FROM CalidadLuna WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idCalidad=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

