#ifndef TIPODOC_IDENT_H
#define TIPODOC_IDENT_H

#include <objetopersistente.h>

class tipodoc_ident:ObjetoPersistente
{
private:
    QString idTipoDocIdent;
    QString nombre;
    QString size;
public:
    tipodoc_ident();

    QString getIdTipoDocIdent();
    QString getNombre();

    void setIdTipoDocIdent(QString);
    void setNombre(QString);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrar();
    bool buscar();
    bool completar();

};

#endif // TIPODOC_IDENT_H
