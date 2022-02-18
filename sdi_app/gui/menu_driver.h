#ifndef MENU_DRIVER_H
#define MENU_DRIVER_H

#include <QWidget>
#include "headers/driver.h"
#include "iostream"

namespace Ui {
class menu_driver;
}

class menu_driver : public QWidget
{
    Q_OBJECT

public:
    explicit menu_driver(QWidget *parent = nullptr);
    ~menu_driver();

private slots:
    void on_pushButton_7_clicked();

private slots:
    void on_pushButton_2_clicked();

private slots:
    void on_pushButton_6_clicked();

private slots:
    void on_pushButton_4_clicked();

private slots:
    void on_pushButton_5_clicked();

private slots:
    void on_pushButton_clicked();

private slots:
    void on_pushButton_3_clicked();

    void receive_username_d(QString tx);

private:
    Ui::menu_driver *ui;
    Driver driv1;

signals:
    void log_out();
};

#endif // MENU_DRIVER_H
