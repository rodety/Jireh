#ifndef DIAMETRO_H
#define DIAMETRO_H

#include <objetopersistente.h>

class diametro:public ObjetoPersistente
{
private:
    QString idDiametro;
    QString valor;
public:
    diametro();

    QString getIdDiametro();
    QString getValor();

    void setIdDiametro(QString tmp);
    void setValor(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();    
    bool completar();
};

#endif // DIAMETRO_H
