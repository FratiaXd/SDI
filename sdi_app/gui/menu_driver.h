#ifndef MENU_DRIVER_H
#define MENU_DRIVER_H

#include <QDialog>

namespace Ui {
class menu_driver;
}

class menu_driver : public QDialog
{
    Q_OBJECT

public:
    explicit menu_driver(QWidget *parent = nullptr);
    ~menu_driver();

private:
    Ui::menu_driver *ui;
};

#endif // MENU_DRIVER_H
