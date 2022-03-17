#include "headers/myudp.h"

MyUdp::MyUdp(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,1234);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void MyUdp::SayHello(QString a) {
    QByteArray Data;
    Data.append(a);
    socket->writeDatagram(Data,QHostAddress::LocalHost,1234);

}

void MyUdp::readyRead() {
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(), Buffer.size(), &sender, &senderPort);

    qDebug() << "Message from send: " << sender.toString();
    qDebug() << "Message from port: " << senderPort;
    qDebug() << "Message: " << Buffer;
}