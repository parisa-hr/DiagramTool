#include "boundaryitem.h"

#include <QPainter>
#include <QPen>

BoundaryItem::BoundaryItem(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
}

QRectF  BoundaryItem::boundingRect() const
{
    return rect();
}

QPainterPath  BoundaryItem::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  BoundaryItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(brush());
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    painter->drawLine(0, rect().height() / 5.0, 0, rect().height() - (rect().height() / 5.0));
    painter->drawLine(0, rect().height() / 2.0, rect().width() / 2.0, rect().height() / 2.0);
    painter->drawEllipse(rect().width() / 2.0, 0.0, rect().height(), rect().height());
}
