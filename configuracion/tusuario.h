#ifndef TUSUARIO_H
#define TUSUARIO_H
#include <objetopersistente.h>

class tusuario:public ObjetoPersistente
{
private:
    QString idtusuario;
    QString nombre;
public:
    tusuario();
    QString getIdtusuario();
    QString getNombre();

    void setIdtusuario(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrar();
    bool completar();
};

#endif // TUSUARIO_H
