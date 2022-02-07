#ifndef MENU_DRIVER_H
#define MENU_DRIVER_H

#include <QWidget>
#include "headers/driver.h"

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
    void on_pushButton_3_clicked();

private:
    Ui::menu_driver *ui;
    Driver driv1;

signals:
    void log_out();
};

#endif // MENU_DRIVER_H
