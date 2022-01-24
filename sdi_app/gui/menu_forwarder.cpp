#include "menu_forwarder.h"
#include "ui_menu_forwarder.h"
#include "start.h"

menu_forwarder::menu_forwarder(QWidget *parent) :
    QDialog(parent),
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
    //log out User function
    this->hide();
    start start;
    start.setModal(true);
    start.exec();
}

void menu_forwarder::on_pushButton_2_clicked()
{
    this->hide();
    order_history order_history;
    order_history.setModal(true);
    order_history.exec();
}
