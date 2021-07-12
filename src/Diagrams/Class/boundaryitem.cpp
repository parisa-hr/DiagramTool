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
    return _rect;
}

QPainterPath  BoundaryItem::shape() const
{
    QPainterPath  path;

    path.addRect(_rect);

    return path;
}

void  BoundaryItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    painter->drawLine(0, _rect.height() / 5.0, 0, _rect.height() - (_rect.height() / 5.0));
    painter->drawLine(0, _rect.height() / 2.0, _rect.width() / 2.0, _rect.height() / 2.0);
    painter->drawEllipse(_rect.width() / 2.0, 0.0, _rect.height(), _rect.height());
}

void  BoundaryItem::setRect(const QRectF &rect)
{
    _rect = rect;
}
