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

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(ColumnNames);
}

menu_forwarder::~menu_forwarder()
{
    delete ui;
}

void menu_forwarder::AddRoot(QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost) {
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
}

void menu_forwarder::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_forwarder::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void menu_forwarder::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_forwarder::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    if (!cargo1.has_any_orders(usnm_, "forwarder")){
        ui->label_5->setText("You don't have any orders");
    }
    //Order history
    else {
        list<Cargo> d1 = cargo1.request_history(usnm_, "forwarder");
        for (list<Cargo>::iterator i = d1.begin(); i != d1.end(); ++i) {
            AddRoot(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                    QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                    QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                    QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                    QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()));
        }
    }
}

void menu_forwarder::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget->clear();
    ui->label_5->clear();
}
