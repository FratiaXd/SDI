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

private:
    Ui::menu_company *ui;
    TranspCompany comp1;
};

#endif // MENU_COMPANY_H
