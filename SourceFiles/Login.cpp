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
    radio1 = new QRadioButton(tr(" server"));
    radio2 = new QRadioButton(tr(" client"));

    QHBoxLayout *first=new QHBoxLayout;
    first->addWidget(mLabel);
    first->addWidget(mUserName);

    QHBoxLayout *third=new QHBoxLayout;
    third->addWidget(radio1);
    third->addWidget(radio2);

    QVBoxLayout *second=new QVBoxLayout;
    second->addLayout(first);
    second->addLayout(third);
    second->addWidget(buttonarea);
    setLayout(second);

    connect(exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(mLoginButton, SIGNAL(clicked()), this, SLOT(LoginRequest()));

    numberOfuser=0;
    //Make_user_Table();
    show();
}
void Login::Make_user_Table(){
    mUserTable=new QTableWidget();
    mUserTable->setGeometry(20,1,480,480);

}

void Login::LoginRequest() {
    //qDebug()<<"salam";

    QString usr =mUserName->text();
    bool check=false;
    for(int i=0;i<usernames.size();i++){
        if(usernames[i]==usr)
            check=true;
    }
    if(check==false) {
        /*QTableWidgetItem *theItem = new QTableWidgetItem();
        theItem->setData(Qt::EditRole, usr);
        mUserTable->setItem(numberOfuser, 0, theItem);
        */
        emit(AddUser(usr,numberOfuser));
        usernames.push_back(usr);
        if(radio1->isChecked()){
            emit(NewServer(usernames));
        }
        else if(radio2->isChecked()){
            emit(NewClient(usernames));
        }
        numberOfuser++;

        //emit(AddUser(usr,numberOfuser));


    }
}