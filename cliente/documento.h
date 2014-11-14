#ifndef TIPODOC_IDENT_H
#define TIPODOC_IDENT_H

#include <objetopersistente.h>

class documento:ObjetoPersistente
{
private:
    QString idDocumento;
    QString nombre;
    QString abreviatura;
public:
    documento();

    QString getIdDocumento();
    QString getNombre();
    QString getAbreviatura();

    void setIdDocumento(QString tmp);
    void setNombre(QString tmp);
    void setAbreviatura(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();
    bool completar();
};

#endif // TIPODOC_IDENT_H
