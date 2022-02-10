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

void menu_driver::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void menu_driver::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_driver::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void menu_driver::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_driver::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void menu_driver::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
