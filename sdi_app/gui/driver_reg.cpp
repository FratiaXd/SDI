#include "driver_reg.h"
#include "ui_driver_reg.h"

driver_reg::driver_reg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::driver_reg)
{
    ui->setupUi(this);
}

driver_reg::~driver_reg()
{
    delete ui;
}

void driver_reg::on_pushButton_clicked()
{
    if (ui->lineEdit_3->text().isEmpty() == true)
    {
        ui->label->setText("Enter missing details");
    }
    else if (ui->lineEdit_4->text().isEmpty() == true)
    {
        ui->label->setText("Enter missing details");
    }
    else if (ui->lineEdit_5->text().isEmpty() == true)
    {
        ui->label->setText("Enter missing details");
    }
    else if (ui->lineEdit_6->text().isEmpty() == true)
    {
        ui->label->setText("Enter missing details");
    }
    else if (ui->lineEdit_7->text().isEmpty() == true)
    {
        ui->label->setText("Enter missing details");
    }
    else
    {
        //check CPC function
        //pass to DB
        //display notification
        this->hide();
        registration registration;
        registration.setModal(true);
        registration.exec();
    }
}
