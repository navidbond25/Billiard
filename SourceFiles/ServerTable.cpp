//
// Created by sepehr007 on 7/20/18.
//
#include "HeaderFiles/ServerTable.h"
Server_Table::Server_Table(QVector <QString> usr) :QWidget(){

    mUserTable=new QTableWidget(20,1,this);
    mUserTable->setGeometry(0,0,150,400);
    for(int i=0;i<usr.size();i++){
        QTableWidgetItem *brush = new QTableWidgetItem;
        brush->setData(Qt::EditRole, usr[i]);
        mUserTable->setItem(i, 0, brush);
    }
    connector=new connection;
    show();
    connect(this->mUserTable, SIGNAL(cellPressed(int, int)), this, SLOT(mouseClicking(int, int)));
}
void Server_Table::Adding(QString usr,int num) {
    QTableWidgetItem *theItem = new QTableWidgetItem();
    theItem->setData(Qt::EditRole, usr);
    mUserTable->setItem(num, 0, theItem);
}
void Server_Table::mouseClicking(int x,int y){
    QString usrname = mUserTable->item( x, y )->text();
    emit(choose_user(usrname));
}