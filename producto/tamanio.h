#ifndef TAMANIO_H
#define TAMANIO_H

#include <objetopersistente.h>

class tamanio:public ObjetoPersistente
{
private:
    QString idTamanio;
    QString nombre;
public:
    tamanio();

    QString getIdTamanio();
    QString getNombre();

    void setIdTamanio(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();
    bool completar();
};

#endif // TAMANIO_H
