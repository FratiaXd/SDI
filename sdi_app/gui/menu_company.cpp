#include "menu_company.h"
#include "ui_menu_company.h"

string usrnam_;

menu_company::menu_company(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_company)
{
    ui->setupUi(this);

    QStringList ColumnNames;
    ColumnNames << "ID" << "Status";

    QStringList ColumnNames2;
    ColumnNames2 << "ID" << "Status" << "Forwarder's username";

    QStringList ColumnNames3;
    ColumnNames3 << "Driver's name" << "Mobile" << "Current location";

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(ColumnNames);

    ui->treeWidget_2->setColumnCount(3);
    ui->treeWidget_2->setHeaderLabels(ColumnNames2);

    ui->treeWidget_3->setColumnCount(3);
    ui->treeWidget_3->setHeaderLabels(ColumnNames3);
}

menu_company::~menu_company()
{
    delete ui;
}

void menu_company::AddRoot(QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost) {
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

void menu_company::AddRoot2(QString id, QString status, QString actorID, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost, QTreeWidget *widget) {
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

void menu_company::AddRoot3(QString driName, QString driEmail, QString userName, QString phone, QString addrDri, QString driLocation) {
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget_3);
    itm->setText(0, driName);
    itm->setText(1, phone);
    itm->setText(2, driLocation);
    ui->treeWidget_3->addTopLevelItem(itm);

    AddChild(itm, "username", userName);
    AddChild(itm, "email", driEmail);
    AddChild(itm, "address", addrDri);
}

void menu_company::AddChild(QTreeWidgetItem *parent, QString id, QString status) {
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0, id);
    itm->setText(1, status);
    parent->addChild(itm);
}

void menu_company::on_pushButton_clicked()
{
    emit log_out();
}

void menu_company::receive_username_c(QString tx) {
    usrnam_ = tx.toStdString();
    comp1.set_n(usrnam_);
}

void menu_company::on_pushButton_2_clicked()
{
    ui->pushButton_11->setVisible(false);
    ui->pushButton_12->setVisible(false);
    ui->stackedWidget->setCurrentIndex(1);
    list<Cargo> o1 = cargo1.request_offers("status", "Waiting for company response", "forwarder", "company", usrnam_);
    for (list<Cargo>::iterator i = o1.begin(); i != o1.end(); ++i) {
        AddRoot2(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                 QString::fromStdString(i->get_forwarder()),
                 QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                 QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                 QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                 QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()), ui->treeWidget_2);
    }
    //offers from forwarders
}

void menu_company::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_2->clear();
    ui->label_7->setText("Comission: ");
    //go back
}

void menu_company::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->pushButton_13->setVisible(false);
    //find driver
    list<Cargo> h1 = cargo1.request_offers("status", "Company accepted. Waiting for driver", "forwarder", "company", usrnam_);
    for (list<Cargo>::iterator i = h1.begin(); i != h1.end(); ++i) {
        string cargoInfo = "ID - " + i->get_id() + "/" + i->get_source() + " - " + i->get_destination();
        ui->comboBox->addItem(QString::fromStdString(cargoInfo));
    }
}

void menu_company::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox->clear();
    ui->treeWidget_3->clear();
    //go back
}

void menu_company::on_pushButton_4_clicked()
{
    //find the closest drivers and put them into treewidget
    try {
        ui->treeWidget_3->clear();
        list<Cargo> h1 = cargo1.request_offers("status", "Company accepted. Waiting for driver", "forwarder", "company",
                                               usrnam_);
        int num = ui->comboBox->currentIndex();
        list<Cargo>::iterator it = h1.begin();
        advance(it, num);
        Cargo chosenCargo = *it;
        string cargoLocation = chosenCargo.get_source();
        vector<Driver> vecDrivers = driver1.request_drivers();
        vector<Driver> vecDriversSorted = driver1.sort_drivers(vecDrivers, cargoLocation);
        //NEED TO CHANGE TO VECDRIVERSSORTED WHEN SORT DRIVERS FUNCTION IS COMPLETED
        for (vector<Driver>::iterator k = vecDrivers.begin(); k != vecDrivers.end(); ++k) {
            AddRoot3(QString::fromStdString(k->get_fulln()), QString::fromStdString(k->get_email()),
                     QString::fromStdString(k->get_n()), QString::fromStdString(k->get_mobile()),
                     QString::fromStdString(k->get_address()), QString::fromStdString(k->get_location()));
        }
        ui->pushButton_13->setVisible(true);
    }catch (...){
        cout << "An exception occured. No option selected." << endl;
    }
}

