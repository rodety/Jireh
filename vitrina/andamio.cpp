#include "andamio.h"

andamio::andamio()
{
}

andamio::andamio(QString idAn, QString idAl, QString n, QString d, QString f, QString c)
{
    idAndamio = idAn;
    idAlmacen = idAl;
    nombre = n;
    descripcion = d;
    fila = f;
    columna= c;
}

QString andamio::getIdAndamio()
{
    return idAndamio;
}

QString andamio::getIdAlmacen()
{
    return idAlmacen;
}

QString andamio::getNombre()
{
    return nombre;
}

QString andamio::getDescripcion()
{
    return descripcion;
}

QString andamio::getFila()
{
    return fila;
}

QString andamio::getColumna()
{
    return columna;

}

void andamio::setIdAndamio(QString idAn)
{
    idAndamio = idAn;
}

void andamio::setIdAlmacen(QString idAl)
{
    idAlmacen = idAl;
}

void andamio::setNombre(QString n)
{
    nombre = n;
}

void andamio::setDescripcion(QString d)
{
    descripcion = d;
}

void andamio::setFila(QString f)
{
    fila = f;
}

void andamio::setColumna(QString c)
{
    columna = c;
}


bool andamio::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Andamio(Almacen_idAlmacen,nombre,descripcion,fila,columna) VALUES(?,?,?,?,?)");
    query.bindValue(0,idAlmacen);
    query.bindValue(1,nombre);
    query.bindValue(2,descripcion);
    query.bindValue(3,fila);
    query.bindValue(4,columna);

    if(query.exec())
        return true;
    else
        return false;
}

bool andamio::actualizar()
{
    QSqlQuery query;
    query.prepare("UPDATE Andamio SET Almacen_idAlmacen=?,nombre=?,descripcion=?,fila=?,columna=? WHERE idAndamio=?");
    query.bindValue(0,idAlmacen);
    query.bindValue(1,nombre);
    query.bindValue(2,descripcion);
    query.bindValue(3,fila);
    query.bindValue(4,columna);
    query.bindValue(5,idAndamio);

    if(query.exec())
        return true;
    else
        return false;
}


bool andamio::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Andamio WHERE idAndamio='"+idAndamio+"'");

    if(query.exec())
        return true;
    else
        return false;
}


