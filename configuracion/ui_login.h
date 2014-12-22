#ifndef UI_LOGIN_H
#define UI_LOGIN_H
#include "sesion.h"
#include <QWidget>
#include "mainwindow.h"


namespace Ui {
class UI_LOGIN;
}

class UI_LOGIN : public QWidget
{
    Q_OBJECT

public:
    explicit UI_LOGIN(QWidget *parent = 0);
    ~UI_LOGIN();

private slots:
    void on_pushButton_Aceptar_clicked();
    void on_pushButton_Cancelar_clicked();

private:
    Ui::UI_LOGIN *ui;
    Sesion * a;
};

#endif // UI_LOGIN_H
