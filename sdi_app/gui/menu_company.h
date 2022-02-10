#ifndef MENU_COMPANY_H
#define MENU_COMPANY_H

#include <QWidget>
#include "headers/transp_company.h"

namespace Ui {
class menu_company;
}

class menu_company : public QWidget
{
    Q_OBJECT

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

private:
    Ui::menu_company *ui;
    TranspCompany comp1;

signals:
    void log_out();
};

#endif // MENU_COMPANY_H
