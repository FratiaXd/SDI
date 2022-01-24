#include "menu_trcomp.h"
#include "ui_menu_trcomp.h"

menu_trcomp::menu_trcomp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_trcomp)
{
    ui->setupUi(this);
}

menu_trcomp::~menu_trcomp()
{
    delete ui;
}
