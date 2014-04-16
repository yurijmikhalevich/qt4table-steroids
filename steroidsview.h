#ifndef STEROIDSVIEW_H
#define STEROIDSVIEW_H

#include <QTableView>
#include <QShortcut>
#include <QMenu>
#include <QSqlTableModel>

class SteroidsView : public QTableView {
  Q_OBJECT
public:
  explicit SteroidsView(QWidget *parent = 0);
  void setModel(QAbstractItemModel *model);
private:
  QShortcut *deleteShortcut;
  QMenu *contextMenu;
public slots:
  void deleteSelected();
private slots:
  void showContextMenu(QPoint);
signals:
  void deleteSelectedRows(QModelIndexList selectedRows);
};

#endif // STEROIDSVIEW_H
