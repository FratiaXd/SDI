/** @file myudp.h
 *  @brief Starts the server and manages notifications within the program
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
    /** @brief default constructor
     *
     * @param parent
     */
    explicit Server(QObject* parent = 0);

    /** @brief sends message to all users
     *
     */
    void sendToAll(const QString&);
public slots:

    /** @brief binds new user to the socket and connects all signals
     * adds new user information to the QMap
     *
     */
    void onNewConnection();

    /** @brief removes user from the QMap
     *
     */
    void onDisconnect();

    /** @brief receives data and processes it
     *
     */
    void onReadyRead();
private:
    QTcpServer* server;
    QMap<QTcpSocket*,QString> clients;
    menu_owner men;
};

#endif // MYUDP_H
