#ifndef NEWALERTA_ALERTA_UI_H
#define NEWALERTA_ALERTA_UI_H

#include <QSqlQuery>
#include <QWidget>
#include <agenda/alerta.h>

class alertas_ui;
class agenda_ui;

namespace Ui {
    class newalerta_alerta_ui;
}

class newalerta_alerta_ui : public QWidget
{
    Q_OBJECT

public:
    explicit newalerta_alerta_ui(QWidget *parent = 0);
    ~newalerta_alerta_ui();
    void set_type_alert(int type);
    void create_alert(QString type);    
    void set_alerta(alerta a);
    void set_comportaminto(int c);

private slots:
    void on_pushButton_Acept_clicked();
    void on_pushButton_Cancel_clicked();


public slots:
signals:
    void updateChange();

private:
    Ui::newalerta_alerta_ui *ui;
    int type_alert;
    QString code_var;
    QString alert_type_var;
    alerta alerta_actual;
    int comportamiento;
};

#endif // NEWALERTA_ALERTA_UI_H
