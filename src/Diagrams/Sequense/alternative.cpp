#include "alternative.h"

#include <QPainter>

Alternative::Alternative(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
}

QRectF  Alternative::boundingRect() const
{
    return rect();
}

QPainterPath  Alternative::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  Alternative::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    auto  pen = QPen(Qt::black, 2);
    pen.setStyle(Qt::DashLine);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    painter->drawRect(rect());
}
