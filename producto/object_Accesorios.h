#ifndef OBJECT_ACCESORIOS_H
#define OBJECT_ACCESORIOS_H
#include <producto/producto.h>
#include <producto/genero.h>
#include "share_include.h"



class object_Accesorios:public producto
{
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

	object_Accesorios();
    ~object_Accesorios();

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
    QSqlQueryModel* mf_show_search(QString id);

};
#endif // OBJECT_ACCESORIOS_H
