#ifndef UI_CANTIDAD_H
#define UI_CANTIDAD_H

#include <QWidget>

namespace Ui {
    class ui_cantidad;
}

class ui_cantidad : public QWidget
{
    Q_OBJECT

public:
    explicit ui_cantidad(QWidget *parent = 0);
    ~ui_cantidad();
    void setDatos(QString codigo,QString descripcion);

private slots:
    void on_pushButton_aceptar_clicked();

private:
    Ui::ui_cantidad *ui;
    QString codigo;
    QString descripcion;
signals:
    void enviarCantidad(QString,QString,int,double);
};

#endif // UI_CANTIDAD_H
