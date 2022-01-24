#ifndef MENU_FORWARDER_H
#define MENU_FORWARDER_H

#include <QDialog>
#include "order_history.h"

namespace Ui {
class menu_forwarder;
}

class menu_forwarder : public QDialog
{
    Q_OBJECT

public:
    explicit menu_forwarder(QWidget *parent = nullptr);
    ~menu_forwarder();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::menu_forwarder *ui;
};

#endif // MENU_FORWARDER_H
