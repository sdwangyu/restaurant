#include "restaurant.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlQuery>


bool OpenDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    qDebug()<<"ODBC driver?"<<db.isValid();
    QString dsn = QString::fromLocal8Bit("database");      //数据源名称
    db.setHostName("localhost");                        //选择本地主机，127.0.1.1
    db.setDatabaseName(dsn);                            //设置数据源名称
    db.setUserName("sa");                               //登录用户
    db.setPassword("2017414");                           //密码
    if(!db.open())                                      //打开数据库
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
        return false;                                   //打开失败
    }
    else
        qDebug()<<"database open success!";
    return true;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    restaurant w;
    //sqlsever w;
    //打开数据库
    if(! OpenDatabase())              //执行完该函数就表示数据库已经被打开了  所有的query操作都指向该数据库
        qDebug() << "open fail";

    //数据库查询语句
    /*QSqlQuery query1("select Sno, Sname, Sage from Student");
    //query.exec("select Sno, Sname from Student");
    while(query1.next()){
        qDebug() << query1.value(0).toString() << query1.value(1).toString() << query1.value(2).toInt();
    }
    QSqlQuery query2("select Sno from Student where Sage > 20");
    while(query2.next())
        qDebug() << query2.value(0).toString();

    //数据库插入语句
    QSqlQuery query3;
    if(query3.exec("insert into Student values('201215129', '王正涛', '男', 20, 'CS')"))
        qDebug() << "insert success";
    else
        qDebug() << "insert fail";
    query3.exec("select Sname, Sage from Student where Sno = '201215129'");//检验是否插入成功
    while(query3.next())
    {
        qDebug() << query3.value(0).toString() << query3.value(1).toInt();
    }
    //删除操作
    if(query3.exec("delete from Student where Sname = '王正涛'"))
        qDebug() << "delete success";
    else
        qDebug() << "delete fail";
    //更新操作
    if(query3.exec("update Student set Sage = 20 where Sno = '201215128'"))
        qDebug() << "update success";
    else
        qDebug() << "update fail";*/


    w.show();

    return a.exec();
}
