#include "menu_forwarder.h"
#include "ui_menu_forwarder.h"

menu_forwarder::menu_forwarder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_forwarder)
{
    ui->setupUi(this);
}

menu_forwarder::~menu_forwarder()
{
    delete ui;
}



void menu_forwarder::on_pushButton_clicked()
{
    emit log_out();
}
