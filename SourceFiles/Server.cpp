//
// Created by sepehr007 on 7/20/18.
//

#include "../HeaderFiles/Server.h"
#include <QDialog>
#include <iostream>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
using namespace std;

Server::Server(QHostAddress *serverAddress, quint16 serverPort) : serverAddress(serverAddress), serverPort(serverPort) {
    clients = new QList<QTcpSocket*>();
    server = new QTcpServer(this);
    server -> listen(*serverAddress, serverPort);
    connect(server,SIGNAL(newConnection()), this, SLOT(createConnection()));

}

void Server::createConnection(){
    QTcpSocket *client = server -> nextPendingConnection();
    clients -> append(client);
    connect(client, SIGNAL(readyRead()), this, SLOT(read()));

}

void Server::read() {
    for(int i = 0;i < clients->size();i ++)
        if(clients -> at(i) -> bytesAvailable() > 0) {
            read(clients->at(i),i);

        }
}
void Server::read(QTcpSocket * client,int i) {
    QByteArray data = client->readAll();
    QString sepehr = data;
    string sep = sepehr.toUtf8().constData();


}
void Server::sendback2(QByteArray finall,int j){


    clients->at(j)->write(finall);
    QString payam=finall;
    string sep=payam.toUtf8().constData();
    //cout<<sep<<endl;

}