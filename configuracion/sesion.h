#ifndef SESION_H
#define SESION_H

#include  <QTime>
#include <QObject>
#include "usuario.h"
#include <map>
#include <QPair>
#include <vitrina/object_Tienda.h>
#include <configuracion/object_Configuracion.h>
/**
 * @class Sesion
 * @brief Clase singletone que representa el la sesion de el sistema
 */


class Sesion:public QObject
{
    Q_OBJECT
    private:
        Sesion(Usuario * usr = 0);
        static Sesion* mp_instance;  ///<instancia de la clase singletone
        static int intentos;         ///<Numero de intentos de inicio de sesion
        static bool sleep;           ///<inhabilita el inicio de sesion por un tiempo determinado
        static QTime tiempoBloqueo;  ///<Cuenta el tiempo de bloqueo
        static int numMinIntentos;  ///<Numero minimo de intentos de inicio
        static int numMaxIntentos;  ///<Numero maximo de intentos de inicio
        static int tiempoEspera;    ///<Tiempo de bloqueo de el inicio
        static int idEmpresa;       ///<Empresa en la que se inicio sesion
        static int idTienda;       ///<Tienda en la que se inicio sesion
        static double impuesto;    ///<Igv
        QTime s_time;               ///<tiempo de inicio de sesion
        Usuario * s_user;           ///<referencia a un usuario
        object_Tienda* tienda;     ///referencia a Tienda
        object_Configuracion* configuracion;   ///Referencia a configuracion
public:

    enum sesionState{UsuarioDeshabilitado,PassUsrWrong,SleepTime,ResetPass,inicioOK};
    static Sesion* getSesion();
    static int Iniciar(QString user,QString pass);
    static void Configurar(int nminI,int nmaxI,int tEspera);
    Usuario *get_Usuario(){return s_user;}
    object_Tienda* get_Tienda(){return tienda;}
    object_Configuracion* get_Configuracion(){return configuracion;}
    static int getIdColaborador() { return mp_instance->s_user->get_id(); }
    static int getIdTypeColaborador();
    /// @return Retorna el tiempo en milisegundos desde que se inicio la sesion
    int get_time(){return s_time.elapsed();}
    std::map<int,bool> get_Permisos();
    static QPair < int,int > getUbicacion();
    //Fist Empresa, Second Tienda
    static void setUbicacion(int,int);
    void loadUbicacion();
    void uptadeConfiguracion();

    static double getIgv() { return impuesto;}

};

#endif // SESION_H
