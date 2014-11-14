#ifndef UI_TRASPASO_ALMACEN_H
#define UI_TRASPASO_ALMACEN_H
#include <QWidget>
#include <QTableWidgetItem>
#include <map>
#include <QDebug>
#include <QSqlQuery>
#include <iostream>
#include <vitrina/ui_tienda.h>
using namespace std;

namespace Ui {
class ui_traspaso_almacen;
}

class ui_traspaso_almacen : public QWidget
{
    Q_OBJECT


private:
    ui_tienda * ui_tienda_traspaso;
    QString idItem_tras;
    QString currentIdEmpresa;
    QString currentIdTienda;
    QString currentIdAlmacen;
    QString currentIdAndamio;
    QString currentIdContenedor;

    map<QString,QString> Empresas;
    map<QString,QString> Tiendas;
    map<QString,QString> Almacenes;
    map<QString,QString> Andamios;
    map<QString,QString> Contenedor;


public:
    QString get_currentIdEmpresa();
    QString get_currentIdTienda();
    QString get_currentIdAlmacen();
    QString get_currentIdAndamio();
    QString get_currentIdContenedor();
    ui_tienda* get_ui_tienda_traspaso(){return ui_tienda_traspaso;}
    QString get_idItem_tras(){return idItem_tras;}

    void set_ui_tienda_traspaso(ui_tienda* tmp){ui_tienda_traspaso=tmp;}
    void set_idItem_tras(QString tmp){idItem_tras=tmp;}
    void set_currentIdEmpresa(QString);
    void set_currentIdTienda(QString);
    void set_currentIdAlmacen(QString);
    void set_currentIdAndamio(QString);
    void set_currentIdContenedor(QString);

    void update_comboBox_Empresa();
    void update_comboBox_Tienda(QString idEmpresa);
    void update_comboBox_Almacen(QString idTienda);
    void update_comboBox_Andamio(QString idAlmacen);

    void clear_widget_Contenedores();
    void set_dimension_widget_Contenedores();
    void update_widget_Contenedores();

public:
    explicit ui_traspaso_almacen(QWidget *parent = 0);
    ~ui_traspaso_almacen();

private slots:


    void on_pushButton_aceptar_traspaso_clicked();

    void on_comboBox_Empresa_currentIndexChanged(const QString &arg1);

    void on_comboBox_Tienda_currentIndexChanged(const QString &arg1);

    void on_comboBox_Almacen_currentIndexChanged(const QString &arg1);

    void on_comboBox_Andamio_currentIndexChanged(const QString &arg1);

    void on_tableWidget_griContenedores_itemSelectionChanged();

private:
    Ui::ui_traspaso_almacen *ui;
};

#endif // UI_TRASPASO_ALMACEN_H
