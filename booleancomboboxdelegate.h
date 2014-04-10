#ifndef BOOLEANCOMBOBOXDELEGATE_H
#define BOOLEANCOMBOBOXDELEGATE_H

#include <QStyledItemDelegate>

class BooleanComboBoxDelegate : public QStyledItemDelegate {
  Q_OBJECT
public:
  BooleanComboBoxDelegate(QString sTrue, QString sFalse, QObject *parent = 0);
  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const;
  void setEditorData(QWidget *editor, const QModelIndex &index) const;
  void setModelData(QWidget *editor, QAbstractItemModel *model,
                    const QModelIndex &index) const;
private:
  QString msTrue;
  QString msFalse;
};

#endif // BOOLEANCOMBOBOXDELEGATE_H
