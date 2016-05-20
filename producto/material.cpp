#include "material.h"

material::material()
{
}

QString material::getIdMaterial()
{
    return idMaterial;
}
QString material::getNombre()
{
    return nombre;
}

void material::setIdMaterial(QString tmp)
{
    idMaterial=tmp;
}
void material::setNombre(QString tmp)
{
    nombre=tmp;
}

bool material::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Material(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}
bool material::actualizar()
{
    return false;
}
bool material::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Material WHERE idMaterial=?");
    query.bindValue(0,idMaterial);
    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel* material::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idMaterial,nombre FROM Material ORDER BY nombre ASC");
    return model;
}

bool material::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idMaterial FROM Material WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idMaterial=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
