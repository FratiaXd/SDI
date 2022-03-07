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

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(ColumnNames);

    ui->treeWidget_2->setColumnCount(3);
    ui->treeWidget_2->setHeaderLabels(ColumnNames2);
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
    //find driver
}

void menu_company::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    //go back
}

void menu_company::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
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
    list<Cargo> o1 = cargo1.request_offers("status", "Waiting for company response", "forwarder", "company", usrnam_);
    int cargoNum = ui->treeWidget_2->currentIndex().row();
    list<Cargo>::iterator it = o1.begin();
    advance(it, cargoNum);
    Cargo offerCargo = *it;
    double commision = comp1.calculate_comission(atof(offerCargo.get_shippingCost().c_str()));
    QString qstr = QString::fromStdString((to_string(commision)));
    ui->label_7->setText("Comission: " + qstr);
    ui->pushButton_11->setVisible(true);
    ui->pushButton_12->setVisible(true);
}

void menu_company::on_pushButton_12_clicked()
{
    //decline offer
}

void menu_company::on_pushButton_11_clicked()
{
    //accept offer
}
