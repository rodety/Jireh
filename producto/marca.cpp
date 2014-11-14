#include "marca.h"

m_marca::m_marca()
{
}


QString m_marca::getIdMarca()
{
    return idMarca;
}
QString m_marca::getNombre()
{
    return nombre;
}


void m_marca::setIdMarca(QString tmp)
{
    idMarca=tmp;
}
void m_marca::setNombre(QString tmp)
{
    nombre=tmp;
}


bool m_marca::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Marca(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}
bool m_marca::actualizar()
{
    return false;
}
bool m_marca::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Marca WHERE idMarca=?");
    query.bindValue(0,idMarca);
    if(query.exec())
        return true;
    else
        return false;
}



bool m_marca::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idMarca FROM Marca WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idMarca=query.value(0).toString();
            return true;
        }
        return false;
    }
    else
        return false;
}

QSqlQueryModel * m_marca::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idMarca,nombre FROM Marca");
    return model;
}
