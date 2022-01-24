#include "order_history.h"
#include "ui_order_history.h"

order_history::order_history(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::order_history)
{
    ui->setupUi(this);
}

order_history::~order_history()
{
    delete ui;
}

//Order history function
