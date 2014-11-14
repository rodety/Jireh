#ifndef UI_PROVEEDORES_H
#define UI_PROVEEDORES_H

#include <QWidget>
#include "proveedor.h"
#include<map>
#include <QTableWidgetItem>
using namespace std;
namespace Ui {
class ui_proveedores;
}

class ui_proveedores : public QWidget
{
    Q_OBJECT
private:
    QString currentIdProveedor;
    map<QString,QString> Proveedores;
public:
    QString get_currentidProveedor();
    void set_currentidProveedor(QString id);
    void update_list_proveedores();

    
public:
    explicit ui_proveedores(QWidget *parent = 0);
    ~ui_proveedores();
public slots:
signals:
    void sentidProveedor(QString,QString,QString,QString);//Enviando Id,ruc,razonSocial,Direccion;

    
private slots:

    void on_pushButton_add_proveedor_clicked();

    void on_pushButton_edit_proveedor_clicked();

    void on_pushButton_sup_proveedor_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);



    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::ui_proveedores *ui;
};

#endif // UI_PROVEEDORES_H
