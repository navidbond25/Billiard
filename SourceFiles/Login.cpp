//
// Created by sepehr007 on 7/19/18.
//

#include <HeaderFiles/Login.h>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QDialogButtonBox>
#include <QDebug>

Login::Login(QWidget *parent) : QWidget(parent){
    QRect rec = QApplication::desktop() -> screenGeometry();
    setGeometry(500, 100, 350, 150);
    numberOfuser=0;

    mUserName=new QLineEdit();
    //mUserName -> setFixedHeight(25);
    mLabel=new QLabel("username : ");

    QPushButton *exit =new QPushButton("EXIT",this);
    mLoginButton=new QPushButton("Login", this);
    QDialogButtonBox *buttonarea=new QDialogButtonBox;
    buttonarea -> addButton(exit, QDialogButtonBox::RejectRole);
    buttonarea -> addButton(mLoginButton, QDialogButtonBox::ActionRole);

    QHBoxLayout *first=new QHBoxLayout;
    first->addWidget(mLabel);
    first->addWidget(mUserName);

    QVBoxLayout *second=new QVBoxLayout;
    second->addLayout(first);
    second->addWidget(buttonarea);
    setLayout(second);

    connect(exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(mLoginButton, SIGNAL(clicked()), this, SLOT(LoginRequest()));
    Make_user_Table();
    show();
}
void Login::Make_user_Table(){
    mUserTable=new QTableWidget();
    mUserTable->setGeometry(20,1,480,480);
    numberOfuser=0;
}

void Login::LoginRequest() {
    //qDebug()<<"salam";

    QString usr =mUserName->text();
    bool check=false;
    for(int i=0;i<mPlayers.size();i++){
        if(mPlayers[i]->username==usr)
            check=true;
    }
    if(check==false) {
        QTableWidgetItem *theItem = new QTableWidgetItem();
        theItem->setData(Qt::EditRole, usr);
        mUserTable->setItem(numberOfuser, 0, theItem);
        numberOfuser++;
        emit(NewTable(mUserTable));
        emit(AddUser(usr,numberOfuser));



        Player* newnode=new Player;
        newnode->username=usr;
        newnode->score=0;
        mPlayers.push_back(newnode);
    }
}