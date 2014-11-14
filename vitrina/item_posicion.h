#ifndef ITEM_POSICION_H
#define ITEM_POSICION_H
#include "objetopersistente.h"

class item_posicion
{
private:
    QString idProducto;
    QString idVitrina;
    int fila;
    int columna;
    int nivel;
    QString colaborador;

public:
    item_posicion();
    item_posicion(QString,QString,int,int,int,QString);

    QString get_idProducto()            {return idProducto;}
    QString get_idVitrina()             {return idVitrina;}
    int get_fila()                      {return fila;}
    int get_columna()                   {return columna;}
    int get_nivel()                     {return nivel;}
    QString get_colaborador()           {return colaborador;}

    void set_idProducto(QString tmp)    {idProducto=tmp;}
    void set_idVitrina(QString tmp)     {idVitrina=tmp;}
    void set_fila(int tmp)              {fila=tmp;}
    void set_columna(int tmp)           {columna=tmp;}
    void set_nivel(int tmp)             {nivel=tmp;}
    void set_colaborador(QString tmp)   {colaborador=tmp;}

    bool agregar();
    bool actualizar();
    bool eliminar();


};

#endif // ITEM_POSICION_H
