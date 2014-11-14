#ifndef ALMACEN_H
#define ALMACEN_H

#include "objetopersistente.h"

class almacen:public ObjetoPersistente
{
private:
    QString idAlmacen;
    QString idTienda;
    QString nombre;
    QString descripcion;
public:
    almacen();
    almacen(QString,QString,QString,QString);

    QString getIdAlmacen();
    QString getIdTienda();
    QString getNombre();
    QString getDescripcion();

    void setIdAlmacen(QString);
    void setIdTienda(QString);
    void setNombre(QString);
    void setDescripcion(QString);

    bool agregar();
    bool actualizar();
    bool eliminar();

};


#endif // ALMACEN_H
