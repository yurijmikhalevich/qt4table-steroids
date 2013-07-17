#include "checkboxdelegate.h"

#include <QCheckBox>
#include <QStylePainter>

CheckBoxDelegate::CheckBoxDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

QWidget *CheckBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    QCheckBox *editor = new QCheckBox(parent);
    return editor;
}

void CheckBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QCheckBox *cb = static_cast<QCheckBox *>(editor);
    cb->setChecked(index.data().toBool());
}

void CheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QCheckBox *cb = static_cast<QCheckBox *>(editor);
    if (cb->isChecked()) {
        model->setData(index, 1);
    } else {
        model->setData(index, 0);
    }
    model->submit();
}

//void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    QCheckBox *ed = new QCheckBox();
//    QPixmap pm = QPixmap::grabWidget(ed);
//    painter->drawPixmap(option.rect.x(), option.rect.y(), pm);
////    painter->set
//}
