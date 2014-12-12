#ifndef UI_CLIENTE_DATOS_H
#define UI_CLIENTE_DATOS_H

#include <QWidget>
#include <cliente/cliente.h>
#include <QMessageBox>

namespace Ui {
class ui_cliente_datos;
}

class ui_cliente_datos : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_cliente_datos(QWidget *parent = 0);
    ~ui_cliente_datos();

    void setCliente(cliente*);
    void setDatosEmpresa();
signals:
    void guarde();
    void enviarCliente(cliente);
private slots:
    bool verificaRestriccionesCliente();

    void on_pushButton_Aceptar_clicked();
    void on_pushButton_Cancelar_clicked();

    void on_pushButton_clicked();

    void on_pushButton_xDocumento_clicked();

private:
    Ui::ui_cliente_datos *ui;

    cliente cliente_act;
    documento pDocumento;
    bool validar_email;
};

#endif // UI_CLIENTE_DATOS_H
