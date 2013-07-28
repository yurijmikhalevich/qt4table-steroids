#ifndef STEROIDSVIEW_H
#define STEROIDSVIEW_H

#include <QTableView>

class SteroidsView : public QTableView
{
    Q_OBJECT
public:
    explicit SteroidsView(QWidget *parent = 0);
    void setModel(QAbstractItemModel *model);
    
};

#endif // STEROIDSVIEW_H
