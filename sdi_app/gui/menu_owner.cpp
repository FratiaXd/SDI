#include "menu_owner.h"
#include "ui_menu_owner.h"
#include "QMessageBox"
#include <QListWidgetItem>

string username_;
QString serverName = "localhost";

menu_owner::menu_owner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_owner)
{
    ui->setupUi(this);

    ui->label_6->setVisible(false);

    QStringList ColumnNames;
    ColumnNames << "ID" << "Status";

    QStringList ColumnNames2;
    ColumnNames2 << "ID" << "Status" << "Forwarder's username";

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(ColumnNames);

    ui->treeWidget_2->setColumnCount(3);
    ui->treeWidget_2->setHeaderLabels(ColumnNames2);

    //location list
    QStringList availableLocations;
    availableLocations << "Nottingham" << "Leeds" << "Liverpool" << "London" << "Manchester" << "Birmingham" << "Edinburgh";
    ui->comboBox->addItems(availableLocations);
    ui->comboBox_2->addItems(availableLocations);

    //cargo types list
    QStringList cargoTypes;
    cargoTypes << "Small box" << "Medium box" << "Large box" << "Fragile";
    ui->comboBox_3->addItems(cargoTypes);

    //validate input
    QRegExp cargoReg("^[+-]?([0-9]*[.])?[0-9]+$");
    ui->lineEdit->setValidator(new QRegExpValidator(cargoReg, this));
    ui->lineEdit_2->setValidator(new QRegExpValidator(cargoReg, this));
    ui->lineEdit_3->setValidator(new QRegExpValidator(cargoReg, this));
    ui->lineEdit_4->setValidator(new QRegExpValidator(cargoReg, this));

    //server connection
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    //connect(ui->lineEdit_5, SIGNAL(returnPressed()), this, SLOT(onpbSend(QString)));
}

menu_owner::~menu_owner()
{
    delete ui;
}

void menu_owner::clientConnected()
{
    socket->connectToHost(serverName, 1234);
}

void menu_owner::onpbSend(QString t) {
    //QString message = ui->lineEdit_5->text().trimmed();
    if (!t.isEmpty()) {
        socket->write(QString("/say:" + t + "\n").toUtf8());
    }
}

void menu_owner::onReadyRead() {
    QRegExp systemRex("^/system:(.*)$");
    QRegExp messageRex("^(.*):(.*)$");
    while (socket->canReadLine()) {
        QString line = QString::fromUtf8(socket->readLine()).trimmed();
        if (systemRex.indexIn(line) != -1) {
            QString msg = systemRex.cap(1);
            ui->label_14->setText(msg);
        }
            // Если сообщение - от пользователя
        else if (messageRex.indexIn(line) != -1) {
            QString user = messageRex.cap(1);
            QString message = messageRex.cap(2);
            ui->label_14->setText(user + "   " + message);
        }
    }
}

void menu_owner::onConnected() {
    ui->label_14->clear();
    socket->write(QString("/login:" + QString::fromStdString(username_) + "\n").toUtf8());
}

void menu_owner::onDisconnected() {
    QMessageBox::warning(NULL, "Warning",
                         "You have been disconnected from the server", QMessageBox::Ok);
}

