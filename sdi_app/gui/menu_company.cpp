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
