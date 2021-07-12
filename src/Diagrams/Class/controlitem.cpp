#include "controlitem.h"

ControlItem::ControlItem(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
}

QRectF        ControlItem::boundingRect() const
{
}

QPainterPath  ControlItem::shape() const
{
}

void          ControlItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void          ControlItem::setRect(const QRectF &rect)
{
    _rect = rect;
}
