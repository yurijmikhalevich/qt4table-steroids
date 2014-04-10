#include "datedelegate.h"
#include <QDateEdit>

DateDelegate::DateDelegate(QDate defaultDate, QObject *parent)
  : QStyledItemDelegate(parent),
    mDefaultDate(defaultDate) {
}

QWidget *DateDelegate::createEditor(
    QWidget *parent, const QStyleOptionViewItem &option,
    const QModelIndex &index) const {
  QDateEdit *editor = new QDateEdit(mDefaultDate, parent);
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
