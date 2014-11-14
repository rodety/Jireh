#include "almacen.h"

almacen::almacen()
{
}


almacen::almacen(QString idA, QString idT, QString n, QString d)
{
    idAlmacen = idA;
    idTienda = idT;
    nombre = n;
    descripcion = d;
}

QString almacen::getIdAlmacen()
{
    return idAlmacen;
}

QString almacen::getIdTienda()
{
    return idTienda;
}

QString almacen::getNombre()
{
    return nombre;
}

QString almacen::getDescripcion()
{
    return descripcion;
}

void almacen::setIdAlmacen(QString idA)
{
    idAlmacen = idA;
}

void almacen::setIdTienda(QString idT)
{
    idTienda = idT;
}

void almacen::setNombre(QString n)
{
    nombre = n;
}

void almacen::setDescripcion(QString d)
{
    descripcion = d;
}

bool almacen::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Almacen(Tienda_idTienda,nombre,descripcion) VALUES(?,?,?)");
    query.bindValue(0,idTienda);
    query.bindValue(1,nombre);
    query.bindValue(2,descripcion);

    if(query.exec())
        return true;
    else
        return false;

}
bool almacen::actualizar()
{
    QSqlQuery query;
    query.prepare("UPDATE Almacen SET Tienda_idtienda=?,nombre=?,descripcion=? where idAlmacen=?");
    query.bindValue(0,idTienda);
    query.bindValue(1,nombre);
    query.bindValue(2,descripcion);
    query.bindValue(3,idAlmacen);

    if(query.exec())
        return true;
    else
        return false;
}

bool almacen::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM almacen WHERE idAlmacen='"+idAlmacen+"'");

    if(query.exec())
        return true;
    else
        return false;
}
