#ifndef TIEMPOUSO_H
#define TIEMPOUSO_H

#include <objetopersistente.h>

class tiempoUso:public ObjetoPersistente
{
private:
    QString idTiempoUso;
    QString valor;
public:
    tiempoUso();

    QString getIdTiempoUso();
    QString getValor();

    void setIdTiempoUso(QString tmp);
    void setValor(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();
    bool completar();
};

#endif // TIEMPOUSO_H
