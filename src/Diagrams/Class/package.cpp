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
    return rect();
}

QPainterPath  Package::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  Package::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(brush());
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

// painter->drawRect(rect());

    QRectF  r1 = QRectF(0.0, 0.0, rect().width() / 10, rect().width() / 10);
    painter->drawRect(r1);

    QRectF  r2 = QRectF(0.0, rect().width() / 10, rect().width(), rect().height() - rect().width() / 10);
    painter->drawRect(r2);
}
