#ifndef DATEDELEGATE_H
#define DATEDELEGATE_H

#include <QStyledItemDelegate>
#include <QDate>

class DateDelegate : public QStyledItemDelegate {
  Q_OBJECT
public:
  DateDelegate(QDate defaultDate, QObject *parent = 0,
               QDate minimumDate = QDate(0, 0, 0),
               QDate maximumDate = QDate(9999, 12, 31));
  QWidget *createEditor(
      QWidget *parent,
      const QStyleOptionViewItem &option = QStyleOptionViewItem(),
      const QModelIndex &index = QModelIndex()) const;
  void setEditorData(QWidget *editor, const QModelIndex &index) const;
  void setModelData(QWidget *editor, QAbstractItemModel *model,
                    const QModelIndex &index) const;
private:
  QDate defaultDate;
  QDate minimumDate;
  QDate maximumDate;
};

#endif // DATEDELEGATE_H
