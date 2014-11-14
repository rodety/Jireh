#ifndef TRABAJOSEXTRAS_H
#define TRABAJOSEXTRAS_H

#include <objetopersistente.h>

class trabajosExtras:public ObjetoPersistente
{
private:
    QString idTrabajosExtras;
    QString descripcion;
    QString precio;
    QString descuento;
public:
    trabajosExtras();

    QString getIdTrabajosExtras();
    QString getDescripcion();
    QString getPrecio();
    QString getDescuento();

    void setIdTrabajosExtras(QString tmp);
    void setDescripcion(QString tmp);
    void setPrecio(QString tmp);
    void setDescuento(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrar();
    bool completar();
};

#endif // TRABAJOSEXTRAS_H
