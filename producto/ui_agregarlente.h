#ifndef UI_AGREGARLENTE_H
#define UI_AGREGARLENTE_H

#include <QWidget>
#include <QMessageBox>
#include <producto/lentecontacto.h>

namespace Ui {
class ui_agregarLente;
}

class ui_agregarLente : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_agregarLente(QWidget *parent = 0);
    ~ui_agregarLente();
    void setModo(bool m);
    void setLenteContacto(lenteContacto* l);
    bool verificarRestricciones();
signals:
    void guardado();
private slots:
    void on_pushButton_aceptar_clicked();

    void on_pushButton_xMarca_clicked();

    void on_pushButton_xTipoLente_clicked();

    void on_pushButton_xPotencia_clicked();

    void on_pushButton_xCurvaBase_clicked();

    void on_pushButton_xDiametro_clicked();

    void on_pushButton_xTiempoUso_clicked();

    void on_pushButton_xMaterial_clicked();

    void on_pushButton_xEstado_clicked();

private:
    Ui::ui_agregarLente *ui;
    bool modo;//0 agregar 1 actualizar
    lenteContacto pLenteContacto;
};

#endif // UI_AGREGARLENTE_H
