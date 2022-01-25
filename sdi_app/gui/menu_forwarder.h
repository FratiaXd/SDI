#ifndef MENU_FORWARDER_H
#define MENU_FORWARDER_H

#include <QWidget>
#include "headers/forwarder.h"

namespace Ui {
class menu_forwarder;
}

class menu_forwarder : public QWidget
{
    Q_OBJECT

public:
    explicit menu_forwarder(QWidget *parent = nullptr);
    ~menu_forwarder();

private slots:

private:
    Ui::menu_forwarder *ui;
    Forwarder forw1;
};

#endif // MENU_FORWARDER_H
