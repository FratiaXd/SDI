#include "menu_driver.h"
#include "ui_menu_driver.h"

menu_driver::menu_driver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_driver)
{
    ui->setupUi(this);
}

menu_driver::~menu_driver()
{
    delete ui;
}
