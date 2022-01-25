#include "gui/application.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    application w;
    w.show();
    return a.exec();
}
