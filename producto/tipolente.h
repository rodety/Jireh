#ifndef TIPOLENTE_H
#define TIPOLENTE_H

#include <objetopersistente.h>

class tipoLente:public ObjetoPersistente
{
private:
    QString idTipoLente;
    QString nombre;
public:
    tipoLente();

    QString getIdTipoLente();
    QString getNombre();

    void setIdTipoLente(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();
    bool completar();
};

#endif // TIPOLENTE_H
