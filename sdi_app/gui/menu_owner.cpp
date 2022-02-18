#include "menu_owner.h"
#include "ui_menu_owner.h"
#include "QMessageBox"

string username_;

menu_owner::menu_owner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_owner)
{
    ui->setupUi(this);

    QStringList ColumnNames;
    ColumnNames << "ID" << "Status";

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(ColumnNames);
}

menu_owner::~menu_owner()
{
    delete ui;
}

void menu_owner::AddRoot(QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost) {
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0, id);
    itm->setText(1, status);
    ui->treeWidget->addTopLevelItem(itm);

    AddChild(itm, "weight", wei);
    AddChild(itm, "height", hei);
    AddChild(itm, "width", wid);
    AddChild(itm, "length", len);
    AddChild(itm, "type", typ);
    AddChild(itm, "source", src);
    AddChild(itm, "destination", dest);
    AddChild(itm, "shipping cost", cost);
}
void menu_owner::AddChild(QTreeWidgetItem *parent, QString id, QString status) {
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0, id);
    itm->setText(1, status);
    parent->addChild(itm);
}

void menu_owner::on_pushButton_clicked()
{
    emit log_out();
}

void menu_owner::receive_username_o(QString tx) {
    username_ = tx.toStdString();
    owner1.set_n(username_);
}

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
    cargo1.assign_owner(username_);
    cargo1.savetoDB();
    QMessageBox::information(this, "Order", "Your order was successful! Order has been added to 'My orders' list.");
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
}

void menu_owner::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    //Forwarder offers
}

void menu_owner::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    //Go back from forwarder offers
}

void menu_owner::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    //check if user has any orders
    if (!cargo1.has_any_orders(username_, "owner")){
        ui->label_6->setText("You don't have any orders");
    }
    //Order history
    else {
        list<Cargo> d1 = cargo1.request_history(username_, "owner");
        for (list<Cargo>::iterator i = d1.begin(); i != d1.end(); ++i) {
            AddRoot(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                    QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                    QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                    QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                    QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()));
        }
    }
}

void menu_owner::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget->clear();
    //Go back from history
}
