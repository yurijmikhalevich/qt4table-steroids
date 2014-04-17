#include "datedelegate.h"
#include <QDateEdit>

DateDelegate::DateDelegate(QDate defaultDate, QObject *parent,
                           QDate minimumDate, QDate maximumDate)
  : QStyledItemDelegate(parent),
    defaultDate(defaultDate) {
}

QWidget *DateDelegate::createEditor(
    QWidget *parent, const QStyleOptionViewItem &option,
    const QModelIndex &index) const {
  QDateEdit *editor = new QDateEdit(defaultDate, parent);
  editor->setMinimumDate(minimumDate);
  editor->setMaximumDate(maximumDate);
  editor->setDisplayFormat("yyyy-MM-dd");
  return editor;
}

void DateDelegate::setEditorData(
    QWidget *editor, const QModelIndex &index) const {
  QDateEdit *de = static_cast<QDateEdit *>(editor);
  de->setDate(index.data().toDate());
}

void DateDelegate::setModelData(
    QWidget *editor, QAbstractItemModel *model,
    const QModelIndex &index) const {
  QDateEdit *de = static_cast<QDateEdit *>(editor);
  model->setData(index, de->date());
}
