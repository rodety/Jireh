#ifndef UI_AGREGAROTROS_H
#define UI_AGREGAROTROS_H

#include <QWidget>
#include <QMessageBox>
#include <producto/otros.h>

namespace Ui {
class ui_agregarOtros;
}

class ui_agregarOtros : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_agregarOtros(QWidget *parent = 0);
    ~ui_agregarOtros();
    void setModo(bool m);
    void setOtros(otros* o);
    bool verificarRestricciones();
signals:
    void guardado();
private slots:
    void on_pushButton_agregar_clicked();

    void on_pushButton_xmarca_clicked();

    void on_pushButton_xcalidad_clicked();

    void on_pushButton_xcolor_clicked();

    void on_pushButton_xestado_clicked();

    void on_pushButton_xtalla_clicked();

    void on_pushButton_xtipo_clicked();

    void on_pushButton_xgenero_clicked();

private:
    Ui::ui_agregarOtros *ui;
    bool modo;//0 agregar 1 actualizar
    otros pOtros;
};

#endif // UI_AGREGAROTROS_H
