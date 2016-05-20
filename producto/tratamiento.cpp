#include "tratamiento.h"

tratamiento::tratamiento()
{
}

QString tratamiento::getIdTratamiento()
{
    return idTratamiento;
}
QString tratamiento::getNombre()
{
    return nombre;
}

void tratamiento::setIdTratamiento(QString tmp)
{
    idTratamiento=tmp;
}
void tratamiento::setNombre(QString tmp)
{
    nombre=tmp;
}

bool tratamiento::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Tratamiento(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}

bool tratamiento::actualizar()
{
    return false;
}

bool tratamiento::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Tratamiento WHERE idTratamiento=?");
    query.bindValue(0,idTratamiento);
    if(query.exec())
        return true;
    else
        return false;
}



bool tratamiento::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idTratamiento FROM Tratamiento WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idTratamiento=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

QSqlQueryModel * tratamiento::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idTratamiento,nombre FROM Tratamiento ORDER BY nombre ASC");
    return model;
}
