#ifndef USUARIO_H
#define USUARIO_H
#include <QString>

/**
 * @class Usuario
 * @brief Representa un usuario registrado que realiza operaciones en el sistema
 */
class Usuario
{
public:
    Usuario();
    Usuario(int id, int utype, QString m_uname,QString name , QString flname , QString slname);
    int get_id(){return m_idUsuario;}
    QString get_nUsuario(){return m_nombreUsuario;}
    QString get_nombre(){return m_nombre;}
    QString get_pApellido(){return m_pApellido;}
    QString get_sApellido(){return m_sApellido;}
    int get_tipoUsuario(){return m_tipoUsuario;}
private:
    int m_idUsuario;        ///<id de usuario de la dase de datos
    int m_tipoUsuario;      ///<id del tipo de usuario
    QString m_nombreUsuario;///<Nombre corto o alias
    QString m_nombre;       ///<Nombre de el usuario
    QString m_pApellido;    ///<Primer apellido
    QString m_sApellido;    ///<Segundo apellido
};

#endif // USUARIO_H
