#include "steroidsmodel.h"

#include <QSqlTableModel>
#include <QSqlRelationalTableModel>

template <class C>
SteroidsModel<C>::SteroidsModel(QObject *parent) :
    C(parent)
{
}

template <class C>
void SteroidsModel<C>::queryChanged(QString query) {
    filters.insert("query", query);
    compileFilters();
}

template <class C>
void SteroidsModel<C>::compileFilters()
{
    this->setFilter(QStringList(filters.values()).join(" AND "));
    this->select();
}

template class SteroidsModel<QSqlTableModel>;
template class SteroidsModel<QSqlRelationalTableModel>;
