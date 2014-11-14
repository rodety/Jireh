#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H
#include <QComboBox>
#include <QLineEdit>
#include <QKeyEvent>
#include <QIcon>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <producto/producto.h>
#include <configuracion/tusuario.h>
#include <cliente/documento.h>
#include <producto/genero.h>
#include <QHash>

class MyComboBox:public QComboBox
{
    Q_OBJECT
private:
    QString tipo;
    QIcon*  icono_agregar;    
    QHash<QString, int> HashId;

public:
    MyComboBox(QWidget* parent=0);
    void setTipo(QString tmp);
    void buscarValor(QString tmp);
    bool selecciono();
    int getId(QString);

public slots:
    void ActualizarItemsSimple(QSqlQueryModel* model);
    void ActualizarItems(QSqlQueryModel* model);
    void ActualizarItemsReporte(QSqlQueryModel* model);
    void ActualizarItemsSeleccion(QSqlQueryModel* model);
    void nuevo();
    void agregar();
    void eliminar();
};

#endif // MYCOMBOBOX_H
