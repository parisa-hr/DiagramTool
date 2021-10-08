#include "port.h"

#include <QPainter>

Port::Port(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 50, 50));
    setBrush(QColor(240, 255, 255));
}

QRectF  Port::boundingRect() const
{
    return rect();
}

QPainterPath  Port::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  Port::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setPen(pen);
    painter->setBrush(brush());
    painter->drawRect(rect());
}
