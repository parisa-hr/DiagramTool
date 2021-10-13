#include "boundarynotation.h"

#include <QPainter>

BoundaryNotation::BoundaryNotation(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
    setBrush(QColor(240, 255, 255));
}

QRectF  BoundaryNotation::boundingRect() const
{
    return rect();
}

QPainterPath  BoundaryNotation::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  BoundaryNotation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
}
