#include "relationalcombobox.h"

#include <QSqlRecord>
#include <QSqlError>
#include <QSqlTableModel>
#include <QDebug>

TableSteroids::RelationalComboBox::RelationalComboBox(
    QString tableName, QString columnName, QString databaseName,
    QWidget *parent)
    : QComboBox(parent),
      model(new QSqlQueryModel(this)),
      query(QSqlQuery(QSqlDatabase::database(databaseName))),
      tableName(tableName),
      columnName(columnName) {
  model->setQuery(
        QSqlQuery(QString("SELECT %1 FROM %2").arg(columnName, tableName),
                  QSqlDatabase::database(databaseName)));
  this->setModel(model);
}

int TableSteroids::RelationalComboBox::currentId() {
  return findId(this->currentText());
}

int TableSteroids::RelationalComboBox::findId(QString displayData) {
  query.prepare(QString("SELECT id FROM %1 WHERE %2 = ?").arg(
                  tableName, columnName));
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
