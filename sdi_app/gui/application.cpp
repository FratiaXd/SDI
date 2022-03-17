#include "application.h"
#include "ui_application.h"
#include <QMessageBox>
#include "headers/myudp.h"

application::application(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::application)
{
    ui->setupUi(this);
    //menu page objects
    ui->stackedWidget->addWidget(&dmenu);
    ui->stackedWidget->addWidget(&fmenu);
    ui->stackedWidget->addWidget(&omenu);
    ui->stackedWidget->addWidget(&cmenu);

    //signals application to log out the user and go back to the main screen
    connect(&dmenu, SIGNAL(log_out()), this, SLOT(logOutUser()));
    connect(&fmenu, SIGNAL(log_out()), this, SLOT(logOutUser()));
    connect(&omenu, SIGNAL(log_out()), this, SLOT(logOutUser()));
    connect(&cmenu, SIGNAL(log_out()), this, SLOT(logOutUser()));

    //passes username to other menu classes
    QObject::connect(this, SIGNAL(pass_username_o(QString)), &omenu, SLOT(receive_username_o(QString)));
    QObject::connect(this, SIGNAL(pass_username_c(QString)), &cmenu, SLOT(receive_username_c(QString)));
    QObject::connect(this, SIGNAL(pass_username_d(QString)), &dmenu, SLOT(receive_username_d(QString)));
    QObject::connect(this, SIGNAL(pass_username_f(QString)), &fmenu, SLOT(receive_username_f(QString)));

    //location list
    QStringList availableLocations;
    availableLocations << "Nottingham" << "Leeds" << "Liverpool" << "London" << "Manchester" << "Birmingham" << "Edinburgh";
    ui->comboBox->addItems(availableLocations);
    ui->comboBox_2->addItems(availableLocations);

    //Hides password
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_8->setEchoMode(QLineEdit::Password);

}

application::~application()
{
    delete ui;
}

