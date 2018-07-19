#include <HeaderFiles/UserTable.h>


//
// Created by sepehr007 on 7/19/18.
//
Table::Table(QTableWidget *tt) :QWidget(){
    mUserTable=tt;
    show();
}
void Table::Adding(QString usr,int num) {
    QTableWidgetItem *theItem = new QTableWidgetItem();
    theItem->setData(Qt::EditRole, usr);
    mUserTable->setItem(num, 0, theItem);
}

