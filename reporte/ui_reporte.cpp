#include "ui_reporte.h"
#include "ui_ui_reporte.h"

ui_reporte::ui_reporte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_reporte)
{
    ui->setupUi(this);
}

ui_reporte::~ui_reporte()
{
    delete ui;
}
