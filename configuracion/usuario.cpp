#include "usuario.h"

Usuario::Usuario(int id, int utype, QString uname,QString name , QString flname , QString slname)
    :m_idUsuario(id),m_tipoUsuario(utype),
     m_nombreUsuario(uname),m_nombre(name),
     m_pApellido(flname),m_sApellido(slname)
{
}

Usuario::Usuario(){}
