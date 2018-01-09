#include "sql.h"

Sql::Sql()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("123");
    if(!isConnected())
        return;


}
Sql::~Sql(){}
QStringList Sql::getDatabaseName()
{
    QString databasesName;
    if(db.open())
    {
        QSqlQuery query;
        query.exec("show databases;");
        while(query.next())
        {

            databasesName = query.value(0).toString();
            dataBases.append(databasesName);
        }
        db.close();
    }
    return dataBases;
}
QStringList Sql::getTableName(QString databaseName)
{
    QSqlQuery query;
    QString tablesName;
    QString command =QString("use")+databaseName+";";
    tables.clear();
    query.exec(command);
    if(db.open())
    {
        query.exec("show tables;");
        while(query.next())
        {

            tablesName = query.value(0).toString();
            tables.append(tablesName);
        }
        db.close();
    }
    return tables;
}
QStringList Sql::getTableColumns(QString tableName)
{
    QSqlQuery query;
    QString columnsName;
    QString command =QString("use")+databaseName+";";
    tables.clear();
    query.exec(command);
    if(db.open())
    {
        query.exec("show tables;");
        while(query.next())
        {

            columnsName = query.value(0).toString();
            columns.append(columnsName;
        }
        db.close();
    }
    return tables;
}
bool Sql::isConnected()
{
    if(this->db.open())
    {

        qDebug() << "Connect to mysql server ok!";
        this->db.close();
        return true;
    }
    else
    {
        qDebug() << "Fail to connect to mysql server.";
        return false;
    }

}
void Sql::setDatabase(QString dataBaseName)
{
     db.setDatabaseName(dataBaseName);
}
void Sql::queryFromTable(QString SQLCommand)
{
    if(db.open())
    {
        QSqlQuery query;
        query.exec(SQLCommand);
        while(query.next())
        {
            int id = query.value(0).toInt();
            QString str = query.value(1).toString();
            qDebug() << id << "|" << str;
        }
        db.close();
    }
    else
    {
        qDebug() << "opened error";
    }
}
void Sql::Open()
{
    db.open();
}
 void Sql::Close()
 {
    db.close();
 }

