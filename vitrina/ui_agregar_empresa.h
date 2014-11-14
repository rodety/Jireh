#ifndef UI_AGREGAR_EMPRESA_H
#define UI_AGREGAR_EMPRESA_H

#include <QWidget>
#include "ui_tienda.h"

namespace Ui {
class ui_agregar_empresa;
}

class ui_agregar_empresa : public QWidget
{
    Q_OBJECT
private:
    QString idEmpresa;    
    int behavior;
public:
    void set_idEmpresa(QString idEmpresa);
    QString get_idEmpresa();
    int get_behavior();
    void set_behavior(int);
    void update_form();

    
public:
    explicit ui_agregar_empresa(QWidget *parent = 0);
    ~ui_agregar_empresa();
    
private slots:
    void on_pushButton_accept_clicked();

    void on_pushButton_cancel_clicked();
public slots:
signals:
    void actualizarParent();


private:
    Ui::ui_agregar_empresa *ui;
};

#endif // UI_AGREGAR_EMPRESA_H
