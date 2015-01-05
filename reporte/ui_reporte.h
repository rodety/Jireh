#ifndef UI_REPORTE_H
#define UI_REPORTE_H

#include <QWidget>

namespace Ui {
class ui_reporte;
}

class ui_reporte : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_reporte(QWidget *parent = 0);
    ~ui_reporte();
    
private:
    Ui::ui_reporte *ui;
    void execute();
};

#endif // UI_REPORTE_H
