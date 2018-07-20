//
// Created by sepehr007 on 7/20/18.
//

#ifndef BILLIARD_SERVERTABLE_H
#define BILLIARD_SERVERTABLE_H
#include <QtWidgets/QWidget>
#include <QtWidgets/QTableWidget>
#include "Connection.h"

class Server_Table: public QWidget{
Q_OBJECT
public:
    Server_Table(QVector <QString>);
    void StartServer();

private:
    QTableWidget *mUserTable;
    connection * connector;

public slots:
    void Adding(QString,int);
    void mouseClicking(int ,int);

signals:
    void choose_user(QString);
};

#endif //BILLIARD_SERVERTABLE_H
