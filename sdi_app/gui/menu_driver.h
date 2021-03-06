/** @file menu_driver.h
 *  @brief Class representing GUI functionality for driver
 *
 *  @author Katrina Petreikyte (fratiaxd)
 */

#ifndef MENU_DRIVER_H
#define MENU_DRIVER_H

#include <QWidget>
#include "headers/driver.h"
#include "headers/cargo.h"
#include "iostream"
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QTcpSocket>

namespace Ui {
class menu_driver;
}

class menu_driver : public QWidget
{
    Q_OBJECT

    void AddRoot (QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost);
    void AddRoot2(QString id, QString status, QString actorID, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost, QTreeWidget *widget);
    void AddChild(QTreeWidgetItem *parent, QString id, QString status);

public:
    explicit menu_driver(QWidget *parent = nullptr);
    ~menu_driver();
public slots:
    void onpbSend(QString t);
private slots:
    void on_pushButton_10_clicked();

private slots:
    void on_pushButton_9_clicked();

private slots:
    void on_pushButton_8_clicked();

private slots:
    void on_pushButton_7_clicked();

private slots:
    void on_pushButton_2_clicked();

private slots:
    void on_pushButton_6_clicked();

private slots:
    void on_pushButton_4_clicked();

private slots:
    void on_pushButton_5_clicked();

private slots:
    void on_pushButton_clicked();

private slots:
    void on_pushButton_3_clicked();

    void receive_username_d(QString tx);
    void clientConnected();

    void onConnected();
    void onDisconnected();
private:
    Ui::menu_driver *ui;
    Driver driv1;
    Cargo cargo1;
    QTcpSocket* socket;

signals:
    void log_out();
};

#endif // MENU_DRIVER_H
