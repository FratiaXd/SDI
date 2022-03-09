#include "menu_forwarder.h"
#include "ui_menu_forwarder.h"

string usnm_;

menu_forwarder::menu_forwarder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_forwarder)
{
    ui->setupUi(this);

    QStringList ColumnNames;
    ColumnNames << "ID" << "Status";

    QStringList ColumnNames3;
    ColumnNames3 << "Company name" << "Email";

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(ColumnNames);

    ui->treeWidget_2->setColumnCount(2);
    ui->treeWidget_2->setHeaderLabels(ColumnNames);

    ui->treeWidget_3->setColumnCount(2);
    ui->treeWidget_3->setHeaderLabels(ColumnNames3);
}

menu_forwarder::~menu_forwarder()
{
    delete ui;
}

void menu_forwarder::AddRoot(QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost, QTreeWidget *widget) {
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

void menu_forwarder::AddRoot2(QString comName, QString comEmail, QString userName, QString phone, QString addrCom) {
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget_3);
    itm->setText(0, comName);
    itm->setText(1, comEmail);
    ui->treeWidget_3->addTopLevelItem(itm);

    AddChild(itm, "username", userName);
    AddChild(itm, "phone number", phone);
    AddChild(itm, "address", addrCom);
}

void menu_forwarder::AddChild(QTreeWidgetItem *parent, QString id, QString status) {
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0, id);
    itm->setText(1, status);
    parent->addChild(itm);
}

void menu_forwarder::receive_username_f(QString tx) {
    usnm_ = tx.toStdString();
    forw1.set_n(usnm_);
}

void menu_forwarder::on_pushButton_clicked()
{
    emit log_out();
}

void menu_forwarder::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    list<Cargo> f1 = cargo1.request_history("status", "Waiting for forwarder");
    for (list<Cargo>::iterator i = f1.begin(); i != f1.end(); ++i) {
        AddRoot(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()), ui->treeWidget_2);
    }

    //list 'waiting for forwarder'
}

void menu_forwarder::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_2->clear();
    //go back
}

void menu_forwarder::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    //lists companies on the market
    vector<TranspCompany> v1 = comp1.request_companies();
    for (vector<TranspCompany>::iterator k = v1.begin(); k != v1.end(); ++k) {
        AddRoot2(QString::fromStdString(k->get_fulln()), QString::fromStdString(k->get_email()),
                 QString::fromStdString(k->get_n()), QString::fromStdString(k->get_mobile()),
                 QString::fromStdString(k->get_address()));
    }
    //combobox lists cargos waiting for progress
    list<Cargo> h1 = cargo1.request_offers("status", "Accepted. Waiting for further actions", "forwarder", "forwarder", usnm_);
    for (list<Cargo>::iterator i = h1.begin(); i != h1.end(); ++i) {
        string cargoInfo = "ID - " + i->get_id() + "/" + i->get_source() + " - " + i->get_destination();
        ui->comboBox->addItem(QString::fromStdString(cargoInfo));
    }
    //list cargos and companies
    //combobox
    
}

void menu_forwarder::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox->clear();
    ui->treeWidget_3->clear();
    //go back
}

void menu_forwarder::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    if (!cargo1.has_any_orders(usnm_, "forwarder")){
        ui->label_5->setText("You don't have any orders");
    }
    //Order history
    else {
        list<Cargo> d1 = cargo1.request_history("forwarder", usnm_);
        for (list<Cargo>::iterator i = d1.begin(); i != d1.end(); ++i) {
            AddRoot(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                    QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                    QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                    QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                    QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()), ui->treeWidget);
        }
    }
}

void menu_forwarder::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget->clear();
    ui->label_5->clear();
}

void menu_forwarder::on_pushButton_6_clicked()
{
    try {
        list<Cargo> f2 = cargo1.request_history("status", "Waiting for forwarder");
        int cargoNum = ui->treeWidget_2->currentIndex().row();
        list<Cargo>::iterator it = f2.begin();
        advance(it, cargoNum);
        Cargo offerCargo = *it;
        offerCargo.assign_forwarder(usnm_);
        offerCargo.update_db_status("Waiting for owner", "forwarder", usnm_);
    }catch (...){
        cout << "An exception occured. No option selected." << endl;
    }
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget_2->clear();
    //add notification
    //make an offer
}

void menu_forwarder::on_pushButton_7_clicked()
{
    try {
        vector<TranspCompany> v1 = comp1.request_companies();
        int companyNum = ui->treeWidget_3->currentIndex().row();
        string companyName = v1[companyNum].get_n();
        string cargoId = ui->comboBox->currentText().toStdString();
        Cargo cargo2;
        cargo2.set_id(cargoId);
        cargo2.update_db_status("Waiting for company response", "company", companyName);
    }catch (...){
        cout << "An exception occured. No option selected." << endl;
    }
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox->clear();
    ui->treeWidget_3->clear();
    //send offer to transp com
    //add notification
}
