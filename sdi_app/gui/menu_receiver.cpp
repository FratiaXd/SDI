#include "menu_receiver.h"
#include "ui_menu_receiver.h"

menu_receiver::menu_receiver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_receiver)
{
    ui->setupUi(this);
}

menu_receiver::~menu_receiver()
{
    delete ui;
}

void menu_receiver::on_pushButton_clicked()
{
    emit log_out();
}

void menu_receiver::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void menu_receiver::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
