#include "application.h"
#include "ui_application.h"
#include <QMessageBox>

application::application(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::application)
{
    ui->setupUi(this);

    ui->stackedWidget->addWidget(&dmenu);
    ui->stackedWidget->addWidget(&fmenu);
    ui->stackedWidget->addWidget(&omenu);
    ui->stackedWidget->addWidget(&rmenu);
    ui->stackedWidget->addWidget(&cmenu);
}

application::~application()
{
    delete ui;
}

//Start sign up process
void application::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
//user type page
void application::on_pushButton_3_clicked()
{
    if (ui->radioButton->isChecked()) {
        //set user class type driver
        user1.set_type("driver");
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if (ui->radioButton_2->isChecked()) {
        //set user class type forwarder
        user1.set_type("forwarder");
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if (ui->radioButton_3->isChecked()) {
        //set user class type owner
        user1.set_type("owner");
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if (ui->radioButton_4->isChecked()) {
        //set user class type receiver
        user1.set_type("receiver");
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if (ui->radioButton_5->isChecked()) {
        //set user class type company
        user1.set_type("company");
        ui->stackedWidget->setCurrentIndex(3);
    }
    else {
        ui->label_2->setText("Choose account type");
    }

}

//lorry registration page
void application::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    //check cpc
}

//default registration page
void application::on_pushButton_5_clicked()
{
    if (ui->lineEdit_7->text().isEmpty()) {
        ui->label_4->setText("Enter missing details");
    }
    else if (ui->lineEdit_8->text().isEmpty()) {
        ui->label_4->setText("Enter missing details");
    }
    else if (ui->lineEdit_9->text().isEmpty()) {
        ui->label_4->setText("Enter missing details");
    }
    else if (ui->lineEdit_10->text().isEmpty()) {
        ui->label_4->setText("Enter missing details");
    }
    else if (ui->lineEdit_11->text().isEmpty()) {
        ui->label_4->setText("Enter missing details");
    }
    else {
        //create user according to user.type
        string a = ui->lineEdit_7->text().toStdString();
        string b = ui->lineEdit_8->text().toStdString();
        string c = ui->lineEdit_9->text().toStdString();
        string d = ui->lineEdit_10->text().toStdString();
        string e = ui->lineEdit_11->text().toStdString();
        if (user1.get_type() == "driver") {
            //Registration function in user is:
            //Encrypt function
            //Pass all details to the db function
        }
        else if (user1.get_type() == "forwarder") {
            Forwarder forw(a, b, c, d, e, "forwarder");
            //Registration function
        }
        else if (user1.get_type() == "owner") {
            CargoOwner own(a, b, c, d, e, "cargo owner");
            //Registration function
        }
        else if (user1.get_type() == "receiver") {
            User receiv(a, b, c, d, e, "receiver");
            //Registration function
        }
        else if (user1.get_type() == "company") {
            TranspCompany comp(a, b, c, d, e, "transportation company");
            //Registration function
        }
        //destroy user
        QMessageBox::information(this, "Registration", "Account was succesfully created");
        ui->stackedWidget->setCurrentIndex(0);
    }
}
//log in
void application::on_pushButton_2_clicked()
{
    //Log in function in user :
    //Decrypt
    //Check in DB user type
    //Open menu for user
    ui->stackedWidget->setCurrentIndex(4);
}


