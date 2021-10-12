#include "controlnotation.h"

#include <QPainter>

ControlNotation::ControlNotation(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
    setBrush(QColor(240, 255, 255));
}

QRectF  ControlNotation::boundingRect() const
{
    return rect();
}

QPainterPath  ControlNotation::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  ControlNotation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
}
