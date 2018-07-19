//
// Created by sepehr007 on 7/19/18.
//

#ifndef BILLIARD_USERTABLE_H
#define BILLIARD_USERTABLE_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QTableWidget>

class Table: QWidget{
    Q_OBJECT
public:
    Table(QTableWidget* tt);

private:
    QTableWidget *mUserTable;


public slots:
    void Adding(QString,int);


};

#endif //BILLIARD_USERTABLE_H
