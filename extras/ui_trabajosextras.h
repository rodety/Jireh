#ifndef UI_TRABAJOSEXTRAS_H
#define UI_TRABAJOSEXTRAS_H

#include <QWidget>
#include <QMessageBox>
#include <extras/trabajosextras.h>
#include <QValidator>
namespace Ui {
class ui_trabajosExtras;
}

class ui_trabajosExtras : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_trabajosExtras(QWidget *parent = 0);
    ~ui_trabajosExtras();
    void setModo(bool m);
    void setTrabajosExtras(trabajosExtras* t);
    bool verificarRestricciones();
signals:
    void guardado();
private slots:
    void on_pushButton_agregar_clicked();

private:
    Ui::ui_trabajosExtras *ui;
    trabajosExtras pTrabajosExtras;
    bool modo;//0 agregar 1 actualizar
    QValidator *validator;
};

#endif // UI_TRABAJOSEXTRAS_H
