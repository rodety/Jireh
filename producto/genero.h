#ifndef GENERO_H
#define GENERO_H
#include <objetopersistente.h>
class genero:ObjetoPersistente
{
private:
    QString idgenero;
    QString nombre;

public:
    genero();
    QString getIdgenero();
    QString getNombre();

    void setIdgenero(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();
    bool completar();
};

#endif // GENERO_H
