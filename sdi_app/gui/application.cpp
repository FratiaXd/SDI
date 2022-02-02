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
    if (ui->lineEdit_3->text().isEmpty()) {
        ui->label_5->setText("Enter missing details");
    }
    else if (ui->lineEdit_4->text().isEmpty()) {
        ui->label_5->setText("Enter missing details");
    }
    else if (ui->lineEdit_5->text().isEmpty()) {
        ui->label_5->setText("Enter missing details");
    }
    else if (ui->lineEdit_6->text().isEmpty()) {
        ui->label_5->setText("Enter missing details");
    }
    else if (ui->lineEdit_13->text().isEmpty()) {
        //has to be double
        ui->label_5->setText("Enter missing details");
    }
    else if (ui->lineEdit_14->text().isEmpty()) {
        //has to be double
        ui->label_5->setText("Enter missing details");
    }
    else if (ui->lineEdit_15->text().isEmpty()) {
        //has to be double
        ui->label_5->setText("Enter missing details");
    }
    else if (ui->lineEdit_16->text().isEmpty()) {
        //has to be double
        ui->label_5->setText("Enter missing details");
    }
    else if (ui->lineEdit_17->text().isEmpty()) {
        ui->label_5->setText("Enter missing details");
    }
    else {
        //check cpc function
        //check lorry reg number
        string g = ui->lineEdit_3->text().toStdString();;
        string h = ui->lineEdit_4->text().toStdString();;
        string i = ui->lineEdit_5->text().toStdString();;
        string j = ui->lineEdit_6->text().toStdString();;
        string k = ui->lineEdit_13->text().toStdString();;
        string l = ui->lineEdit_14->text().toStdString();;
        string m = ui->lineEdit_15->text().toStdString();;
        string o = ui->lineEdit_16->text().toStdString();;
        string p = ui->lineEdit_17->text().toStdString();;
        driv.driver_details(g, h, i, j, k, l, m, o, p);
        ui->stackedWidget->setCurrentIndex(3);
    }
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
        string f = ui->lineEdit_12->text().toStdString();
        if (user1.get_type() == "driver") {
            driv.set_driver(a, b, c, d, e, "driver", f);
            driv.registration_driver();
            //Encrypt function
        }
        else if (user1.get_type() == "forwarder") {
            Forwarder forw(a, b, c, d, e, "forwarder", f);
            forw.registration();
        }
        else if (user1.get_type() == "owner") {
            CargoOwner own(a, b, c, d, e, "cargo owner", f);
            own.registration();
        }
        else if (user1.get_type() == "receiver") {
            User receiv(a, b, c, d, e, "receiver", f);
            receiv.registration();
        }
        else if (user1.get_type() == "company") {
            TranspCompany comp(a, b, c, d, e, "transportation company", f);
            comp.registration();
        }
        //destroy user
        QMessageBox::information(this, "Registration", "Account was succesfully created");
        ui->stackedWidget->setCurrentIndex(0);
    }
}
//log in
void application::on_pushButton_2_clicked()
{
    if (ui->lineEdit->text().isEmpty()) {
        ui->label_6->setText("Enter missing details");
    }
    else if (ui->lineEdit_2->text().isEmpty()) {
        ui->label_6->setText("Enter missing details");
    }
    else {
        string nm = ui->lineEdit->text().toStdString();
        string pass = ui->lineEdit_2->text().toStdString();
        //Log in function in user :
        //Decrypt
        //Check in DB user type
        //Open menu for user
        ui->stackedWidget->setCurrentIndex(4);
    }
}