void menu_company::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    if (!cargo1.has_any_orders(usrnam_, "company")){
        ui->label_6->setText("You don't have any orders");
    }
        //Order history
    else {
        list<Cargo> d1 = cargo1.request_history("company", usrnam_);
        for (list<Cargo>::iterator i = d1.begin(); i != d1.end(); ++i) {
            AddRoot(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                    QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                    QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                    QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                    QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()));
        }
    }
}

void menu_company::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget->clear();
    ui->label_6->clear();
}

void menu_company::on_pushButton_10_clicked()
{
    //calculate comission function
    try {
        list<Cargo> o1 = cargo1.request_offers("status", "Waiting for company response", "forwarder", "company",
                                               usrnam_);
        int cargoNum = ui->treeWidget_2->currentIndex().row();
        list<Cargo>::iterator it = o1.begin();
        advance(it, cargoNum);
        Cargo offerCargo = *it;
        //calculate comission function is in transpostation company class
        double commision = comp1.calculate_comission(atof(offerCargo.get_shippingCost().c_str()));
        QString qstr = QString::fromStdString((to_string(commision)));
        ui->label_7->setText("Comission: " + qstr);
        ui->pushButton_11->setVisible(true);
        ui->pushButton_12->setVisible(true);
    }catch (...){
        cout << "An exception occured. No option selected." << endl;
    }
}

void menu_company::on_pushButton_12_clicked()
{
    //decline offer
    try {
        list<Cargo> o1 = cargo1.request_offers("status", "Waiting for company response", "forwarder", "company",
                                               usrnam_);
        int cargoNum = ui->treeWidget_2->currentIndex().row();
        list<Cargo>::iterator it = o1.begin();
        advance(it, cargoNum);
        Cargo offerCargo = *it;
        offerCargo.assign_company("");
        offerCargo.update_db_status("Accepted. Waiting for further actions", "company", "");
    }catch (...){
        cout << "An exception occured. No option selected." << endl;
    }
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_2->clear();
}

void menu_company::on_pushButton_11_clicked()
{
    //accept offer
    try {
        list<Cargo> o1 = cargo1.request_offers("status", "Waiting for company response", "forwarder", "company",
                                               usrnam_);
        int cargoNum = ui->treeWidget_2->currentIndex().row();
        list<Cargo>::iterator it = o1.begin();
        advance(it, cargoNum);
        Cargo offerCargo = *it;
        //UPDATE FEE
        offerCargo.assign_company(usrnam_);
        offerCargo.update_db_status("Company accepted. Waiting for driver", "company", usrnam_);
    }catch (...){
        cout << "An exception occured. No option selected." << endl;
    }
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_2->clear();
}

void menu_company::on_pushButton_13_clicked()
{
    //send offer to driver
    try {
        list<Cargo> h1 = cargo1.request_offers("status", "Company accepted. Waiting for driver", "forwarder", "company",
                                               usrnam_);
        int num = ui->comboBox->currentIndex();
        list<Cargo>::iterator it = h1.begin();
        advance(it, num);
        Cargo chosenCargo = *it;
        string cargoLocation = chosenCargo.get_source();
        vector<Driver> vecDrivers = driver1.request_drivers();
        vector<Driver> vecDriversSorted = driver1.sort_drivers(vecDrivers, cargoLocation);
        //CHANGE TO VECDRIVERSSORTED WHEN FUNC IS DONE
        int driverNum = ui->treeWidget_3->currentIndex().row();
        string driverUsername = vecDrivers[driverNum].get_n();
        string cargoId = ui->comboBox->currentText().toStdString();
        Cargo cargo2;
        cargo2.set_id(cargoId);
        cargo2.update_db_status("Waiting for driver response", "driver", driverUsername);
        cout << "Status updated" << endl;
    }catch (...){
        cout << "An exception occured. No option selected." << endl;
    }
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox->clear();
    ui->treeWidget_3->clear();
}
