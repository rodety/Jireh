#ifndef UI_PAGOS_H
#define UI_PAGOS_H

#include <QWidget>
#include <venta/object_VentaPlazo.h>

namespace Ui {
class ui_pagos;
}

class ui_pagos : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_pagos(QWidget *parent = 0);
    ~ui_pagos();
    void loadTable(object_VentaPlazo *v_plazo);
    
private:
    Ui::ui_pagos *ui;
    object_VentaPlazo *v_plazo;
};

#endif // UI_PAGOS_H
