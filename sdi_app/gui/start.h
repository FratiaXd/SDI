#ifndef START_H
#define START_H

#include <QDialog>
#include "user_type.h"
#include "menu_cargoown.h"
#include "menu_trcomp.h"
#include "menu_forwarder.h"
#include "menu_driver.h"
#include "menu_receiver.h"

namespace Ui {
class start;
}

class start : public QDialog
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = nullptr);
    ~start();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::start *ui;
};

#endif // START_H
