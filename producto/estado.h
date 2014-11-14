#ifndef ESTADO_H
#define ESTADO_H

#include <objetopersistente.h>

class estado:public ObjetoPersistente
{
private:
    QString idEstado;
    QString nombre;
public:
    estado();

    QString getIdEstado();
    QString getNombre();

    void setIdEstado(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();    
    bool completar();
};

#endif // ESTADO_H
