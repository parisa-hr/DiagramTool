#include "activationoccurrence.h"

#include <QPainter>

ActivationOccurrence::ActivationOccurrence(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(102);
    setRect(QRect(0, 0, 30, 200));
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
    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setPen(pen);

    painter->setBrush(brush());

    painter->drawRoundedRect(QRect(0, 0, 30, rect().height()), 20.0, 15.0);
}
