#include "lineeditdelegate.h"

#include <QLineEdit>

LineEditDelegate::LineEditDelegate(SteroidsValidator *validator, QObject *parent) :
    QStyledItemDelegate(parent)
{
    this->validator = validator;
}

QWidget *LineEditDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit(parent);
    if (validator) {
        editor->setValidator(validator);
    }
    return editor;
}

void LineEditDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QLineEdit *le = static_cast<QLineEdit *>(editor);
    QString modelData = index.data().toString();
    le->setText(modelData);
    if (validator) {
        validator->setModelData(modelData);
    }
}

void LineEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *le = static_cast<QLineEdit *>(editor);
    model->setData(index, le->text());
    model->submit();
}
