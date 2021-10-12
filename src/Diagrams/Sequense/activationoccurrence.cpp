#include "activationoccurrence.h"

#include <QPainter>

ActivationOccurrence::ActivationOccurrence(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
    setBrush(QColor(240, 255, 255));
}

QRectF  ActivationOccurrence::boundingRect() const
{
    return rect();
}

QPainterPath  ActivationOccurrence::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  ActivationOccurrence::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
}
