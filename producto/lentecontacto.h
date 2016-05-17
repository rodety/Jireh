#ifndef LENTECONTACTO_H
#define LENTECONTACTO_H

#include <producto/producto.h>

class lenteContacto:public producto
{
private:
    QString presentacion;
    QString tinteVisibilidad;
    QString contenidoAcuoso;
    QString diseno;
    tipoLente pTipoLente;
    potencia pPotencia;
    curvaBase pCurvaBase;
    diametro pDiametro;
    tiempoUso pTiempoUso;
    material pMaterial;

public:
    lenteContacto();

    QString getPresentacion();
    QString getTienteVisibilidad();
    QString getContenidoAcuoso();
    QString getDiseno();
    tipoLente getTipoLente();
    potencia getPotencia();
    curvaBase getCurvaBase();
    diametro getDiametro();
    tiempoUso getTiempoUso();
    material getMaterial();

    void setPresentacion(QString tmp);
    void setTinteVisibilidad(QString tmp);
    void setContenidoAcuoso(QString tmp);
    void setDiseno(QString tmp);
    void setTipoLente(tipoLente tmp);
    void setPotencia(potencia tmp);
    void setCurvaBase(curvaBase tmp);
    void setDiametro(diametro tmp);
    void setTiempoUso(tiempoUso tmp);
    void setMaterial(material tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrar();
    static QSqlQueryModel* mostrarcod();
    bool completar();

};

#endif // LENTECONTACTO_H
