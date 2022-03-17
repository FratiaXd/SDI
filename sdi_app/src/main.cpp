#include "gui/application.h"
#include <QApplication>
#include "headers/myudp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    application w;
    w.show();
    MyUdp Server;
    MyUdp Client;

    Client.SayHello("privet");
    return a.exec();
}
