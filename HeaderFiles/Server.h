//
// Created by sepehr007 on 7/20/18.
//

#ifndef BILLIARD_SERVER_H
#define BILLIARD_SERVER_H

#include <QUdpSocket>
#include <vector>

using namespace std;
class QTimer;
class QHostAddress;
class QDialog;
class QTcpSocket;
class QTcpServer;
class Server : public QObject{
Q_OBJECT
public:
    Server(QHostAddress * = new QHostAddress("127.0.0.1"), quint16 = 8888);
    void read(QTcpSocket*,int);
    QList<QTcpSocket*> *clients;
    QTcpServer *server;

public slots:
    void createConnection();
    void read();
    void sendback2(QByteArray,int);


private:
    QHostAddress *serverAddress;
    quint16 serverPort;





};

#endif //BILLIARD_SERVER_H
