/** @file menu_receiver.h
 *  @brief Class representing GUI functionality for transportation company
 *
 *  @author Katrina Petreikyte (fratiaxd)
 */

#ifndef MENU_COMPANY_H
#define MENU_COMPANY_H

#include <QWidget>
#include "headers/transp_company.h"
#include "headers/cargo.h"
#include "iostream"
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>

namespace Ui {
class menu_company;
}

class menu_company : public QWidget
{
    Q_OBJECT

    void AddRoot (QString id, QString status, QString wei, QString hei, QString wid, QString len, QString typ, QString src, QString dest, QString cost);
    void AddChild(QTreeWidgetItem *parent, QString id, QString status);

public:
    explicit menu_company(QWidget *parent = nullptr);
    ~menu_company();

private slots:
    void on_pushButton_9_clicked();

private slots:
    void on_pushButton_5_clicked();

private slots:
    void on_pushButton_8_clicked();

private slots:
    void on_pushButton_4_clicked();

private slots:
    void on_pushButton_7_clicked();

private slots:
    void on_pushButton_3_clicked();

private slots:
    void on_pushButton_6_clicked();

private slots:
    void on_pushButton_2_clicked();

private slots:
    void on_pushButton_clicked();

    void receive_username_c(QString tx);

private:
    Ui::menu_company *ui;
    TranspCompany comp1;
    Cargo cargo1;

signals:
    void log_out();
};

#endif // MENU_COMPANY_H
