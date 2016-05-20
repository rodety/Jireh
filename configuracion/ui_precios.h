#ifndef UI_PRECIOS_H
#define UI_PRECIOS_H

#include <QWidget>

namespace Ui {
    class ui_precios;
}

class ui_precios : public QWidget
{
    Q_OBJECT

public:
    explicit ui_precios(QWidget *parent = 0);
    ~ui_precios();

private slots:
    void on_pushButton_descuentoGeneral_clicked();

private:
    Ui::ui_precios *ui;
public:
    bool actualizar_descuento();
};

#endif // UI_PRECIOS_H
