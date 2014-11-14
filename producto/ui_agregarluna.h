#ifndef UI_AGREGARLUNA_H
#define UI_AGREGARLUNA_H

#include <QWidget>
#include <QMessageBox>
#include <producto/luna.h>
#include <producto/object_Laboratorio.h>
#include <producto/object_Lista.h>

namespace Ui {
class ui_agregarLuna;
}

class ui_agregarLuna : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_agregarLuna(QWidget *parent = 0);
    ~ui_agregarLuna();
    void setModo(bool m);
    void setLuna(luna* l);
    bool verificarRestricciones();

    
signals:
    void guardado();
private slots:
    void on_pushButton_aceptar_clicked();
    void on_pushButton_xDiametro_clicked();
    void on_pushButton_xCalidad_clicked();
    void on_pushButton_xTipoLuna_clicked();
    void on_pushButton_xTratamiento_clicked();
    void on_pushButton_xEstado_clicked();


private:
    Ui::ui_agregarLuna *ui;
    bool modo;//0 agregar 1 actualizar
    luna pLuna;    
};

#endif // UI_AGREGARLUNA_H
