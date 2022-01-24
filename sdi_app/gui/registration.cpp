#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>
#include "start.h"

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty() == true)
    {
        ui->label->setText("Enter missing details");
    }
    else if (ui->lineEdit_2->text().isEmpty() == true)
    {
        ui->label->setText("Enter missing details");
    }
    else if (ui->lineEdit_3->text().isEmpty() == true)
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
    else {
        //Encrypt
        //Pass all details to the db
        QMessageBox::information(this, "Registration", "Account was succesfully created");
        this->hide();
        start start;
        start.setModal(true);
        start.exec();
    }
}
