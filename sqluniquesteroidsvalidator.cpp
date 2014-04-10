#include "sqluniquesteroidsvalidator.h"

#include <QSqlQuery>

SQLUniqueSteroidsValidator::SQLUniqueSteroidsValidator(QString tableName, QString fieldName, QObject *parent) :
    SteroidsValidator(parent)
{
    this->tableName = tableName;
    this->fieldName = fieldName;
}

QValidator::State SQLUniqueSteroidsValidator::validate(QString &input, int &) const
{
    if (input == modelData) {
        return Acceptable;
    }
    QSqlQuery query;
    query.prepare(QString("SELECT id FROM %1 WHERE %2 = ? LIMIT 1").arg(tableName, fieldName));
    query.addBindValue(input);
    if (!query.exec() || query.next()) {
        emit invalidInput(input);
        return Invalid;
    }
    return Acceptable;
}
