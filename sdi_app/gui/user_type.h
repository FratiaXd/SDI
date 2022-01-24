#ifndef USER_TYPE_H
#define USER_TYPE_H

#include <QDialog>
#include "registration.h"
#include "driver_reg.h"

namespace Ui {
class user_type;
}

class user_type : public QDialog
{
    Q_OBJECT

public:
    explicit user_type(QWidget *parent = nullptr);
    ~user_type();

private slots:
    void on_pushButton_clicked();

private:
    Ui::user_type *ui;
};

#endif // USER_TYPE_H
