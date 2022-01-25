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
    if (ui->radioButton->isChecked() == true) {
        //set user class type driver
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if (ui->radioButton_2->isChecked() == true) {
        //set user class type forwarder
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if (ui->radioButton_3->isChecked() == true) {
        //set user class type owner
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if (ui->radioButton_4->isChecked() == true) {
        //set user class type receiver
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if (ui->radioButton_5->isChecked() == true) {
        //set user class type company
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
    if (ui->lineEdit_7->text().isEmpty() == true) {
        ui->label_4->setText("Enter missing details");
    }
    else if (ui->lineEdit_8->text().isEmpty() == true) {
        ui->label_4->setText("Enter missing details");
    }
    else if (ui->lineEdit_9->text().isEmpty() == true) {
        ui->label_4->setText("Enter missing details");
    }
    else {
        //create user according to user.type
        //destroy user
        //create actor
        //Encrypt
        //Pass all details to the db
        QMessageBox::information(this, "Registration", "Account was succesfully created");
        ui->stackedWidget->setCurrentIndex(0);
    }
}
//log in
void application::on_pushButton_2_clicked()
{
    //Decrypt
    //Check in DB user type
    //Open menu for user
    ui->stackedWidget->setCurrentIndex(4);
}
