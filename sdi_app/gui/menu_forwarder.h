/** @file menu_forwarder.h
 *  @brief Class representing GUI functionality for forwarder
 *
 *  @author Katrina Petreikyte (fratiaxd)
 */

#ifndef MENU_FORWARDER_H
#define MENU_FORWARDER_H

#include <QWidget>
#include "headers/forwarder.h"
#include "headers/cargo.h"
#include "headers/transp_company.h"
#include "iostream"
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include <QMessageBox>

namespace Ui {
class menu_forwarder;
}

class menu_forwarder : public QWidget
{
    Q_OBJECT

    void AddRoot (QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost, QTreeWidget *widget);
    void AddChild(QTreeWidgetItem *parent, QString id, QString status);
    void AddRoot2 (QString comName, QString comEmail, QString userName, QString phone, QString addrCom);

public:
    explicit menu_forwarder(QWidget *parent = nullptr);
    ~menu_forwarder();

private slots:
    void on_pushButton_7_clicked();

private slots:
    void on_pushButton_6_clicked();

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

    void receive_username_f(QString tx);

private:
    Ui::menu_forwarder *ui;
    Forwarder forw1;
    Cargo cargo1;
    TranspCompany comp1;

signals:
    void log_out();
};

#endif // MENU_FORWARDER_H
