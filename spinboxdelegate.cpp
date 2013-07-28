#include "spinboxdelegate.h"

#include <QSpinBox>

SpinBoxDelegate::SpinBoxDelegate(int minimum, int maximum, int defaultValue, QObject *parent) :
    QStyledItemDelegate(parent)
{
    this->minimum = minimum;
    this->maximum = maximum;
    this->defaultValue = defaultValue;
}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                       const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(minimum);
    editor->setMaximum(maximum);
    editor->setValue(defaultValue);
    editor->setSingleStep(1);
    return editor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QSpinBox *sb = static_cast<QSpinBox *>(editor);
    sb->setValue(index.data().toInt());
}

void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *sb = static_cast<QSpinBox *>(editor);
    model->setData(index, sb->value());
    model->submit();
}
