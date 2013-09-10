#include "tablehelper.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

QComboBox *TableHelper::createRelationalEditor(QString tableName, QString column)
{
    QComboBox *editor = new QComboBox();
    QSqlQuery query;
    query.prepare(QString("SELECT id, %1 FROM %2").arg(column, tableName));
    if (!query.exec()) {
        throw query.lastError();
    }
    while (query.next()) {
        editor->addItem(query.record().value(column).toString(), query.record().value("id"));
    }
    return editor;
}
