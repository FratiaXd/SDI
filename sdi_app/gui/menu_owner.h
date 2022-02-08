#ifndef MENU_OWNER_H
#define MENU_OWNER_H

#include <QWidget>
#include "headers/cargo_owner.h"
#include "headers/cargo.h"

namespace Ui {
class menu_owner;
}

class menu_owner : public QWidget
{
    Q_OBJECT

public:
    explicit menu_owner(QWidget *parent = nullptr);
    ~menu_owner();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::menu_owner *ui;
    CargoOwner owner1;
    Cargo cargo1;

signals:
    void log_out();
};

#endif // MENU_OWNER_H
