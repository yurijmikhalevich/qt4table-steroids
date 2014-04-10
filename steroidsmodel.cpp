#include "steroidsmodel.h"
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QDebug>

template <class C>
SteroidsModel<C>::SteroidsModel(QObject *parent)
    : C(parent) {
  QSqlTableModel::setEditStrategy(QSqlTableModel::OnFieldChange);
}

template <class C>
void SteroidsModel<C>::queryChanged(QString query) {
  filters.insert("query", query);
  compileFilters();
}

template <class C>
void SteroidsModel<C>::compileFilters() {
  this->setFilter(QStringList(filters.values()).join(" AND "));
  this->select();
}

template class SteroidsModel<QSqlTableModel>;
template class SteroidsModel<QSqlRelationalTableModel>;
