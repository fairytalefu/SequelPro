#ifndef SQL_H
#define SQL_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql/QSql>
#include <QDebug>
#include <QStringList>
#include <QList>
class Sql
{
public:
    Sql();
    ~Sql();
    QStringList getDatabaseName();
    QStringList getTableName(QString databaseName);
    QStringList getTableColumns(QString databaseName);
    bool isConnected();
    void setDatabase(QString dataBaseName);
    void Open();
    void queryFromTable(QString SQLCommand);
    void Close();
private:
    QSqlDatabase db;
    QStringList dataBases;
    QStringList tables;
    QStringList columns;
    QString dbName;
    QString tableName;
};

#endif // SQL_H
