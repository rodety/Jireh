#ifndef USUARIOSFORM_H
#define USUARIOSFORM_H

#include <QWidget>
#include <QtSql>
#include <QDataWidgetMapper>
#include <QLabel>

namespace Ui {
class UsuariosForm;
}

class UsuariosForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit UsuariosForm(QWidget *parent = 0);
    ~UsuariosForm();
    
private slots:
    void on_list_tableView_activated(const QModelIndex &index);
    void on_save_pushButton_clicked();
    void on_cancel_pushButton_clicked();
    void on_Module_tabWidget_currentChanged(int index);
    void on_nuevo_pushButton_clicked();
    void on_editar_pushButton_clicked();
    void on_pB_buscar_clicked();

    //void on_list_tableView_clicked(const QModelIndex &index);

    //void on_list_tableView_doubleClicked(const QModelIndex &index);

    void on_Up_activated();

private:
    bool isNew;
    int curRow;
    Ui::UsuariosForm *ui;
    QDataWidgetMapper * mapper;
    QSqlRelationalTableModel * relTableModel;
    QSqlRelationalTableModel *permisosModel;
    inline void configListTab();
    inline void configMapper();
    inline void configDetailsForm();
    inline void configPermisosModelView();
    inline void refresh();
    inline void refreshDetailsView();
    inline void refreshPermisosView();
    inline void showPermisos();
    inline void createPermisoRec(int &idMod,QSqlRecord & rcd);
    void agregarPermisos();
    inline void clearForm();

};

class NoEditItemDelegate: public QItemDelegate
{
protected:

  QWidget *	createEditor ( QWidget * parent, const QStyleOptionViewItem & /*option*/, const QModelIndex & /*index*/ )
  const{return new QLabel(parent);}

};

#endif // USUARIOSFORM_H
