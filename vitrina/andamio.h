#ifndef ANDAMIO_H
#define ANDAMIO_H

#include "objetopersistente.h"

class andamio:public ObjetoPersistente
{
private:
    QString idAndamio;
    QString idAlmacen;
    QString nombre;
    QString descripcion;
    QString fila;
    QString columna;

public:
    andamio();
    andamio(QString,QString,QString,QString,QString,QString);

    QString getIdAndamio();
    QString getIdAlmacen();
    QString getNombre();
    QString getDescripcion();
    QString getFila();
    QString getColumna();

    void setIdAndamio(QString);
    void setIdAlmacen(QString);
    void setNombre(QString);
    void setDescripcion(QString);
    void setFila(QString);
    void setColumna(QString);

    bool agregar();
    bool actualizar();
    bool eliminar();

};

#endif // ANDAMIO_H
