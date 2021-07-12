#include "package.h"

#include <QPainter>
#include <QPen>

Package::Package()
{
    setAcceptHoverEvents(true);
    setZValue(101);
}

QRectF  Package::boundingRect() const
{
    return _rect;
}

QPainterPath  Package::shape() const
{
    QPainterPath  path;

    path.addRect(_rect);

    return path;
}

void  Package::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    painter->drawRect(_rect);
}

void  Package::setRect(const QRectF &rect)
{
    _rect = rect;
}
