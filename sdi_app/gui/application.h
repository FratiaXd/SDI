#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include "menu_driver.h"
#include "menu_forwarder.h"
#include "menu_company.h"
#include "menu_owner.h"
#include "menu_receiver.h"

namespace Ui {
class application;
}

class application : public QWidget
{
    Q_OBJECT

public:
    explicit application(QWidget *parent = nullptr);
    ~application();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::application *ui;
    menu_driver dmenu;
    menu_forwarder fmenu;
    menu_owner omenu;
    menu_company cmenu;
    menu_receiver rmenu;
    User user1;
};

#endif // APPLICATION_H