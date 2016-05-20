#include "tamanio.h"

tamanio::tamanio()
{
}


QString tamanio::getIdTamanio()
{
    return idTamanio;
}
QString tamanio::getNombre()
{
    return nombre;
}


void tamanio::setIdTamanio(QString tmp)
{
    idTamanio=tmp;
}
void tamanio::setNombre(QString tmp)
{
    nombre=tmp;
}


bool tamanio::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Tamanio(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}
bool tamanio::actualizar()
{
    return false;
}
bool tamanio::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Tamanio WHERE idTamanio=?");
    query.bindValue(0,idTamanio);
    if(query.exec())
        return true;
    else
        return false;
}



bool tamanio::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idTamanio FROM Tamanio WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idTamanio=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

QSqlQueryModel * tamanio::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idTamanio,nombre FROM Tamanio ORDER BY nombre ASC");
    return model;
}
