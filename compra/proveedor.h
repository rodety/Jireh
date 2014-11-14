#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include <objetopersistente.h>
class proveedor :public ObjetoPersistente
{
private:

    QString id;
    QString razonSocial;
    QString ruc;
    QString direccion;
    QString telefono1;
    QString telefono2;
    QString nombre_contacto;
    QString email;
    QString nombre_banco;
    QString numero_cuenta;
    QString comentario;
    QString idbanco;

public:

    QString getid();
    QString getrazonSocial();
    QString getruc();
    QString getdireccion();
    QString gettelefono1();
    QString gettelefono2();
    QString getnombre_contacto();
    QString getemail();
    QString getnombre_banco();
    QString getnumero_cuenta();
    QString getcomentario();
    QString getidbanco();

    void setid(QString);
    void setrazonSocial(QString);
    void setruc(QString);
    void setdireccion(QString);
    void settelefono1(QString);
    void settelefono2(QString);
    void setnombre_contacto(QString);
    void setemail(QString);
    void setnombre_banco(QString);
    void setnumero_cuenta(QString);
    void setcomentario(QString);
    void setidbanco(QString);


public:
    proveedor();
    proveedor(QString id,QString raz_social,QString ruc,QString direccion,QString telefono1,QString telefono2,QString nombre_contacto,QString email,QString nombre_banco, QString numero_cuenta,QString comentario);
    bool agregar();
    bool actualizar();
    bool eliminar();

};

#endif // PROVEEDOR_H
