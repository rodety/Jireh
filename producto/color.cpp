#include "color.h"

color::color()
{
}

QString color::getIdColor()
{
    return idColor;
}
QString color::getNombre()
{
    return nombre;
}


void color::setIdColor(QString tmp)
{
    idColor=tmp;
}
void color::setNombre(QString tmp)
{
    nombre=tmp;
}


bool color::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Color(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}
bool color::actualizar()
{
    return false;
}
bool color::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Color WHERE idColor=?");
    query.bindValue(0,idColor);
    if(query.exec())
        return true;
    else
        return false;
}



bool color::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idColor FROM Color WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idColor=query.value(0).toString();
            return true;
        }
        return false;
    }
    else
        return false;
}

QSqlQueryModel * color::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idColor,nombre FROM Color ORDER BY nombre ASC");
    return model;
}
