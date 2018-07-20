//
// Created by sepehr007 on 7/19/18.
//

#ifndef BILLIARD_MATCHING_H
#define BILLIARD_MATCHING_H

#include <QtCore/QObject>
#include "UserTable.h"
#include "Login.h"
#include "ServerTable.h"
class Matching: public QObject{
Q_OBJECT
public:
    Matching();

public slots:
    void NewClient(QVector <QString>);
    void NewServer(QVector <QString>);
private:
    Login *mLogin;

signals:
    void IsServer();

};
#endif //BILLIARD_MATCHING_H
