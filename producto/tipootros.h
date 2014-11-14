#ifndef TIPOOTROS_H
#define TIPOOTROS_H

#include <objetopersistente.h>

class tipoOtros:public ObjetoPersistente
{
private:
    QString idTipoOtros;
    QString nombre;
public:
    tipoOtros();

    QString getIdTipoOtros();
    QString getNombre();

    void setIdTipoOtros(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();
    bool completar();
};

#endif // TIPOOTROS_H
