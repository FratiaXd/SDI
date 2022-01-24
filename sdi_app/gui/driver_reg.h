#ifndef DRIVER_REG_H
#define DRIVER_REG_H

#include <QDialog>
#include "registration.h"

namespace Ui {
class driver_reg;
}

class driver_reg : public QDialog
{
    Q_OBJECT

public:
    explicit driver_reg(QWidget *parent = nullptr);
    ~driver_reg();

private slots:
    void on_pushButton_clicked();

private:
    Ui::driver_reg *ui;
};

#endif // DRIVER_REG_H
