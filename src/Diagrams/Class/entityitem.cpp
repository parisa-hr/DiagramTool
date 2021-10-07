#include "entityitem.h"

#include <QPainter>
#include <QPen>

EntityItem::EntityItem(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
}

QRectF  EntityItem::boundingRect() const
{
    return rect();
}

QPainterPath  EntityItem::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  EntityItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(brush());
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    painter->drawLine(0, rect().height(), rect().width(), rect().height());
    painter->drawEllipse(0.0, 0.0, rect().width(), rect().height());
}
