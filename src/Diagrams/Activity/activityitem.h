#ifndef ACTIVITYITEM_H
#define ACTIVITYITEM_H

#include <QObject>
#include "src/Base/baseitem.h"

class ActivityItem: public BaseItem
{
public:
    explicit ActivityItem(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ACTIVITYITEM_H
