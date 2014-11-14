#ifndef ACCESORIOS_H
#define ACCESORIOS_H
#include "producto/producto.h"
#include <configuracion/sesion.h>
#include "producto/genero.h"
#include <QSqlQuery>
class accesorios : public producto
{
public:
    accesorios();
    ~accesorios();
private:
    color pColor;
    tamanio pTamanio;
    calidad pCalidad;
    genero pGenero;

    QString idColor;
    QString idTamanio;
    QString idCalidad;
    QString idGenero;


public:
    color getColor();
    tamanio getTamanio();
    calidad getCalidad();
    genero getGenero();

    void setColor(color tmp);
    void setTamanio(tamanio tmp);
    void setCalidad(calidad tmp);
    void setGenero(genero tmp);

    void setidColor(QString tmp);
    void setidTamanio(QString tmp);
    void setidCalidad(QString tmp);
    void setidGenero(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrar();
    static QSqlQueryModel* mostrarcod();
    bool completar();
    QSqlQueryModel* mf_show(object_Producto tmp);
};

#endif // ACCESORIOS_H
