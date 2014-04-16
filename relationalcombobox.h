#ifndef TABLEHELPER_H
#define TABLEHELPER_H

#include <QComboBox>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QHash>

namespace TableSteroids {
class RelationalComboBox : public QComboBox {
  Q_OBJECT
public:
  RelationalComboBox(QString tableName, QString columnName,
                     QHash<QString, QString> additions = {},
                     QString databaseName = QSqlDatabase::defaultConnection,
                     QWidget *parent = 0);
  int currentId();
  int findId(QString displayData);
private:
  QSqlQueryModel *model;
  QSqlQuery query;
  QString tableName;
  QString columnName;
  QHash<QString, QString> additions;
};
}

#endif // TABLEHELPER_H
