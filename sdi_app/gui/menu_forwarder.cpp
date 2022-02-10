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

void menu_forwarder::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void menu_forwarder::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_forwarder::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void menu_forwarder::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_forwarder::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void menu_forwarder::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
