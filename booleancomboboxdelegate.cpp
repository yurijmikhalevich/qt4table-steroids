#include "booleancomboboxdelegate.h"
#include <QComboBox>
#include <QSqlTableModel>

BooleanComboBoxDelegate::BooleanComboBoxDelegate(
    QString sTrue, QString sFalse, QObject *parent)
    : QStyledItemDelegate(parent),
      msTrue(sTrue),
      msFalse(sFalse) {
}

QWidget *BooleanComboBoxDelegate::createEditor(
    QWidget *parent, const QStyleOptionViewItem &option,
    const QModelIndex &index) const {
  QComboBox *editor = new QComboBox(parent);
  editor->addItem(msFalse);
  editor->addItem(msTrue);
  return editor;
}

void BooleanComboBoxDelegate::setEditorData(
    QWidget *editor, const QModelIndex &index) const {
  QComboBox *cEditor = static_cast<QComboBox *>(editor);
  cEditor->setCurrentIndex(index.data().toString() == "Работает" ? 0 : 1);
}

void BooleanComboBoxDelegate::setModelData(
    QWidget *editor, QAbstractItemModel *model,
    const QModelIndex &index) const {
  QComboBox *cEditor = static_cast<QComboBox *>(editor);
  model->setData(index, cEditor->currentIndex());
  model->submit();
  try {
    QSqlTableModel *sModel = dynamic_cast<QSqlTableModel *>(model);
    sModel->select();
  } catch (const std::bad_cast &) {
    // item model is not SqlModel, so do nothing
  }
}
