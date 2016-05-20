#include "tipootros.h"

tipoOtros::tipoOtros()
{
}

QString tipoOtros::getIdTipoOtros()
{
    return idTipoOtros;
}
QString tipoOtros::getNombre()
{
    return nombre;
}
void tipoOtros::setIdTipoOtros(QString tmp)
{
    idTipoOtros=tmp;
}
void tipoOtros::setNombre(QString tmp)
{
    nombre=tmp;
}

bool tipoOtros::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TipoOtros(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}

bool tipoOtros::actualizar()
{
    return false;
}

bool tipoOtros::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM TipoOtros WHERE idTipoOtros=?");
    query.bindValue(0,idTipoOtros);
    if(query.exec())
        return true;
    else
        return false;
}



bool tipoOtros::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idTipoOtros FROM TipoOtros WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idTipoOtros=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

QSqlQueryModel * tipoOtros::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idTipoOtros,nombre FROM TipoOtros ORDER BY nombre ASC");
    return model;
}
