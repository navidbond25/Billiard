//
// Created by sepehr007 on 7/20/18.
//

#include "../HeaderFiles/Connection.h"
#include <QHostAddress>
#include <QTcpSocket>


using namespace std;
connection::connection(QHostAddress *serveraddress, quint16 serverport)
{
    Server *myserver=new Server();
    socket= new QTcpSocket;
    socket -> connectToHost(*serveraddress, serverport);
    connect(socket, SIGNAL(readyRead()), this, SLOT(receivemessage()));
}
void connection::receivemessage()
{
    QString message=socket -> readAll();
    emit newrecievemessage(message);
}
void connection::sendmessage(QString message)
{
    QByteArray data=&message.toStdString()[0];
    socket-> write(data);
}