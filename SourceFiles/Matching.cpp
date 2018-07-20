//
// Created by sepehr007 on 7/19/18.
//

#include <HeaderFiles/Matching.h>


Matching::Matching() {
    mLogin=new Login();
    connect(mLogin,SIGNAL(NewClient(QVector <QString>)),this,SLOT(NewClient(QVector <QString>)));
    connect(mLogin,SIGNAL(NewServer(QVector <QString>)),this,SLOT(NewServer(QVector <QString>)));

}
void Matching::NewClient(QVector <QString> names) {
    Client_Table *newtable=new Client_Table(names);
    //newtable->show();
    connect(mLogin,SIGNAL(AddUser(QString,int)),newtable,SLOT(Adding(QString,int)));
}
void Matching::NewServer(QVector <QString> names) {
    Server_Table *newtable=new Server_Table(names);
    connect(mLogin,SIGNAL(AddUser(QString,int)),newtable,SLOT(Adding(QString,int)));

}