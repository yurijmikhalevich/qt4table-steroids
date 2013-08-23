#include "steroidsrelationaldelegate.h"

#include <QComboBox>
#include <QSqlRelationalTableModel>

SteroidsRelationalDelegate::SteroidsRelationalDelegate(bool editable, QObject *parent) :
    QStyledItemDelegate(parent)
{
    this->editable = editable;
}

QWidget *SteroidsRelationalDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                                  const QModelIndex &index) const
{
    const QSqlRelationalTableModel *sqlModel = static_cast<const QSqlRelationalTableModel *>(index.model());
    QSqlTableModel *childModel = sqlModel ? sqlModel->relationModel(index.column()) : 0;
    if (!childModel)
        return QStyledItemDelegate::createEditor(parent, option, index);
    QComboBox *combo = new QComboBox(parent);
    combo->setModel(childModel);
    combo->setModelColumn(childModel->fieldIndex(sqlModel->relation(index.column()).displayColumn()));
//    combo->installEventFilter(const_cast<SteroidsRelationalDelegate *>(this));
    combo->setEditable(editable);
    QSqlTableModel *model = static_cast<QSqlTableModel *>(combo->model());
    model->setFilter("dismissed = 0");
    model->select();
    return combo;
}

void SteroidsRelationalDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    const QSqlRelationalTableModel *sqlModel = static_cast<const QSqlRelationalTableModel *>(index.model());
    QComboBox *combo = static_cast<QComboBox *>(editor);
    if (!sqlModel || !combo) {
        QStyledItemDelegate::setEditorData(editor, index);
        return;
    }
    combo->setCurrentIndex(combo->findText(sqlModel->data(index).toString()));
}

void SteroidsRelationalDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                              const QModelIndex &index) const
{
    if (!index.isValid())
        return;

    QSqlRelationalTableModel *sqlModel = qobject_cast<QSqlRelationalTableModel *>(model);
    QSqlTableModel *childModel = sqlModel ? sqlModel->relationModel(index.column()) : 0;
    QComboBox *combo = qobject_cast<QComboBox *>(editor);
    if (!sqlModel || !childModel || !combo) {
        QStyledItemDelegate::setModelData(editor, model, index);
        return;
    }

    int currentItem = combo->currentIndex();
    int childColIndex = childModel->fieldIndex(sqlModel->relation(index.column()).displayColumn());
    int childEditIndex = childModel->fieldIndex(sqlModel->relation(index.column()).indexColumn());
    sqlModel->setData(index,
            childModel->data(childModel->index(currentItem, childColIndex), Qt::DisplayRole),
            Qt::DisplayRole);
    sqlModel->setData(index,
            childModel->data(childModel->index(currentItem, childEditIndex), Qt::EditRole),
            Qt::EditRole);
}
