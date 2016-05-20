#include "talla.h"

talla::talla()
{
}


QString talla::getIdTalla()
{
    return idTalla;
}
QString talla::getNombre()
{
    return nombre;
}


void talla::setIdTalla(QString tmp)
{
    idTalla=tmp;
}
void talla::setNombre(QString tmp)
{
    nombre=tmp;
}


bool talla::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Talla(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}
bool talla::actualizar()
{
    return false;
}
bool talla::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Talla WHERE idTalla=?");
    query.bindValue(0,idTalla);
    if(query.exec())
        return true;
    else
        return false;
}



bool talla::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idTalla FROM Talla WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idTalla=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

QSqlQueryModel * talla::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idTalla,nombre FROM Talla ORDER BY nombre ASC");
    return model;
}
