#ifndef UI_CONFIGURACION_H
#define UI_CONFIGURACION_H
#include "configurador.h"
#include <QWidget>
#include <map>
#include <vitrina/ui_agregar_empresa.h>
#include <vitrina/ui_tienda_agregar.h>
#include <configuracion/programa.h>
#include <vitrina/object_Empresa.h>
#include <vitrina/object_Tienda.h>
class ui_agregar_empresa;
using namespace std;
namespace Ui {
class ui_configuracion;
}

class ui_configuracion : public QWidget
{
    Q_OBJECT

public:
    explicit ui_configuracion(QWidget *parent = 0);
    ~ui_configuracion();
public:

    QString get_idEmpresa();
    QString get_idTienda();
    void set_idEmpresa(QString);
    void set_idTienda(QString);
    void loadTableConfiguracion();
public slots:
    void update_comboBox_Empresa();
    void update_comboBox_Tienda(QString idEmpresa);

private slots:
    void on_btn_testConexion_clicked();
    void on_comboBox_empresa_currentIndexChanged(const QString &arg1);
    void on_btn_saveConfiguration_clicked();
    void on_comboBox_tienda_currentTextChanged(const QString &arg1);

    void on_comboBox_tienda_currentIndexChanged(const QString &arg1);

    void on_btn_eliminar_ducumento_clicked();

    void on_btn_eliminar_tusuario_clicked();


    void on_btn_eliminar_estado_clicked();


    void on_comboBox_Documento_currentIndexChanged(const QString &arg1);

    void on_comboBox_tipoUsuario_currentIndexChanged(const QString &arg1);

    void on_comboBox_estadoProductos_currentIndexChanged(const QString &arg1);

    void on_btnAgregar_empresa_clicked();

    void on_btnAgregar_Tienda_clicked();

    void on_btn_backup_clicked();
    void on_pushButton_EditConfiguracion_clicked();

    void on_tableView_configuracion_clicked(const QModelIndex &index);

    void actualizar_descuento();

signals:
    void closeparent();

private:
    Ui::ui_configuracion *ui;
    void saveConfiguration();
    QString idEmpresa;
    QString idTienda;
    void loadConfiguration();
    configurador* config;
    std::map<int,QString> res;
    void controlbotones(bool a);
    ui_agregar_empresa* add_empresa;
    ui_tienda_agregar* tienda_agregar;
    QModelIndex index;
    int id;
    bool conexion;
    map<int,int> posComboboxEmpresa;
    map<int,int> posComboboxTienda;

    map<QString,QString> Empresas;
    map<QString,QString> Tiendas;

};

#endif // UI_CONFIGURACION_H
