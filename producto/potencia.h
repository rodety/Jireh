#ifndef POTENCIA_H
#define POTENCIA_H

#include <objetopersistente.h>

class potencia:public ObjetoPersistente
{
private:
    QString idPotencia;
    QString nombre;
public:
    potencia();

    QString getIdPotencia();
    QString getNombre();

    void setIdPotencia(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();
    bool completar();
};

#endif // POTENCIA_H
