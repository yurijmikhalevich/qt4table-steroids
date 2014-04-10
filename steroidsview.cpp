#include "steroidsview.h"

SteroidsView::SteroidsView(QWidget *parent) :
    QTableView(parent)
{
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::ExtendedSelection);
    setSortingEnabled(true);
    setWordWrap(true);
    deleteShortcut = new QShortcut(Qt::Key_Delete, this, SLOT(deleteSelected()), 0, Qt::WidgetShortcut);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
    contextMenu = new QMenu(this);
    QAction *deleteSelectedAction = new QAction(tr("Delete selected"), this);
    deleteSelectedAction->setShortcut(Qt::Key_Delete);
    deleteSelectedAction->setShortcutContext(Qt::WidgetShortcut);
    connect(deleteSelectedAction, SIGNAL(triggered()), this, SLOT(deleteSelected()));
    contextMenu->addAction(deleteSelectedAction);
}

void SteroidsView::setModel(QAbstractItemModel *model)
{
    QTableView::setModel(model);
    hideColumn(0);
}

void SteroidsView::deleteSelected()
{
    if (!selectionModel()->selectedRows().isEmpty()) {
        emit deleteSelectedRows(selectionModel()->selectedRows());
    }
}

void SteroidsView::showContextMenu(QPoint)
{
    if (!selectionModel()->selectedRows().isEmpty()) {
        contextMenu->exec(QCursor::pos());
    }
}