//opens user sign up window
void application::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//opens account type window to allow user to choose his role
void application::on_pushButton_3_clicked()
{
    if (ui->radioButton->isChecked()) {
        user1.set_type("driver");
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if (ui->radioButton_2->isChecked()) {
        user1.set_type("forwarder");
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if (ui->radioButton_3->isChecked()) {
        user1.set_type("owner");
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if (ui->radioButton_5->isChecked()) {
        user1.set_type("company");
        ui->stackedWidget->setCurrentIndex(3);
    }
    //does not allow proceeding until radio button is checked
    else {
        ui->label_2->setText("Choose account type");
    }

}

//opens lorry registration page
void application::on_pushButton_4_clicked()
{
    //does not allow proceeding until each line has user input
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
        //has to be double (tbc)
        ui->label_5->setText("Enter missing details");
    }
    else if (ui->lineEdit_14->text().isEmpty()) {
        //has to be double (tbc)
        ui->label_5->setText("Enter missing details");
    }
    else if (ui->lineEdit_15->text().isEmpty()) {
        //has to be double (tbc)
        ui->label_5->setText("Enter missing details");
    }
    else if (ui->lineEdit_16->text().isEmpty()) {
        //has to be double (tbc)
        ui->label_5->setText("Enter missing details");
    }
    else if (ui->lineEdit_17->text().isEmpty()) {
        ui->label_5->setText("Enter missing details");
    }
    else {
        string niNumber = ui->lineEdit_3->text().toStdString();
        string licenseID = ui->lineEdit_4->text().toStdString();
        string cpcNumber = ui->lineEdit_5->text().toStdString();
        string regNumber = ui->lineEdit_6->text().toStdString(); //reg num
        string lorryType = ui->lineEdit_13->text().toStdString();
        string lorryWidth = ui->lineEdit_14->text().toStdString();
        string lorryHeight = ui->lineEdit_15->text().toStdString();
        string lorryLength = ui->lineEdit_16->text().toStdString();
        string lorryWeight = ui->lineEdit_17->text().toStdString(); //cpc
        string driverLocation = ui->comboBox->currentText().toStdString(); //current location
        //check cpc function (tbc)
        //check lorry reg number (tbc)
        //if both true
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_13->clear();
        ui->lineEdit_14->clear();
        ui->lineEdit_15->clear();
        ui->lineEdit_16->clear();
        ui->lineEdit_17->clear();
        //saves driver's lorry information for later use
        driv.driver_details(niNumber, licenseID, lorryType, regNumber, lorryHeight, lorryWidth, lorryLength, lorryWeight, cpcNumber, driverLocation);
        QMessageBox::information(this, "Lorry check", "Check success!");
        ui->stackedWidget->setCurrentIndex(3);
        //if false ask for details again and display message
    }
}

//opens registration page
void application::on_pushButton_5_clicked()
{
    //does not allow proceeding until each line has user input
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
        //creates the user according to user.type saved previously in account type window
        string userUsername = ui->lineEdit_7->text().toStdString();
        string userPassword = ui->lineEdit_8->text().toStdString();
        string userFullName = ui->lineEdit_9->text().toStdString();
        string userEmail = ui->lineEdit_10->text().toStdString();
        string userMobile = ui->lineEdit_11->text().toStdString();
        string userAddress = ui->comboBox_2->currentText().toStdString();
        if (user1.user_exists(userUsername)) {
            QMessageBox::critical(this, "Log in", "Username is already taken");
        }
        else {
            if (user1.get_type() == "driver") {
                driv.set_driver(userUsername, userPassword, userFullName, userEmail, userMobile, "driver", userAddress);
                driv.registration_driver();
                driv.~Driver();
            }
            else if (user1.get_type() == "forwarder") {
                Forwarder forw(userUsername, userPassword, userFullName, userEmail, userMobile, "forwarder", userAddress);
                forw.registration();
                forw.~Forwarder();
            }
            else if (user1.get_type() == "owner") {
                CargoOwner own(userUsername, userPassword, userFullName, userEmail, userMobile, "cargo owner", userAddress);
                own.registration();
                own.~CargoOwner();
            }
            else if (user1.get_type() == "company") {
                TranspCompany comp(userUsername, userPassword, userFullName, userEmail, userMobile, "transportation company", userAddress);
                comp.registration();

            }
            user1.~User();
            QMessageBox::information(this, "Registration", "Account was succesfully created");
            ui->stackedWidget->setCurrentIndex(0);
        }
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_10->clear();
        ui->lineEdit_11->clear();
    }
}
//opens menu according to the user type
void application::on_pushButton_2_clicked()
{
    if (ui->lineEdit->text().isEmpty()) {
        ui->label_6->setText("Enter missing details");
    }
    else if (ui->lineEdit_2->text().isEmpty()) {
        ui->label_6->setText("Enter missing details");
    }
    //does not allow proceeding until each line has user input
    else {
        string loginUsernm = ui->lineEdit->text().toStdString();
        string loginPassw = ui->lineEdit_2->text().toStdString();
        if (!user1.sign_in(loginUsernm, loginPassw)) {
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            QMessageBox::critical(this, "Log in", "Incorrect username/password");
        }
        else {
            QMessageBox::information(this, "Log in", "Welcome back!");
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            QString usernameToPass = QString::fromStdString(loginUsernm);
            int menuPage = user1.open_menu(loginUsernm);
            switch (menuPage) {
                case 4:
                    emit pass_username_d(usernameToPass);
                    break;
                case 5:
                    emit pass_username_f(usernameToPass);
                    break;
                case 6:
                    emit pass_username_o(usernameToPass);
                    break;
                case 7:
                    emit pass_username_c(usernameToPass);
                    break;
            }
            ui->stackedWidget->setCurrentIndex(menuPage);
        }
    }
}

//returns user back to start page
void application::logOutUser()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void application::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void application::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_13->clear();
    ui->lineEdit_14->clear();
    ui->lineEdit_15->clear();
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
}

void application::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
}
