#ifndef CLIENTE_H
#define CLIENTE_H

#include <objetopersistente.h>
#include <cliente/documento.h>

class cliente:ObjetoPersistente
{
private:
    QString idCliente;
    QString nombres;
    QString primerApellido;
    QString segundoApellido;
    QString numeroDocumento;
    QString direccion;
    QString sexo;
    QString fechaNacimiento;
    QString telefono;
    QString telefono2;
    QString movil;
    QString email;
    QString nacionalidad;
    documento pDocumento;
    QString ruc;
    QString razonSocial;
    QString direccion2;
public:
    cliente();

    QString getIdCliente();
    QString getNombres();
    QString getPrimerApellido();
    QString getSegundoApellido();
    QString getNumeroDocumento();
    QString getDireccion();
    QString getSexo();
    QString getFechaNacimiento();
    QString getTelefono();
    QString getTelefono2();
    QString getMovil();
    QString getEmail();
    QString getNacionalidad();
    documento getDocumento();
    QString getRuc();
    QString getRazonSocial();
    QString getDireccion2();

    void setIdCliente(QString tmp);
    void setNombres(QString tmp);
    void setPrimerApellido(QString tmp);
    void setSegundoApellido(QString tmp);
    void setNumeroDocumento(QString tmp);
    void setDireccion(QString tmp);
    void setSexo(QString tmp);
    void setFechaNacimiento(QString tmp);
    void setTelefono(QString tmp);
    void setTelefono2(QString tmp);
    void setMovil(QString tmp);
    void setEmail(QString tmp);
    void setNacionalidad(QString tmp);
    void setDocumento(documento tmp);
    void setRuc(QString tmp);
    void setRazonSocial(QString tmp);
    void setDireccion2(QString tmp);

    bool agregar();
    bool actualizar();
    bool eliminar();

    static QSqlQueryModel* mostrar();
    bool completar();
    bool completarId(QString id);

    static QSqlQueryModel* buscarCliente(QString _item);
};

#endif // CLIENTE_H
