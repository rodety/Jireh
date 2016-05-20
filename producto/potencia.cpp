#include "potencia.h"

potencia::potencia()
{
}


QString potencia::getIdPotencia()
{
    return idPotencia;
}
QString potencia::getNombre()
{
    return nombre;
}


void potencia::setIdPotencia(QString tmp)
{
    idPotencia=tmp;
}
void potencia::setNombre(QString tmp)
{
    nombre=tmp;
}


bool potencia::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Potencia(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}
bool potencia::actualizar()
{
    return false;
}
bool potencia::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Potencia WHERE idPotencia=?");
    query.bindValue(0,idPotencia);
    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel* potencia::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idPotencia,nombre FROM Potencia ORDER BY nombre ASC");
    return model;
}

bool potencia::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idPotencia FROM Potencia WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idPotencia=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
