#ifndef UI_AGREGARMONTURA_H
#define UI_AGREGARMONTURA_H

#include <QWidget>
#include <QMessageBox>
#include <producto/montura.h>

namespace Ui {
class ui_agregarMontura;
}

class ui_agregarMontura : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_agregarMontura(QWidget *parent = 0);
    ~ui_agregarMontura();
    void setModo(bool m);
    void setMontura(montura* m);
    bool verificarRestricciones();
    
private slots:
    void on_pushButton_agregar_clicked();
    void on_pushButton_xmarca_clicked();
    void on_pushButton_xtamanio_clicked();
    void on_pushButton_xforma_clicked();
    void on_pushButton_xcalidad_clicked();
    void on_pushButton_xcolor_clicked();
    void on_pushButton_xestado_clicked();

    void on_pushButton_xgenero_clicked();

signals:
    void guardado();
private:
    Ui::ui_agregarMontura *ui;
    bool modo;//0 agregar 1 actualizar
    montura pMontura;
};

#endif // UI_AGREGARMONTURA_H
