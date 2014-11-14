#ifndef MATERIAL_H
#define MATERIAL_H

#include <objetopersistente.h>

class material:public ObjetoPersistente
{
private:
    QString idMaterial;
    QString nombre;
public:
    material();

    QString getIdMaterial();
    QString getNombre();

    void setIdMaterial(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();
    bool completar();
};

#endif // MATERIAL_H
