#include "tusuario.h"

tusuario::tusuario()
{
}

QString tusuario::getIdtusuario()
{
    return idtusuario;
}
QString tusuario::getNombre()
{
    return nombre;
}


void tusuario::setIdtusuario(QString tmp)
{
    idtusuario=tmp;
}
void tusuario::setNombre(QString tmp)
{
    nombre=tmp;
}


bool tusuario::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TipoColaborador (nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}
bool tusuario::actualizar()
{
    return false;
}
bool tusuario::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM TipoColaborador WHERE idTipoColaborador=?");
    query.bindValue(0,idtusuario);
    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel* tusuario::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT nombre FROM TipoColaborador");
    return model;
}

bool tusuario::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idTipoColaborador FROM TipoColaborador WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idtusuario=query.value(0).toString();            
            return true;
        }
        return false;
    }
    else
        return false;
}
