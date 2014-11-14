#ifndef TIPOLUNA_H
#define TIPOLUNA_H

#include <objetopersistente.h>

class tipoLuna:public ObjetoPersistente
{
private:
    QString idTipoLuna;
    QString nombre;
public:
    tipoLuna();

    QString getIdTipoLuna();
    QString getNombre();

    void setIdTipoLuna(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();    
    bool completar();
};

#endif // TIPOLUNA_H
