#ifndef SQLUNIQUESTEROIDSVALIDATOR_H
#define SQLUNIQUESTEROIDSVALIDATOR_H

#include "steroidsvalidator.h"

class SQLUniqueSteroidsValidator : public SteroidsValidator {
  Q_OBJECT
public:
  explicit SQLUniqueSteroidsValidator(
      QString tableName, QString fieldName, bool isNotNull,
      QObject *parent = 0);
  State validate(QString &input, int &) const;
private:
  QString tableName;
  QString fieldName;
  bool isNotNull;
signals:
  void invalidInput(QString &input) const;
  void validInput(QString &input) const;
};

#endif // SQLUNIQUESTEROIDSVALIDATOR_H
