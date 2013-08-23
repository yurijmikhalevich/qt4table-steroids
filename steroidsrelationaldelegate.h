#ifndef STEROIDSRELATIONALDELEGATE_H
#define STEROIDSRELATIONALDELEGATE_H

#include <QStyledItemDelegate>

class SteroidsRelationalDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit SteroidsRelationalDelegate(bool editable = false, QObject *parent = 0);
    QWidget *createEditor(QWidget *parent = 0, const QStyleOptionViewItem &option = QStyleOptionViewItem(),
                          const QModelIndex &index = QModelIndex()) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

private:
    bool editable;
    
};

#endif // STEROIDSRELATIONALDELEGATE_H
