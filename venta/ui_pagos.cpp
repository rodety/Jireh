#include "ui_pagos.h"
#include "ui_ui_pagos.h"

ui_pagos::ui_pagos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_pagos)
{
    ui->setupUi(this);    
}

ui_pagos::~ui_pagos()
{
    delete ui;
}

void ui_pagos::loadTable(object_VentaPlazo *v_plazo_Object)
{
    v_plazo = v_plazo_Object;
    ui->tableView->setModel(v_plazo->mf_show());
}
