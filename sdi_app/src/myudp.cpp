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

/* Отправить сообщение всем пользователям */
void Server::sendToAll(const QString& msg) {
            foreach (QTcpSocket* socket, clients.keys()) {
            socket->write(msg.toUtf8());
        }
}

/* Слот, который вызывается, когда к серверу подключается
 * новый клиент */
void Server::onNewConnection() {
    QTcpSocket* socket = server->nextPendingConnection();
    qDebug() << "Client connected: " << socket->peerAddress().toString();

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(&men, SIGNAL(log_out()), socket, SIGNAL(disconnected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));

    // оставим клиента безымянным пока он не залогинится
    clients.insert(socket, "");
}

/* Слот, вызываемый при отключении клиента */
//doesnt know which one disconnects!!!!!!!!!!!!!!
void Server::onDisconnect() {
    cout << "disconnect" << endl;
    QTcpSocket* socket = (QTcpSocket*)sender();
    qDebug() << "Client disconnected: " << socket->peerAddress().toString();
    QString username = clients.value(socket);
    sendToAll(QString("/system:" + username + " has left the chat.\n"));
    clients.remove(socket);
}

/* Прием данных от клиента */
void Server::onReadyRead() {
    QRegExp loginRex("^/login:(.*)$");
    QRegExp messageRex("^/say:(.*)$");
    QTcpSocket* socket = (QTcpSocket*)sender();
    while (socket->canReadLine()) {
        QString line = QString::fromUtf8(socket->readLine()).trimmed();
        /* Сообщение - пользователь логинится */
        if (loginRex.indexIn(line) != -1) {
            QString user = loginRex.cap(1);
            clients[socket] = user;
            sendToAll(QString("/system:" + user + " has joined the chat.\n"));
            qDebug() << user << "logged in.";
        }
            /* Сообщение в чат */
        else if (messageRex.indexIn(line) != -1) {
            QString user = clients.value(socket);
            QString msg = messageRex.cap(1);
            sendToAll(QString(user + ":" + msg + "\n"));
            qDebug() << "User:" << user;
            qDebug() << "Message:" << msg;
        }
            /* Некорректное сообщение от клиента */
        else {
            qDebug() << "Bad message from " << socket->peerAddress().toString();
        }
    }
}