#include "contenedor.h"

contenedor::contenedor()
{
}

contenedor::contenedor(QString idC, QString idAn, QString n, QString d, QString f, QString c)
{
    idContenedor = idC;
    idAndamio = idAn;
    nombre = n;
    descripcion = d;
    pos_fila = f;
    pos_columna = c;
}


QString contenedor::getIdContenedor()
{
    return idContenedor;
}

QString contenedor::getIdAndamio()
{
    return idAndamio;
}

QString contenedor::getNombre()
{
    return nombre;
}

QString contenedor::getDescripcion()
{
    return descripcion;
}

QString contenedor::getPosFila()
{
    return pos_fila;

}

QString contenedor::getPosColumna()
{
    return pos_columna;
}

void contenedor::setIdContenedor(QString idC)
{
    idContenedor = idC;
}

void contenedor::setIdAndamio(QString idAn)
{
    idAndamio = idAn;
}

void contenedor::setNombre(QString n)
{
    nombre = n;
}

void contenedor::setDescripcion(QString d)
{
    descripcion = d;
}

void contenedor::setPosFila(QString f)
{
    pos_fila = f;
}

void contenedor::setPosColumna(QString c)
{
    pos_columna = c;
}

bool contenedor::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Contenedor(Andamio_idAndamio,nombre,descripcion,posFila,posColumna) VALUES(?,?,?,?,?)");
    query.bindValue(0,idAndamio);
    query.bindValue(1,nombre);
    query.bindValue(2,descripcion);
    query.bindValue(3,pos_fila);
    query.bindValue(4,pos_columna);

    if(query.exec())
        return true;
    else
        return false;
}

bool contenedor::actualizar()
{
    QSqlQuery query;
    query.prepare("UPDATE Contenedor SET Andamio_idAndamio=?,nombre=?,descripcion=?,posFila=?,posColumna=? WHERE idContenedor=?");
    query.bindValue(0,idAndamio);
    query.bindValue(1,nombre);
    query.bindValue(2,descripcion);
    query.bindValue(3,pos_fila);
    query.bindValue(4,pos_columna);
    query.bindValue(5,idContenedor);

    if(query.exec())
        return true;
    else
        return false;


}

bool contenedor::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Contenedor WHERE idContenedor='"+idContenedor+"'");

    if(query.exec())
        return true;
    else
        return false;
}



