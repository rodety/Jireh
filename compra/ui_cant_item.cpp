#include "ui_cant_item.h"
#include "ui_ui_cant_item.h"

ui_cant_item::ui_cant_item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_cant_item)
{
    ui->setupUi(this);
}

ui_cant_item::~ui_cant_item()
{
    delete ui;
}

void ui_cant_item::on_pushButton_clicked()
{

    close();
}
