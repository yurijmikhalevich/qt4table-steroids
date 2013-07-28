#include "steroidsvalidator.h"

SteroidsValidator::SteroidsValidator(QObject *parent) :
    QValidator(parent)
{
}

void SteroidsValidator::setModelData(QString data)
{
    modelData = data;
}
