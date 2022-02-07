#include "menu_driver.h"
#include "ui_menu_driver.h"

menu_driver::menu_driver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_driver)
{
    ui->setupUi(this);
}

menu_driver::~menu_driver()
{
    delete ui;
}

void menu_driver::on_pushButton_3_clicked()
{
    emit log_out();
}
