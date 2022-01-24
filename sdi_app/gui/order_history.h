#ifndef ORDER_HISTORY_H
#define ORDER_HISTORY_H

#include <QDialog>

namespace Ui {
class order_history;
}

class order_history : public QDialog
{
    Q_OBJECT

public:
    explicit order_history(QWidget *parent = nullptr);
    ~order_history();

private:
    Ui::order_history *ui;
};

#endif // ORDER_HISTORY_H
