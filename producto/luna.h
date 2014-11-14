#ifndef LUNA_H
#define LUNA_H

#include <producto/producto.h>

class luna:public producto
{
private:
    diametro pDiametro;
    calidadluna pCalidad;
    tipoLuna pTipoLuna;
    tratamiento pTratamiento;
    object_Laboratorio pLaboratorio;
    object_Lista pLista;
    QString valorInicial;
    QString valorFinal;
    QString precio;
    QString cilindro;
    QString cilindro_final;
    QString detalle;

public:
    luna();

    diametro getDiametro();
    calidadluna getCalidad();
    tipoLuna getTipoLuna();
    tratamiento getTratamiento();

    object_Laboratorio getLaboratorio();
    object_Lista getLista();
    QString getValorInicial();
    QString getValorFinal();
    QString getPrecio();
    QString getCilindro();
    QString getCilindro_final();



    void setDiametro(diametro tmp);
    void setCalidad(calidadluna tmp);
    void setTipoLuna(tipoLuna tmp);
    void setTratamiento(tratamiento tmp);
    void setValorInicial(QString tmp);
    void setValorFinal(QString tmp);
    void setPrecio(QString tmp);
    void setCilindro(QString tmp);
    void setCilindro_final(QString tmp);
    void setDetalle(QString tmp);    

    void setLaboratorio(object_Laboratorio tmp);
    void setLista(object_Lista tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrar();
    bool completar();

    bool verificarPrecio();
};

#endif // LUNA_H
