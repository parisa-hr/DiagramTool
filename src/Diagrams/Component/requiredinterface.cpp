#include "requiredinterface.h"

#include <QPainter>

RequiredInterface::RequiredInterface(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 50, 50));
    setBrush(QColor(240, 255, 255));
}

QRectF  RequiredInterface::boundingRect() const
{
    return rect();
}

QPainterPath  RequiredInterface::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  RequiredInterface::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);

    painter->setPen(pen);

    painter->setPen(pen);
    painter->drawArc(rect(), 90 * 16, 180 * 16);
}
