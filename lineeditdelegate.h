#ifndef LINEEDITDELEGATE_H
#define LINEEDITDELEGATE_H

#include <QStyledItemDelegate>
#include "steroidsvalidator.h"

class LineEditDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit LineEditDelegate(SteroidsValidator *validator = nullptr, QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option = QStyleOptionViewItem(),
                          const QModelIndex &index = QModelIndex()) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

private:
    SteroidsValidator *validator;
    
};

#endif // LINEEDITDELEGATE_H
