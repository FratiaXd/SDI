#include "menu_driver.h"
#include "ui_menu_driver.h"

string ussnm_;

menu_driver::menu_driver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_driver)
{
    ui->setupUi(this);

    driv1.set_n(ussnm_);

    //sets up tree widget for displaying or history
    QStringList ColumnNames;
    ColumnNames << "ID" << "Status";

    QStringList ColumnNames2;
    ColumnNames2 << "ID" << "Status" << "Company name";

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(ColumnNames);

    ui->treeWidget_2->setColumnCount(3);
    ui->treeWidget_2->setHeaderLabels(ColumnNames2);

    ui->treeWidget_3->setColumnCount(3);
    ui->treeWidget_3->setHeaderLabels(ColumnNames2);

    QStringList availableLocations;
    availableLocations << "Nottingham" << "Leeds" << "Liverpool" << "London" << "Manchester" << "Birmingham" << "Edinburgh";
    ui->comboBox->addItems(availableLocations);

    //driver's location
    string location = driv1.request_locationDB();
    ui->label_8->setText(QString::fromStdString(location));
}

menu_driver::~menu_driver()
{
    delete ui;
}
//builds tree view (gui) with list of orders
void menu_driver::AddRoot(QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost) {
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
//builds tree view (gui) with list of orders version 2
void menu_driver::AddRoot2(QString id, QString status, QString actorID, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost, QTreeWidget *widget) {
    QTreeWidgetItem *itm = new QTreeWidgetItem(widget);
    itm->setText(0, id);
    itm->setText(1, status);
    itm->setText(2, actorID);
    widget->addTopLevelItem(itm);

    AddChild(itm, "weight", wei);
    AddChild(itm, "height", hei);
    AddChild(itm, "width", wid);
    AddChild(itm, "length", len);
    AddChild(itm, "type", typ);
    AddChild(itm, "source", src);
    AddChild(itm, "destination", dest);
    AddChild(itm, "shipping cost", cost);
}
//builds tree view subcategories (gui) with list of orders
void menu_driver::AddChild(QTreeWidgetItem *parent, QString id, QString status) {
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0, id);
    itm->setText(1, status);
    parent->addChild(itm);
}
//returns user to log in page
void menu_driver::on_pushButton_3_clicked()
{
    emit log_out();
}
//receives current user username from application
void menu_driver::receive_username_d(QString tx) {
    ussnm_ = tx.toStdString();
    driv1.set_n(ussnm_);
}
//lists all offers from transportation company
void menu_driver::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    list<Cargo> o1 = cargo1.request_offers("status", "Waiting for driver response", "company", "driver", ussnm_);
    for (list<Cargo>::iterator i = o1.begin(); i != o1.end(); ++i) {
        AddRoot2(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                 QString::fromStdString(i->get_company()),
                 QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                 QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                 QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                 QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()), ui->treeWidget_2);
    }
}
//goes back to the main menu
void menu_driver::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_2->clear();
    string location = driv1.request_locationDB();
    ui->label_8->setText(QString::fromStdString(location));
}
//opens delivery page
void menu_driver::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    list<Cargo> o1 = cargo1.request_offers("status", "Driver is on the way", "company", "driver", ussnm_);
    for (list<Cargo>::iterator i = o1.begin(); i != o1.end(); ++i) {
        AddRoot2(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                 QString::fromStdString(i->get_company()),
                 QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                 QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                 QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                 QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()), ui->treeWidget_3);
    }
}
//goes back to the main menu
void menu_driver::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_3->clear();
    string location = driv1.request_locationDB();
    ui->label_8->setText(QString::fromStdString(location));
}
//opens order history page
void menu_driver::on_pushButton_2_clicked()
{
    //if user doesn't have any orders
    ui->stackedWidget->setCurrentIndex(3);
    if (!cargo1.has_any_orders(ussnm_, "driver")){
        ui->label_5->setText("You don't have any orders");
    }
    //Order history
    else {
        list<Cargo> d1 = cargo1.request_history("driver", ussnm_);
        for (list<Cargo>::iterator i = d1.begin(); i != d1.end(); ++i) {
            AddRoot(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                    QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                    QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                    QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                    QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()));
        }
    }
}
//goes back to the main menu
void menu_driver::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget->clear();
    ui->label_5->clear();
    string location = driv1.request_locationDB();
    ui->label_8->setText(QString::fromStdString(location));
}
//declines offer from transp company
void menu_driver::on_pushButton_8_clicked()
{
    try {
        list<Cargo> o1 = cargo1.request_offers("status", "Waiting for driver response", "company", "driver", ussnm_);
        int cargoNum = ui->treeWidget_2->currentIndex().row();
        list<Cargo>::iterator it = o1.begin();
        advance(it, cargoNum);
        Cargo offerCargo = *it;
        offerCargo.assign_driver("");
        offerCargo.update_db_status("Company accepted. Waiting for driver", "driver", "");
        QMessageBox::information(this, "Offer", "You successfully declined an offer");
    }catch (...){
        cout << "An exception occured. No option selected." << endl;
    }
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_2->clear();
}
//accepts offer from transp company
void menu_driver::on_pushButton_9_clicked()
{
    try {
        list<Cargo> o1 = cargo1.request_offers("status", "Waiting for driver response", "company", "driver", ussnm_);
        int cargoNum = ui->treeWidget_2->currentIndex().row();
        list<Cargo>::iterator it = o1.begin();
        advance(it, cargoNum);
        Cargo offerCargo = *it;
        offerCargo.update_db_status("Driver is on the way", "driver", ussnm_);
        QMessageBox::information(this, "Offer", "You successfully accepted an offer");
    }catch (...){
        cout << "An exception occured. No option selected." << endl;
    }
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_2->clear();
}
//confirms successfull delivery
void menu_driver::on_pushButton_10_clicked()
{
    try {
        list<Cargo> o1 = cargo1.request_offers("status", "Driver is on the way", "company", "driver", ussnm_);
        int cargoNum = ui->treeWidget_3->currentIndex().row();
        list<Cargo>::iterator it = o1.begin();
        advance(it, cargoNum);
        Cargo offerCargo = *it;
        string finalDest = offerCargo.get_destination();
        string driverLocation = ui->comboBox->currentText().toStdString();
        if (finalDest == driverLocation) {
            offerCargo.update_db_status("Delivered", "receiver", "success");
            driv1.update_position(driverLocation);
            driv1.update_positionDB();
            QMessageBox::information(this, "Confirmation", "Cargo delivered. Your location updated");
        }
        else {
            QMessageBox::critical(this, "Delivery", "Your location doesn't match with order delivery address");
        }
    }catch (...){
        cout << "An exception occured. No option selected." << endl;
    }
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_3->clear();
}
