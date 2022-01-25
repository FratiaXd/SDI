#ifndef MENU_RECEIVER_H
#define MENU_RECEIVER_H

#include <QWidget>
#include "headers/user.h"

namespace Ui {
class menu_receiver;
}

class menu_receiver : public QWidget
{
    Q_OBJECT

public:
    explicit menu_receiver(QWidget *parent = nullptr);
    ~menu_receiver();

private:
    Ui::menu_receiver *ui;
    User user1;
};

#endif // MENU_RECEIVER_H
