#include "start.h"
#include "ui_start.h"

start::start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
}

start::~start()
{
    delete ui;
}

void start::on_pushButton_2_clicked()
{
    this->hide();
    user_type user_type;
    user_type.setModal(true);
    user_type.exec();
}

void start::on_pushButton_clicked()
{
    this->hide();
    menu_cargoown menu_cargoown;
    menu_cargoown.setModal(true);
    menu_cargoown.exec();
}
