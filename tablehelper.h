#ifndef TABLEHELPER_H
#define TABLEHELPER_H

#include <QComboBox>

namespace TableHelper {
QComboBox *createRelationalEditor(QString tableName, QString column);
}

#endif // TABLEHELPER_H
