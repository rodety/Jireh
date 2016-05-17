#ifndef ETIQUETA_H
#define ETIQUETA_H

#include <QString>
#include <zint.h>
//#include <zlib.h>
#include <QSqlQuery>
#include <QDebug>

class etiqueta
{
private:
    QString codigo;
    QString descripcion;
    QString marca;
    QString ubicacion;
    QString precio;
public:
    etiqueta();

    QString getCodigo();
    QString getDescripcion();
    QString getMarca();
    QString getUbicacion();
    QString getPrecio();

    void setCodigo(QString);
    void setDescripcion(QString tmp)
    {
        descripcion=tmp;
    }
    void setMarca(QString);
    void setUbicacion(QString);
    void setPrecio(QString);

    void etiquetar();

    bool buscarUbicacion();

};

#endif // ETIQUETA_H
