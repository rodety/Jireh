#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H

#include <objetopersistente.h>

class tratamiento:public ObjetoPersistente
{
private:
    QString idTratamiento;
    QString nombre;
public:
    tratamiento();

    QString getIdTratamiento();
    QString getNombre();

    void setIdTratamiento(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();    
    bool completar();
};

#endif // TRATAMIENTO_H
