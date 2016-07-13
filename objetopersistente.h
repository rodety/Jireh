#ifndef OBJETOPERSISTENTE_H
#define OBJETOPERSISTENTE_H
#include <QString>
#include <QSqlQuery>
#include <QList>
#include <QVariant>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>

/**
 * @file objetopersistente.h
 * @class ObjetoPersistente
 * @brief Es una clase virtual pura de persistencia.
 * De esta clase heredaran las mayoria de las clases para
 * usarla como interfaz con las funciones "agregar","actualizar" y "eliminar"
 */

class ObjetoPersistente
{
public:
    ObjetoPersistente();
    virtual bool agregar()=0;
    virtual bool actualizar()=0;
    virtual bool eliminar()=0;

};

#endif // OBJETOPERSISTENTE_H
