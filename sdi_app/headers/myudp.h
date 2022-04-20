/** @file myudp.h
 *  @brief
 *
 *  @author Katrina Petreikyte (fratiaxd)
 */

#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QStringList>
#include <QMap>
#include "gui/menu_owner.h"

#define PORT 1234


class Server : public QObject {
Q_OBJECT
public:
    explicit Server(QObject* parent = 0);
    void sendToAll(const QString&);
public slots:
    void onNewConnection();
    void onDisconnect();
    void onReadyRead();
private:
    QTcpServer* server;
    QMap<QTcpSocket*,QString> clients;
    menu_owner men;
};

#endif // MYUDP_H
