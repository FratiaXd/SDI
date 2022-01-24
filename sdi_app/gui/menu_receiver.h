#ifndef MENU_RECEIVER_H
#define MENU_RECEIVER_H

#include <QDialog>

namespace Ui {
class menu_receiver;
}

class menu_receiver : public QDialog
{
    Q_OBJECT

public:
    explicit menu_receiver(QWidget *parent = nullptr);
    ~menu_receiver();

private:
    Ui::menu_receiver *ui;
};

#endif // MENU_RECEIVER_H
