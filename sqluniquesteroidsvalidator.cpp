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
  input = input.simplified();
  if (isNotNull && input.isEmpty()) {
    return Intermediate;
  }
  if (input == modelData) {
    return Acceptable;
  }
  QSqlQuery query;
  query.prepare(QString("SELECT id FROM %1 WHERE %2 = ? LIMIT 1").arg(
                  tableName, fieldName));
  query.addBindValue(input);
  if (!query.exec() || query.next()) {
    emit invalidInput(input);
    return Intermediate;
  }
  return Acceptable;
}
