#include <QCoreApplication>
#include <QDebug>
// #include <drug.h>

int main(int argc, char * argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "main start!";
    // qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
    // qx::QxSqlDatabase::getSingleton()->setDatabaseName("./1.db");
    // qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    // qx::QxSqlDatabase::getSingleton()->setUserName("root");
    // qx::QxSqlDatabase::getSingleton()->setPassword("");
    // QSqlError daoError = qx::dao::create_table<drug>();
    // drug d;
    // d.name = "test";
    // d.description = "111";

    // daoError = qx::dao::insert(d);
    // drug d2;
    // d2.id = 1;
    // daoError = qx::dao::fetch_by_id(d2);
    // qDebug() << "name:" << d2.name << "description:" << d2.description;

    qDebug() << "main stop!";
    return a.exec();
}