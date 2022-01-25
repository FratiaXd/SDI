#ifndef MENU_OWNER_H
#define MENU_OWNER_H

#include <QWidget>
#include "headers/cargo_owner.h"

namespace Ui {
class menu_owner;
}

class menu_owner : public QWidget
{
    Q_OBJECT

public:
    explicit menu_owner(QWidget *parent = nullptr);
    ~menu_owner();

private:
    Ui::menu_owner *ui;
    CargoOwner owner1;
};

#endif // MENU_OWNER_H
