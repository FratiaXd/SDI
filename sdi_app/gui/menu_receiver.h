#ifndef MENU_RECEIVER_H
#define MENU_RECEIVER_H

#include <QWidget>
#include "headers/user.h"
#include "headers/cargo.h"
#include "iostream"
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>

namespace Ui {
class menu_receiver;
}

class menu_receiver : public QWidget
{
    Q_OBJECT

    void AddRoot (QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost);
    void AddChild(QTreeWidgetItem *parent, QString id, QString status);

public:
    explicit menu_receiver(QWidget *parent = nullptr);
    ~menu_receiver();

private slots:
    void on_pushButton_3_clicked();

private slots:
    void on_pushButton_2_clicked();

private slots:
    void on_pushButton_clicked();

    void receive_username_r(QString tx);

private:
    Ui::menu_receiver *ui;
    User user1;
    Cargo cargo1;

signals:
    void log_out();
};

#endif // MENU_RECEIVER_H
