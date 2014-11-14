#include "genero.h"

genero::genero()
{
}
QString genero::getIdgenero()
{
    return idgenero;
}
QString genero::getNombre()
{
    return nombre;
}


void genero::setIdgenero(QString tmp)
{
    idgenero=tmp;
}
void genero::setNombre(QString tmp)
{
    nombre=tmp;
}


bool genero::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Genero(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}
bool genero::actualizar()
{
    return false;
}
bool genero::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Genero WHERE idGenero=?");
    query.bindValue(0,idgenero);
    if(query.exec())
        return true;
    else
        return false;
}



bool genero::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idGenero FROM Genero WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idgenero=query.value(0).toString();
            return true;
        }
        return false;
    }
    else
        return false;
}

QSqlQueryModel * genero::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idGenero,nombre FROM Genero");
    return model;
}
