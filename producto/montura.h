#ifndef MONTURA_H
#define MONTURA_H

#include <producto/producto.h>
#include <producto/genero.h>
class montura:public producto
{
private:
    forma pForma;
    color pColor;
    tamanio pTamanio;
    calidad pCalidad;
    genero pGenero;

public:
    montura();

    forma getForma();
    color getColor();
    tamanio getTamanio();
    calidad getCalidad();
    genero getGenero();

    void setForma(forma tmp);
    void setColor(color tmp);
    void setTamanio(tamanio tmp);
    void setCalidad(calidad tmp);
    void setGenero(genero tmp);


    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrar();
    static QSqlQueryModel* mostrarcod();
    bool completar();

};

#endif // MONTURA_H
