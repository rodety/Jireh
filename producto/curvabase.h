#ifndef CURVABASE_H
#define CURVABASE_H

#include <objetopersistente.h>

class curvaBase:public ObjetoPersistente
{
private:
    QString idCurvaBase;
    QString valor;
public:
    curvaBase();

    QString getIdCurvaBase();
    QString getValor();

    void setIdCurvaBase(QString tmp);
    void setValor(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();
    bool completar();
};

#endif // CURVABASE_H
