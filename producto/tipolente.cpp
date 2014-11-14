#include "tipolente.h"

tipoLente::tipoLente()
{
}

QString tipoLente::getIdTipoLente()
{
    return idTipoLente;
}
QString tipoLente::getNombre()
{
    return nombre;
}

void tipoLente::setIdTipoLente(QString tmp)
{
    idTipoLente=tmp;
}
void tipoLente::setNombre(QString tmp)
{
    nombre=tmp;
}

bool tipoLente::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TipoLente(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}

bool tipoLente::actualizar()
{
    return false;
}
bool tipoLente::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM TipoLente WHERE idTipoLente=?");
    query.bindValue(0,idTipoLente);
    if(query.exec())
        return true;
    else
        return false;
}


bool tipoLente::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idTipoLente FROM TipoLente WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idTipoLente=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

QSqlQueryModel * tipoLente::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idTipoLente,nombre FROM TipoLente");
    return model;
}
