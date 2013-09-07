#ifndef TABLEHELPER_H
#define TABLEHELPER_H

#include <QWidget>

namespace TableHelper {
QWidget *createRelationalEditor(QString tableName, QString column);
}

#endif // TABLEHELPER_H
