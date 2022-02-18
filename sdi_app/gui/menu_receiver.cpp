#include "menu_receiver.h"
#include "ui_menu_receiver.h"

string usrname_;

menu_receiver::menu_receiver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_receiver)
{
    ui->setupUi(this);

    QStringList ColumnNames;
    ColumnNames << "ID" << "Status";

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(ColumnNames);
}

menu_receiver::~menu_receiver()
{
    delete ui;
}

void menu_receiver::AddRoot(QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost) {
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
void menu_receiver::AddChild(QTreeWidgetItem *parent, QString id, QString status) {
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0, id);
    itm->setText(1, status);
    parent->addChild(itm);
}

void menu_receiver::receive_username_r(QString tx)  {
    usrname_ = tx.toStdString();
    user1.set_n(usrname_);
}

void menu_receiver::on_pushButton_clicked()
{
    emit log_out();
}

void menu_receiver::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    if (!cargo1.has_any_orders(usrname_, "receiver")){
        ui->label_3->setText("You don't have any orders");
    }
        //Order history
    else {
        list<Cargo> d1 = cargo1.request_history(usrname_, "receiver");
        for (list<Cargo>::iterator i = d1.begin(); i != d1.end(); ++i) {
            AddRoot(QString::fromStdString(i->get_id()), QString::fromStdString(i->get_status()),
                    QString::fromStdString(i->get_weight()), QString::fromStdString(i->get_height()),
                    QString::fromStdString(i->get_width()), QString::fromStdString(i->get_length()),
                    QString::fromStdString(i->get_type()), QString::fromStdString(i->get_source()),
                    QString::fromStdString(i->get_destination()), QString::fromStdString(i->get_shippingCost()));
        }
    }
}

void menu_receiver::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidget->clear();
    ui->label_3->clear();
}
