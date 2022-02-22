/** @file menu_receiver.h
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

namespace Ui {
class menu_owner;
}

class menu_owner : public QWidget
{
    Q_OBJECT

    void AddRoot (QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost);
    void AddChild(QTreeWidgetItem *parent, QString id, QString status);

public:
    explicit menu_owner(QWidget *parent = nullptr);
    ~menu_owner();

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

private:
    Ui::menu_owner *ui;
    CargoOwner owner1;
    Cargo cargo1;

signals:
    void log_out();
};

#endif // MENU_OWNER_H
