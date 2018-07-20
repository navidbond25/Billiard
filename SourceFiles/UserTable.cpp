#include <HeaderFiles/UserTable.h>


//
// Created by sepehr007 on 7/19/18.
//
Client_Table::Client_Table(QVector <QString> usr) :QWidget(){

    mUserTable=new QTableWidget(20,1,this);
    mUserTable->setGeometry(0,0,150,400);
    for(int i=0;i<usr.size();i++){
        QTableWidgetItem *brush = new QTableWidgetItem;
        brush->setData(Qt::EditRole ,usr[i]);
        mUserTable->setItem(i, 0, brush);
    }

    show();
}
void Client_Table::Adding(QString usr,int num) {
    QTableWidgetItem *theItem = new QTableWidgetItem();
    theItem->setData(Qt::EditRole, usr);
    mUserTable->setItem(num, 0, theItem);
}


