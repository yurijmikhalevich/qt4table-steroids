#ifndef SPINBOXDELEGATE_H
#define SPINBOXDELEGATE_H

#include <QStyledItemDelegate>

class SpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit SpinBoxDelegate(int minimum = 0, int maximum = 9999, int defaultValue = 0, QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option = QStyleOptionViewItem(),
                          const QModelIndex &index = QModelIndex()) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    
private:
    int minimum;
    int maximum;
    int defaultValue;
    
};

#endif // SPINBOXDELEGATE_H