//builds tree view (gui) with list of orders
void menu_owner::AddRoot(QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost, QTreeWidget *widget) {
    QTreeWidgetItem *itm = new QTreeWidgetItem(widget);
    itm->setText(0, id);
    itm->setText(1, status);
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
void menu_owner::AddChild(QTreeWidgetItem *parent, QString id, QString status) {
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0, id);
    itm->setText(1, status);
    parent->addChild(itm);
}
//builds tree view (gui) with list of offers version 2
void menu_owner::AddRoot2(QString id, QString status, QString actorID, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost, QTreeWidget *widget) {
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

void menu_owner::on_pushButton_clicked()
{
    emit log_out();
}
//receives current user username from application
void menu_owner::receive_username_o(QString tx) {
    username_ = tx.toStdString();
    owner1.set_n(username_);
}
//hides button make order until price is calculated
void menu_owner::on_pushButton_2_clicked()
{
    ui->pushButton_6->setVisible(false);
    ui->stackedWidget->setCurrentIndex(1);
}
//go back from order page
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
    ui->label_2->setText("Price");
}
//making order
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
    else {
        string cargoWeight = ui->lineEdit->text().toStdString(); //float
        string cargoHeight = ui->lineEdit_2->text().toStdString(); //float
        string cargoWidth = ui->lineEdit_3->text().toStdString(); //float
        string cargoLength = ui->lineEdit_4->text().toStdString(); //float
        string cargoType = ui->comboBox_3->currentText().toStdString();
        string cargoSource = ui->comboBox->currentText().toStdString();
        string cargoDestination = ui->comboBox_2->currentText().toStdString();
        if (cargoSource == cargoDestination) {
            ui->label_2->setText("Source and destination have to be different");
        }
        else{
            //check values to be float
            float weightFloat = stof(cargoWeight);
            float heightFloat = stof(cargoHeight);
            float widthFloat = stof(cargoWidth);
            float lengthFloat = stof(cargoLength);
            //calculate shipping function
            float pr = owner1.calculate_shipping(weightFloat, heightFloat, lengthFloat, widthFloat, cargoSource, cargoDestination);
            string disp_pr = to_string(pr);
            QString qstr = QString::fromStdString(disp_pr);
            ui->label_2->setText("Final shipping price: " + qstr);
            ui->pushButton_6->setVisible(true);
            cargo1.set_primary_values(cargoWeight, cargoHeight, cargoWidth, cargoLength, cargoType, cargoSource, cargoDestination, disp_pr);
        }
    }
}
//button make order
//updates database and order
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
    onpbSend(QString::fromStdString(username_) + " made an order");
}
//display forwarder offers
void menu_owner::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    //need to add if similar to order history if there is no offers
    list<Cargo> offerList = cargo1.request_offers("status", "Waiting for owner", "forwarder", "owner", username_);
    for (list<Cargo>::iterator i = offerList.begin(); i != offerList.end(); ++i) {
        AddRoot2(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                 QString::fromStdString(i->get_forwarder()),
                QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()), ui->treeWidget_2);
    }
}
//Go back from forwarder offers
void menu_owner::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_2->clear();
}
//display order history
void menu_owner::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    //check if user has any orders
    if (!cargo1.has_any_orders(username_, "owner")){
        ui->label_6->setVisible(true);
        ui->label_6->setText("You don't have any orders");
    }
    //Order history
    else {
        list<Cargo> historyList = cargo1.request_history("owner", username_);
        for (list<Cargo>::iterator i = historyList.begin(); i != historyList.end(); ++i) {
            AddRoot(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                    QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                    QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                    QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                    QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()), ui->treeWidget);
        }
    }
}
//Go back from history
void menu_owner::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget->clear();
    ui->label_6->clear();
}
//decline forwarders offer
void menu_owner::on_pushButton_10_clicked()
{
    try {
        list<Cargo> offerList = cargo1.request_offers("status", "Waiting for owner", "forwarder", "owner", username_);
        int cargoNum = ui->treeWidget_2->currentIndex().row();
        list<Cargo>::iterator it = offerList.begin();
        advance(it, cargoNum);
        Cargo offerCargo = *it;
        offerCargo.assign_forwarder("");
        offerCargo.update_db_status("Waiting for forwarder", "forwarder", "");
        QMessageBox::information(this, "Offer", "You successfully declined offer");
    } catch (...){
        cout << "An exception occured. No option selected." << endl;
    }
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_2->clear();
}
//accept forwarders offer
void menu_owner::on_pushButton_11_clicked()
{
    try {
        list<Cargo> d1 = cargo1.request_offers("status", "Waiting for owner", "forwarder", "owner", username_);
        int cargoNum = ui->treeWidget_2->currentIndex().row();
        list<Cargo>::iterator it = d1.begin();
        advance(it, cargoNum);
        Cargo offerCargo = *it;
        offerCargo.update_db_status("Accepted. Waiting for further actions", "owner", username_);
        QMessageBox::information(this, "Offer", "You successfully accepted offer");
    }catch (...){
        cout << "An exception occured. No option selected." << endl;
    }
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_2->clear();
    //accept
}