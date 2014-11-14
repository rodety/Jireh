#ifndef DIALOGBUSCARUSUARIOS_H
#define DIALOGBUSCARUSUARIOS_H

#include <QDialog>

namespace Ui {
class DialogBuscarUsuarios;
}

class DialogBuscarUsuarios : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogBuscarUsuarios(QWidget *parent = 0);
    ~DialogBuscarUsuarios();
    QString getQueryFilter();
    
private:
    Ui::DialogBuscarUsuarios *ui;
};

#endif // DIALOGBUSCARUSUARIOS_H
