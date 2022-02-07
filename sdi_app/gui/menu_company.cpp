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
