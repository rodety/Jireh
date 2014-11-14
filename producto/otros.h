#ifndef OTROS_H
#define OTROS_H

#include <producto/producto.h>
#include <producto/genero.h>
class otros:public producto
{
private:
    color pColor;
    talla pTalla;
    calidad pCalidad;
    tipoOtros pTipoOtros;
    genero pGenero;
public:
    otros();

    color getColor();
    talla getTalla();
    calidad getCalidad();
    tipoOtros getTipoOtros();
    genero getGenero();

    void setColor(color tmp);
    void setTalla(talla tmp);
    void setCalidad(calidad tmp);
    void setTipoOtros(tipoOtros tmp);
    void setGenero(genero tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrar();
    static QSqlQueryModel* mostrarcod();
    bool completar();
};

#endif // OTROS_H
