#include "swimlane.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

Swimlane::Swimlane(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 100, 100));
}

QRectF  Swimlane::boundingRect() const
{
    return rect();
}

QPainterPath  Swimlane::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  Swimlane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setPen(pen);
}

void  Swimlane::insert()
{
}
