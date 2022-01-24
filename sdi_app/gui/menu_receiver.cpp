#include "menu_receiver.h"
#include "ui_menu_receiver.h"

menu_receiver::menu_receiver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_receiver)
{
    ui->setupUi(this);
}

menu_receiver::~menu_receiver()
{
    delete ui;
}
