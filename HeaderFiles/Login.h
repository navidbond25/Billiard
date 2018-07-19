//
// Created by sepehr007 on 7/19/18.
//

#ifndef BILLIARD_LOGIN_H
#define BILLIARD_LOGIN_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QDesktopWidget>
#include <QVector>
#include <QtWidgets/QTableWidget>

struct Player{
    QString username;
    int score;
};
class Login: public QWidget{
    Q_OBJECT
public:
    Login(QWidget *parent =0);
    void Make_user_Table();

private:
    QLineEdit *mUserName;
    QLabel *mLabel;
    QPushButton *mLoginButton;
    QTableWidget *mUserTable;
    QVector <Player*> mPlayers;
    int numberOfuser;

public slots:
   void LoginRequest();

signals:
    void AddUser(QString,int);
    void NewTable(QTableWidget*);



};


#endif //BILLIARD_LOGIN_H
