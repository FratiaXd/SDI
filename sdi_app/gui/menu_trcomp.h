#ifndef MENU_TRCOMP_H
#define MENU_TRCOMP_H

#include <QDialog>

namespace Ui {
class menu_trcomp;
}

class menu_trcomp : public QDialog
{
    Q_OBJECT

public:
    explicit menu_trcomp(QWidget *parent = nullptr);
    ~menu_trcomp();

private:
    Ui::menu_trcomp *ui;
};

#endif // MENU_TRCOMP_H
