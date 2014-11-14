#ifndef FORMA_H
#define FORMA_H

#include <objetopersistente.h>

class forma:public ObjetoPersistente
{
private:
    QString idForma;
    QString nombre;
public:
    forma();

    QString getIdForma();
    QString getNombre();

    void setIdForma(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();
    bool completar();
};

#endif // FORMA_H
