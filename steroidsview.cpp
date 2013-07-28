#include "steroidsview.h"

SteroidsView::SteroidsView(QWidget *parent) :
    QTableView(parent)
{
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSortingEnabled(true);
}

void SteroidsView::setModel(QAbstractItemModel *model)
{
    QTableView::setModel(model);
    hideColumn(0);
}
