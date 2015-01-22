#ifndef AGENDA_UI_H
#define AGENDA_UI_H

#include <QWidget>
#include <QTableWidget>
#include "funciones.h"
#include "newalerta_alerta_ui.h"
#include <map>
#include <configuracion/usuario.h>
using namespace std;
//hello
namespace Ui {
    class agenda_ui;
}

class agenda_ui : public QWidget
{
    Q_OBJECT

public:
    explicit agenda_ui(QWidget *parent = 0);
    ~agenda_ui();

    void show_personal_combox();
    void set_access_level(int access);
    int access_user_type;
    void update_table_agenda_form();
    void update_table_alerta_personal();
    QString curren_user_code_var;
    QString code_var_alerta_general;
    QString code_var_alerta_personal;
    bool ActualizarRegistro(QString idVenta);

private:
    Ui::agenda_ui *ui;
    map<QString,QString> Tiendas;
    QDate fecha;
    int tipoColaborador;


private slots:


    void on_pushButton_AlertaGeneral_changeColor_clicked();
    void on_pushButton_Alert_Personales_add_clicked();
    void on_dateEdit_Alerta_Personales_dateChanged(const QDate &date);
    void on_pushButton_show_SelectAlert_Personales_4_clicked();
    void on_pushButton_Alert_Personales_edit_clicked();
    void on_pushButton_Alert_Personales_remove_clicked();
    void on_pushButton_agenda_changeColor_clicked();
    void on_pushButton_update_Agenda_clicked();
    void on_calendarWidget_clicked(const QDate &date);
    void on_tablaView_Agend_doubleClicked(const QModelIndex &index);
    void on_pushButton_Alert_General_add_clicked();
    void updateTable_Alert_General();
    void updateTable_Alert_Personal();
    void actualizar_combo_tienda();
    void actualizar_tiempo(const QDate &date);
    void on_pushButton_imprimir_clicked();

public slots:
    void calcularReporte();






    void on_pushButton_Alert_General_edit_clicked();
    void on_tableView_Alert_General_doubleClicked(const QModelIndex &index);
    void on_pushButton_Alert_General_remove_clicked();
    void on_tableView_Alert_Personal_doubleClicked(const QModelIndex &index);
    void on_comboBox_tienda_activated(int index);
    void on_comboBox_tipo_pendiente_currentIndexChanged(int index);
    void on_tableView_Main_Alert_doubleClicked(const QModelIndex &index);
};

#endif // AGENDA_UI_H

