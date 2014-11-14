#include "calidad.h"

calidad::calidad()
{
}

QString calidad::getIdCalidad()
{
    return idCalidad;
}
QString calidad::getNombre()
{
    return nombre;
}


void calidad::setIdCalidad(QString tmp)
{
    idCalidad=tmp;
}
void calidad::setNombre(QString tmp)
{
    nombre=tmp;
}


bool calidad::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Calidad(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}
bool calidad::actualizar()
{
    return false;
}
bool calidad::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Calidad WHERE idCalidad=?");
    query.bindValue(0,idCalidad);
    if(query.exec())
        return true;
    else
        return false;
}


bool calidad::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idCalidad FROM Calidad WHERE nombre=?");
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

QSqlQueryModel * calidad::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idCalidad,nombre FROM Calidad");
    return model;
}
