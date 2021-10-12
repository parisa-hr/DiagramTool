#include "actornotation.h"

ActorNotation::ActorNotation(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
    setBrush(QColor(240, 255, 255));
}

QRectF  ActorNotation::boundingRect() const
{
    return rect();
}

QPainterPath  ActorNotation::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  ActorNotation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
}
