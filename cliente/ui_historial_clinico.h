#ifndef UI_HISTORIAL_CLINICO_H
#define UI_HISTORIAL_CLINICO_H

#include <QWidget>
#include <cliente/historialclinico.h>
#include <cliente/cliente.h>
#include <QMessageBox>

namespace Ui {
class ui_historial_clinico;
}

class ui_historial_clinico : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_historial_clinico(QWidget *parent = 0);
    ~ui_historial_clinico();
    void setCliente(cliente*);
    void setHistorial(historialClinico*);
signals:
    void guarde();
private slots:
    bool verificaRestriccionesHistorial();

    void on_pushButton_Cancelar_2_clicked();
    void on_pushButton_Aceptar_2_clicked();

private:
    Ui::ui_historial_clinico *ui;
    cliente cliente_act;
    historialClinico historial_act;
};

#endif // UI_HISTORIAL_CLINICO_H
