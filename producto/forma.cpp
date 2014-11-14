#include "forma.h"

forma::forma()
{
}


QString forma::getIdForma()
{
    return idForma;
}
QString forma::getNombre()
{
    return nombre;
}


void forma::setIdForma(QString tmp)
{
    idForma=tmp;
}
void forma::setNombre(QString tmp)
{
    nombre=tmp;
}


bool forma::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Forma(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}
bool forma::actualizar()
{
    return false;
}
bool forma::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Forma WHERE idForma=?");
    query.bindValue(0,idForma);
    if(query.exec())
        return true;
    else
        return false;
}



bool forma::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idForma FROM Forma WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idForma=query.value(0).toString();
            return true;
        }
        return false;
    }
    else
        return false;
}

QSqlQueryModel * forma::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idForma,nombre FROM Forma");
    return model;
}
