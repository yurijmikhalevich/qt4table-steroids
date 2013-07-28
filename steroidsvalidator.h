#ifndef STEROIDSVALIDATOR_H
#define STEROIDSVALIDATOR_H

#include <QValidator>
#include <QString>

class SteroidsValidator : public QValidator
{
    Q_OBJECT
public:
    explicit SteroidsValidator(QObject *parent = 0);
    void setModelData(QString data);

protected:
    QString modelData;
    
};

#endif // STEROIDSVALIDATOR_H
