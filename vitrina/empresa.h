#ifndef EMPRESA_H
#define EMPRESA_H

#include <objetopersistente.h>
#include <QSqlQueryModel>

class empresa:public ObjetoPersistente
{
    private:
        QString id;
        QString ruc;
        QString razonSocial;
        QString domilicioFiscal;
        QString telefono;
        QString representante;
        QString email;
        QString web;


    public:
        empresa();
        empresa(QString idEmpresa,QString raz_social, QString ruc,QString domicilio,QString telefono, QString representante, QString email, QString web);
        QString getId();
        QString getRuc();
        QString getrazonSocial();
        QString getDomilicioFiscal();
        QString getTelefono();
        QString getRepresentante();
        QString getEmail();
        QString getWeb();


        void setId(QString);
        void setRuc(QString);
        void setRazonSocial(QString);
        void setDomicilioFiscal(QString);
        void setTelefono(QString);
        void setRepresentante(QString);
        void setEmail(QString);
        void setWeb(QString);

        bool agregar();
        bool actualizar();
        bool eliminar();
        static QSqlQueryModel* mostrar();



};

#endif // EMPRESA_H
