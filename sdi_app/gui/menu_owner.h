/** @file menu_owner.h
 *  @brief Class representing GUI functionality for cargo owner
 *
 *  @author Katrina Petreikyte (fratiaxd)
 */

#ifndef MENU_OWNER_H
#define MENU_OWNER_H

#include <QWidget>
#include "headers/cargo_owner.h"
#include "headers/cargo.h"
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>

#include <QMainWindow>
#include <QTcpSocket>
#include <QRegExpValidator>

namespace Ui {
class menu_owner;
}

class menu_owner : public QWidget
{
    Q_OBJECT

    void AddRoot (QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost, QTreeWidget *widget);
    void AddChild(QTreeWidgetItem *parent, QString id, QString status);
    void AddRoot2(QString id, QString status, QString actorID, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost, QTreeWidget *widget);

public:
    explicit menu_owner(QWidget *parent = nullptr);
    ~menu_owner();
public slots:
    void onpbSend(QString t);

private slots:
    void on_pushButton_11_clicked();

private slots:
    void on_pushButton_10_clicked();

private slots:
    void on_pushButton_9_clicked();

private slots:
    void on_pushButton_3_clicked();

private slots:
    void on_pushButton_8_clicked();

private slots:
    void on_pushButton_4_clicked();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void receive_username_o(QString tx);
    void clientConnected();


    void onReadyRead();
    void onConnected();
    void onDisconnected();

private:
    Ui::menu_owner *ui;
    QTcpSocket* socket;
    CargoOwner owner1;
    Cargo cargo1;

signals:
    void log_out();
};

#endif // MENU_OWNER_H
