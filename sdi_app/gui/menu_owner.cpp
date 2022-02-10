#include "menu_owner.h"
#include "ui_menu_owner.h"

menu_owner::menu_owner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_owner)
{
    ui->setupUi(this);

}

menu_owner::~menu_owner()
{
    delete ui;
}

void menu_owner::on_pushButton_clicked()
{
    emit log_out();
}

//void menu_owner::receive_username(std::string a) {
    //owner1.set_n(a);
//}

void menu_owner::on_pushButton_2_clicked()
{
    ui->pushButton_6->setVisible(false);
    ui->stackedWidget->setCurrentIndex(1);
}

void menu_owner::on_pushButton_7_clicked()
{
    //details will be lost message
    ui->stackedWidget->setCurrentIndex(0);
    if (cargo1.cargo_exists()){
        cargo1.~Cargo();
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->label_2->setText("Price");
}

void menu_owner::on_pushButton_5_clicked()
{
    if (ui->lineEdit->text().isEmpty()) {
        ui->label_2->setText("Enter missing details");
    }
    else if (ui->lineEdit_2->text().isEmpty()) {
        ui->label_2->setText("Enter missing details");
    }
    else if (ui->lineEdit_3->text().isEmpty()) {
        ui->label_2->setText("Enter missing details");
    }
    else if (ui->lineEdit_4->text().isEmpty()) {
        ui->label_2->setText("Enter missing details");
    }
    else if (ui->lineEdit_5->text().isEmpty()) {
        ui->label_2->setText("Enter missing details");
    }
    else if (ui->lineEdit_6->text().isEmpty()) {
        ui->label_2->setText("Enter missing details");
    }
    else if (ui->lineEdit_7->text().isEmpty()) {
        ui->label_2->setText("Enter missing details");
    }
    else {
        string wei = ui->lineEdit->text().toStdString();
        string hei = ui->lineEdit_2->text().toStdString();
        string wid = ui->lineEdit_3->text().toStdString();
        string len = ui->lineEdit_4->text().toStdString();
        string typ = ui->lineEdit_5->text().toStdString();
        string sour = ui->lineEdit_6->text().toStdString();
        string dest = ui->lineEdit_7->text().toStdString();
        //check values to be int
        float wei_fl = stof(wei);
        float hei_fl = stof(hei);
        float wid_fl = stof(wid);
        float len_fl = stof(len);
        float pr = owner1.calculate_shipping(wei_fl, hei_fl, len_fl, wid_fl, sour, dest);
        string disp_pr = to_string(pr);
        QString qstr = QString::fromStdString(disp_pr);
        ui->label_2->setText("Final shipping price: " + qstr);
        ui->pushButton_6->setVisible(true);
        cargo1.set_primary_values(wei, hei, wid, len, typ, sour, dest, disp_pr);
    }
}

void menu_owner::on_pushButton_6_clicked()
{
    string cID = cargo1.generate_id();
    cargo1.update_status("Waiting for forwarder");
    //string d = owner1.get_n();
    //cout << d;
    //cargo1.assign_owner();
    //pass to db and encrypt
}

void menu_owner::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void menu_owner::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_owner::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void menu_owner::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
