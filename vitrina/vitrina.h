#ifndef VITRINA_H
#define VITRINA_H

#include <objetopersistente.h>
#include <QSqlQueryModel>
#include "configuracion/sesion.h"

class vitrina:public ObjetoPersistente
{
    private:
        QString idUbicacion;
        QString idTienda;
        QString nombre;
        int num_fila;
        int num_columna;
        int num_nivel;
        int habilitado;
    public:
        vitrina();
        vitrina(QString,QString,QString,int,int,int,int);

        QString getIdVitrina() { return idUbicacion; }
        QString getIdTienda()  { return idTienda; }
        QString getNombre()    { return nombre; }
        int getNum_Filas()     { return num_fila; }
        int getNum_Columnas()  { return num_columna; }
        int getNum_Niveles()   { return num_nivel; }
        int getHabilitado()    { return habilitado; }

        void setIdVitrina(QString tmp) { idUbicacion=tmp;}
        void setIdTienda(QString tmp)  { idTienda=tmp;}
        void setAlias(QString tmp)     { nombre=tmp;}
        void setNum_Filas(int tmp)     { num_fila=tmp;}
        void setNum_Columnas(int tmp)  { num_columna=tmp;}
        void setNum_Niveles(int tmp)   { num_nivel=tmp;}
        void setHabilitado(int tmp)    { habilitado=tmp;}

//        static QSqlQueryModel* mostrar();
        bool agregar();        
        bool eliminar();
        bool actualizar();
        bool ver_usuario();

//        bool buscar();   //parece que no se usa



};






#endif // VITRINA_H
