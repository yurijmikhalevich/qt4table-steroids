#include "sqluniquesteroidsvalidator.h"
#include <QSqlQuery>

SQLUniqueSteroidsValidator::SQLUniqueSteroidsValidator(
    QString tableName, QString fieldName, bool isNotNull, QObject *parent)
    : SteroidsValidator(parent),
      tableName(tableName),
      fieldName(fieldName),
      isNotNull(isNotNull) {
}

QValidator::State SQLUniqueSteroidsValidator::validate(
    QString &input, int &) const {
  QString inputData = QString(input).simplified();
  if (isNotNull && inputData.isEmpty()) {
    emit invalidInput(input);
    return Intermediate;
  }
  if (inputData == modelData) {
    emit validInput(input);
    return Acceptable;
  }
  QSqlQuery query;
  query.prepare(QString("SELECT id FROM %1 WHERE %2 = ? LIMIT 1").arg(
                  tableName, fieldName));
  query.addBindValue(inputData);
  if (!query.exec() || query.next()) {
    emit invalidInput(input);
    return Intermediate;
  }
  emit validInput(input);
  return Acceptable;
}
