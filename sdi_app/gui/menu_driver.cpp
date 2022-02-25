#include "menu_driver.h"
#include "ui_menu_driver.h"

string ussnm_;

menu_driver::menu_driver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_driver)
{
    ui->setupUi(this);

    //sets up tree widget for displaying or history
    QStringList ColumnNames;
    ColumnNames << "ID" << "Status";

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(ColumnNames);
}

menu_driver::~menu_driver()
{
    delete ui;
}

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

void menu_driver::receive_username_d(QString tx) {
    ussnm_ = tx.toStdString();
    driv1.set_n(ussnm_);
}

void menu_driver::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void menu_driver::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_driver::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void menu_driver::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_driver::on_pushButton_2_clicked()
{
    //if user doesn't have any orders
    ui->stackedWidget->setCurrentIndex(3);
    if (!cargo1.has_any_orders(ussnm_, "driver")){
        ui->label_5->setText("You don't have any orders");
    }
    //Order history
    else {
        list<Cargo> d1 = cargo1.request_history(ussnm_, "driver");
        for (list<Cargo>::iterator i = d1.begin(); i != d1.end(); ++i) {
            AddRoot(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                    QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                    QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                    QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                    QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()));
        }
    }
}

void menu_driver::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget->clear();
    ui->label_5->clear();
}
