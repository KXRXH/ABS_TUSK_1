#ifndef DATABASELIB_H
#define DATABASELIB_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QList>
#include <vector>
#include <QDebug>
#include <QtSql/QSqlRecord>

class DataBaseLib
{
private:
    QSqlDatabase db;
    int get_table_columns_count(QSqlQuery dbquery);
public:
    DataBaseLib(QSqlDatabase database) { db = database; };
    bool connect_to_base();
    QList<QString> get_database_tables();
    std::vector<std::vector<QString>> db_select(QString _request);
    void delete_row_by_id(QString table_name, int id);
    // void insert_row_to_table(QString table_name, std::vector<std::vector<QString>)
};

#endif // DATABASELIB_H
