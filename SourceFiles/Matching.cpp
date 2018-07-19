//
// Created by sepehr007 on 7/19/18.
//

#include <HeaderFiles/Matching.h>

Matching::Matching() {
    mLogin=new Login();
    connect(mLogin,SIGNAL(NewTable(QTableWidget*)),this,SLOT(New(QTableWidget*)));


}
void Matching::New(QTableWidget *table) {
    Table *newtable=new Table(table);
    //newtable->show();
    connect(mLogin,SIGNAL(AddUser(QString,int)),newtable,SLOT(Adding(QString,int)));
}