#include "user_type.h"
#include "ui_user_type.h"

user_type::user_type(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_type)
{
    ui->setupUi(this);
}

user_type::~user_type()
{
    delete ui;
}

void user_type::on_pushButton_clicked()
{
    if (ui->radioButton->isChecked() == true)
    {
        //set type cargo owner true
        this->hide();
        registration registration;
        registration.setModal(true);
        registration.exec();
    }
    else if (ui->radioButton_2->isChecked() == true)
    {
        //set type forwarder true
        this->hide();
        registration registration;
        registration.setModal(true);
        registration.exec();
    }
    else if (ui->radioButton_3->isChecked() == true)
    {
        //set type receiver true
        this->hide();
        registration registration;
        registration.setModal(true);
        registration.exec();
    }
    else if (ui->radioButton_4->isChecked() == true)
    {
        //set type transportation company true
        this->hide();
        registration registration;
        registration.setModal(true);
        registration.exec();
    }
    else if (ui->radioButton_5->isChecked() == true)
    {
        //set type driver true
        this->hide();
        registration registration;
        registration.setModal(true);
        registration.exec();
    }
    else
    {
        ui->label->setText("Choose account type");
    }
}
