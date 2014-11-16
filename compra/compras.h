#ifndef COMPRAS_H
#define COMPRAS_H

#include <QWidget>
#include<QTableWidgetItem>
#include<map>
#include <compra/compra.h>
#include <QSqlRelationalTableModel>
#include <compra/object_proveedor.h>
using namespace std;

namespace Ui {
class compras;
}

class compras : public QWidget
{
    Q_OBJECT
public:
    void setCant(int cant){currentCant = cant;}

    void updateListCompras();
    void loadCompra(QString idCompra);
public slots:
    void getProveedor(QString,QString,QString,QString);
    void addItemProductos(QString,QString,QString,int);
public:
    explicit compras(QWidget *parent = 0);
    ~compras();
    
private slots:
    void on_pushButton_clicked();    

    void on_pushButton_buscar_proveedor_clicked();

    void on_pushButton_buscar_producto_clicked();        

    void on_pushButton_guardar_clicked();

    void on_tableWidget_Compras_itemClicked(QTableWidgetItem *item);

    void on_pushButton_ver_compra_clicked();

    void on_lineEdit_proveedor_returnPressed();

    void on_lineEdit_productos_returnPressed();

    void on_tableWidget_Compras_doubleClicked(const QModelIndex &index);

    void on_tableWidget__items_productos_itemDoubleClicked(QTableWidgetItem *item);

    void on_pushButton_eliminar_compra_clicked();


    void on_tableWidget__items_productos_doubleClicked(const QModelIndex &index);

    void on_pushButton_limpiar_clicked();

    void on_tableView_compras_doubleClicked(const QModelIndex &index);    



private:
    Ui::compras *ui;    
    map<QString,QString> Productos;
    map<QString,QString> Productos_Agregados;
    map<QString,QString> Compras;
    int contador;
    int currentCant;
    double compra_total;
    QString current_idCompras;
    int currentItem;
    compra* actualCompra;
    double igv;
    QString idProveedor;
    QSqlRelationalTableModel* productos_Model;
    void habilitarInterfaz(bool);

};

#endif // COMPRAS_H
