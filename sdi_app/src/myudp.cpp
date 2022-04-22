#include "headers/myudp.h"
#include <QString>
#include <QRegExp>

Server::Server(QObject* parent) : QObject(parent) {
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()),
            this,   SLOT(onNewConnection()));

    if (!server->listen(QHostAddress::Any, PORT)) {
        qDebug() << "Server is not started.";
    } else {
        qDebug() << "Server is started.";
    }
}

/* Sent a notification to all users*/
void Server::sendToAll(const QString& msg) {
            foreach (QTcpSocket* socket, clients.keys()) {
            socket->write(msg.toUtf8());
        }
}

/* Is called when the new user is connected to the server*/
void Server::onNewConnection() {
    QTcpSocket* socket = server->nextPendingConnection();
    qDebug() << "Client connected: " << socket->peerAddress().toString();

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(&men, SIGNAL(log_out()), socket, SIGNAL(disconnected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));

    // leaving client without username until client logs in
    clients.insert(socket, "");
}

/* Is called when the user disconnects from the server*/
void Server::onDisconnect() {
    cout << "disconnect" << endl;
    QTcpSocket* socket = (QTcpSocket*)sender();
    qDebug() << "Client disconnected: " << socket->peerAddress().toString();
    QString username = clients.value(socket);
    clients.remove(socket);
}

/* Receives data */
void Server::onReadyRead() {
    QRegExp loginRex("^/login:(.*)$");
    QRegExp messageRex("^/say:(.*)$");
    QTcpSocket* socket = (QTcpSocket*)sender();
    while (socket->canReadLine()) {
        QString line = QString::fromUtf8(socket->readLine()).trimmed();
        /* Message - new user connected */
        if (loginRex.indexIn(line) != -1) {
            QString user = loginRex.cap(1);
            clients[socket] = user;
        }
            /* Notification */
        else if (messageRex.indexIn(line) != -1) {
            QString user = clients.value(socket);
            QString msg = messageRex.cap(1);
            sendToAll(QString(user + ":" + msg + "\n"));
            qDebug() << "User:" << user;
            qDebug() << "Message:" << msg;
        }
            /* Error handling */
        else {
            qDebug() << "Bad message from " << socket->peerAddress().toString();
        }
    }
}