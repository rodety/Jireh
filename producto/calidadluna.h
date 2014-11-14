#ifndef CALIDADLUNA_H
#define CALIDADLUNA_H
#include <objetopersistente.h>

class calidadluna:public ObjetoPersistente
{
private:
    QString idCalidad;
    QString nombre;
public:
    calidadluna();
    QString getIdCalidad();
    QString getNombre();

    void setIdCalidad(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();    
    bool completar();
};

#endif // CALIDADLUNA_H
