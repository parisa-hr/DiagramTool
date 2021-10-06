#ifndef ACTIVITYITEM_H
#define ACTIVITYITEM_H

#include <QObject>

class ActivityItem : public QObject
{
    Q_OBJECT
public:
    explicit ActivityItem(QObject *parent = nullptr);

signals:

};

#endif // ACTIVITYITEM_H
