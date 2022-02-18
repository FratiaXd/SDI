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

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(ColumnNames);
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
    ui->stackedWidget->setCurrentIndex(1);
}

void menu_company::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_company::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void menu_company::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_company::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void menu_company::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu_company::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    if (!cargo1.has_any_orders(usrnam_, "company")){
        ui->label_6->setText("You don't have any orders");
    }
        //Order history
    else {
        list<Cargo> d1 = cargo1.request_history(usrnam_, "company");
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
