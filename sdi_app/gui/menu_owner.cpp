#include "menu_owner.h"
#include "ui_menu_owner.h"

menu_owner::menu_owner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_owner)
{
    ui->setupUi(this);
}

menu_owner::~menu_owner()
{
    delete ui;
}

void menu_owner::on_pushButton_clicked()
{
    emit log_out();
}
