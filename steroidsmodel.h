#ifndef STEROIDSMODEL_H
#define STEROIDSMODEL_H

#include <QObject>
#include <QHash>
#include <QStringList>

template <class C>
class SteroidsModel : public C
{
public:
    explicit SteroidsModel(QObject *parent = 0);

protected:
    void compileFilters();
    QHash<QString, QString> filters;
};

#endif // STEROIDSMODEL_H
