#include "gui/application.h"
#include <QApplication>
#include "headers/myudp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    application w;
    w.show();
    Server server;
    return a.exec();
}
