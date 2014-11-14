#ifndef MEDIDASHISTORIAL_H
#define MEDIDASHISTORIAL_H

#include <objetopersistente.h>

class medidasHistorial:public ObjetoPersistente
{
private:
    QString idMedidasHistorial;
    QString esferico;//variable
    QString cilindrico;//variable
    QString eje;
    QString distanciaPupilar;
public:
    medidasHistorial();

    QString getIdMedidasHistorial();
    QString getEsferico();
    QString getCilindrico();
    QString getEje();
    QString getDistanciaPupilar();

    void setIdMedidasHistorial(QString);
    void setEsferico(QString);
    void setCilindrico(QString);
    void setEje(QString);
    void setDistanciaPupilar(QString);

    bool agregar();
    bool actualizar();
    bool eliminar();

    bool buscar();
};

#endif // MEDIDASHISTORIAL_H
