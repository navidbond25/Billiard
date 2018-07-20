//
// Created by sepehr007 on 7/20/18.
//

#ifndef BILLIARD_CONNECTION_H
#define BILLIARD_CONNECTION_H
#include <QObject>
#include <QHostAddress>
#include "Server.h"
class QTcpSocket;
class connection :public QObject
{
Q_OBJECT
public:
    connection(QHostAddress * =new QHostAddress("127.0.0.1"), quint16 =4444);

private:
    QTcpSocket *socket;
    QHostAddress *serveraddress;
    quint16 serverport;
public slots:
    void receivemessage();
    void sendmessage(QString);
signals:
    void newrecievemessage(QString);
};
#endif //BILLIARD_CONNECTION_H
