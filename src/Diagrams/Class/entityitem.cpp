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
    return _rect;
}

QPainterPath  EntityItem::shape() const
{
    QPainterPath  path;

    path.addRect(_rect);

    return path;
}

void  EntityItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    painter->drawLine(0, _rect.height(), _rect.width(), _rect.height());
    painter->drawEllipse(0.0, 0.0, _rect.width(), _rect.height());
}

void  EntityItem::setRect(const QRectF &rect)
{
    _rect = rect;
}
