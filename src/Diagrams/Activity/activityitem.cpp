#include "activityitem.h"

#include <qpainter.h>

ActivityItem::ActivityItem(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
}

QRectF  ActivityItem::boundingRect() const
{
    return rect();
}

QPainterPath  ActivityItem::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  ActivityItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setPen(pen);

    painter->setBrush(brush());

    painter->drawRoundedRect(rect(), 20.0, 15.0);
}
