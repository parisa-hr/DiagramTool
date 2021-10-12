#include "entitynotation.h"

#include <QPainter>

EntityNotation::EntityNotation(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
    setBrush(QColor(240, 255, 255));
}

QRectF  EntityNotation::boundingRect() const
{
    return rect();
}

QPainterPath  EntityNotation::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  EntityNotation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
}
