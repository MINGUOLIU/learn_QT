#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL","conn");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setConnectOptions("MYSQL_OPT_RECONNECT=1");
    db.setDatabaseName("students");
    db.setUserName("root");
    db.setPassword("liu3357");



    bool ok = db.open();
    if(!ok)
    {
        QMessageBox::critical(0, QObject::tr("连接数据库失败！"), db.lastError().text());
        return 1;
    }
    else
    {
        qDebug()<<QObject::tr("连接到数据库。");
    }

    qApp->setWindowIcon(QIcon(":/images/windowIcon.png"));


    Login login;
    login.show();



    return a.exec();
}
