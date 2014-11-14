#ifndef UI_DATOS_COMPRAS_H
#define UI_DATOS_COMPRAS_H

#include <QWidget>
#include <QDate>
#include <QString>
namespace Ui {
class ui_datos_compras;
}

class ui_datos_compras : public QWidget
{
    Q_OBJECT
public:
    void setdataproveedor(QDate fecha,QString proveedor, QString ruc, QString direccion, QString total);
    void additemproducto(QString codigo,QString descripcion, QString accesorios, QString precio,QString cantidad, QString total);
private:
    int count_row;
public:
    explicit ui_datos_compras(QWidget *parent = 0);
    ~ui_datos_compras();
    
private slots:
    void on_pushButton_4_clicked();

private:
    Ui::ui_datos_compras *ui;
};

#endif // UI_DATOS_COMPRAS_H
