#ifndef MARCA_H
#define MARCA_H

#include <objetopersistente.h>

class m_marca:public ObjetoPersistente
{
private:
    QString idMarca;
    QString nombre;
public:
    m_marca();

    QString getIdMarca();
    QString getNombre();

    void setIdMarca(QString tmp);
    void setNombre(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrarId();    
    bool completar();
};

#endif // MARCA_H
