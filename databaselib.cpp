#include "databaselib.h"

//PRIVATE:
int DataBaseLib::get_table_columns_count(QSqlQuery dbquery) {
    QSqlRecord rec = dbquery.record();
    return rec.count();
}

//PABLIC:
bool DataBaseLib::connect_to_base() {
    db.setDatabaseName("main.db");
    return db.open();
}

QList<QString> DataBaseLib::get_database_tables() {
    return db.tables(QSql::Tables);
}

std::vector<std::vector<QString>> DataBaseLib::db_select(QString _request) {
  std::vector<std::vector<QString>> all_rows_vector;

  QSqlQuery query(db);
  query.exec(_request);

  int table_columns = get_table_columns_count(query);

  while (query.next()) {
      std::vector<QString> row_vector;
      for (int i = 0; i < table_columns; ++i) {
          row_vector.push_back(query.value(i).toString());
      }
      all_rows_vector.push_back(row_vector);
  }
  qDebug() << all_rows_vector << table_columns;
  return all_rows_vector;
}

void DataBaseLib::delete_row_by_id(QString table_name, int id) {
    QSqlQuery query_delete(db);
    query_delete.prepare("DELETE FROM " + table_name +
                         " WHERE id = " + QString::number(id));
    query_delete.exec();
}


