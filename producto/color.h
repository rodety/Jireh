#ifndef COLOR_H
#define COLOR_H

#include <objetopersistente.h>

class color:public ObjetoPersistente
{
private:
    QString idColor;
    QString nombre;
public:
    color();

    QString getIdColor();
    QString getNombre();

    void setIdColor(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();
    bool completar();
};

#endif // COLOR_H
