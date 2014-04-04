#ifndef TABLEHELPER_H
#define TABLEHELPER_H

#include <QComboBox>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace TableSteroids {
class RelationalComboBox : public QComboBox {
  Q_OBJECT
public:
  RelationalComboBox(QString tableName, QString columnName,
                     QString databaseName = QSqlDatabase::defaultConnection,
                     QWidget *parent = 0);
  int currentId();
private:
  QSqlQueryModel *model;
  QSqlQuery query;
  QString tableName;
  QString columnName;
};
}

#endif // TABLEHELPER_H
