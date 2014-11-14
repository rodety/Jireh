#ifndef TALLA_H
#define TALLA_H

#include <objetopersistente.h>

class talla:public ObjetoPersistente
{
private:
    QString idTalla;
    QString nombre;
public:
    talla();

    QString getIdTalla();
    QString getNombre();

    void setIdTalla(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();
    bool completar();
};

#endif // TALLA_H
