#include "menu_company.h"
#include "ui_menu_company.h"

menu_company::menu_company(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_company)
{
    ui->setupUi(this);
}

menu_company::~menu_company()
{
    delete ui;
}

void menu_company::on_pushButton_clicked()
{
    emit log_out();
}

void menu_company::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void menu_company::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_company::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void menu_company::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_company::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void menu_company::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_company::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void menu_company::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
