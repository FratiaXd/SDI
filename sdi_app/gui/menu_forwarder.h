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
    void on_pushButton_12_clicked();

private slots:
    void on_pushButton_3_clicked();

private slots:
    void on_pushButton_11_clicked();

private slots:
    void on_pushButton_4_clicked();

private slots:
    void on_pushButton_5_clicked();

private slots:
    void on_pushButton_2_clicked();

private slots:
    void on_pushButton_clicked();

private:
    Ui::menu_forwarder *ui;
    Forwarder forw1;

signals:
    void log_out();
};

#endif // MENU_FORWARDER_H
