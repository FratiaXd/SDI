#include "menu_cargoown.h"
#include "ui_menu_cargoown.h"

menu_cargoown::menu_cargoown(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_cargoown)
{
    ui->setupUi(this);
}

menu_cargoown::~menu_cargoown()
{
    delete ui;
}
