#ifndef MENU_CARGOOWN_H
#define MENU_CARGOOWN_H

#include <QDialog>

namespace Ui {
class menu_cargoown;
}

class menu_cargoown : public QDialog
{
    Q_OBJECT

public:
    explicit menu_cargoown(QWidget *parent = nullptr);
    ~menu_cargoown();

private:
    Ui::menu_cargoown *ui;
};

#endif // MENU_CARGOOWN_H
