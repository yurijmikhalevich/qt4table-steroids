#include "relationalcombobox.h"

#include <QSqlRecord>
#include <QSqlError>
#include <QSqlTableModel>
#include <QDebug>

TableSteroids::RelationalComboBox::RelationalComboBox(
    QString tableName, QString columnName, QHash<QString, QString> additions,
    QString databaseName, QWidget *parent)
    : QComboBox(parent),
      model(new QSqlQueryModel(this)),
      query(QSqlQuery(QSqlDatabase::database(databaseName))),
      tableName(tableName),
      columnName(columnName),
      additions(additions) {
  QString queryString = QString("SELECT %1 FROM %2").arg(columnName, tableName);
  QString where = additions.value("where", "");
  if (!where.isEmpty()) {
    queryString += " WHERE " + where;
  }
  QString order = additions.value("order", "");
  if (!order.isEmpty()) {
    queryString += " ORDER BY " + order;
  }
  model->setQuery(QSqlQuery(queryString, QSqlDatabase::database(databaseName)));
  this->setModel(model);
}

int TableSteroids::RelationalComboBox::currentId() {
  return findId(this->currentText());
}

int TableSteroids::RelationalComboBox::findId(QString displayData) {
  QString queryString = QString("SELECT id FROM %1 WHERE %2 = ?").arg(
        tableName, columnName);
  QString where = additions.value("where", "");
  if (!where.isEmpty()) {
    queryString += " AND " + where;
  }
  QString order = additions.value("order", "");
  if (!order.isEmpty()) {
    queryString += " ORDER BY " + order;
  }
  query.prepare(queryString);
  query.addBindValue(displayData);
  if (!query.exec() || !query.next()) {
    if (query.lastError().isValid()) {
      qDebug() << query.lastError().text();
    }
    qDebug() << "error in RelationalComboBox" << tableName;
    return -1;
  }
  return query.record().value("id").toInt();
}
