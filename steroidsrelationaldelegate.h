#ifndef STEROIDSLRELATIONALDELEGATE_H
#define STEROIDSLRELATIONALDELEGATE_H

#include <QSqlRelationalDelegate>

class SteroidsRelationalDelegate : public QSqlRelationalDelegate {
  Q_OBJECT
public:
  explicit SteroidsRelationalDelegate(QObject *parent = 0);
  QWidget *createEditor(QWidget *aParent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const;
  void setModelData(QWidget *editor, QAbstractItemModel *model,
                    const QModelIndex &index) const;
  void setEditorData(QWidget *editor, const QModelIndex &index) const;
};

#endif // STEROIDSLRELATIONALDELEGATE_H
