/** @file menu_receiver.h
 *  @brief Class representing GUI functionality for login/registration windows
 *
 *  @author Katrina Petreikyte (fratiaxd)
 */

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
    void on_pushButton_8_clicked();

private slots:
    void on_pushButton_7_clicked();

private slots:
    void on_pushButton_6_clicked();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void logOutUser();

private:
    Ui::application *ui;
    User user1;
    menu_driver dmenu;
    menu_forwarder fmenu;
    menu_owner omenu;
    menu_company cmenu;
    menu_receiver rmenu;
    Driver driv;

    signals:
    void pass_username_o(QString tx);
    void pass_username_r(QString tx);
    void pass_username_c(QString tx);
    void pass_username_f(QString tx);
    void pass_username_d(QString tx);
};

#endif // APPLICATION_H
