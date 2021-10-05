#include "baseitem.h"

BaseItem::BaseItem(QObject *parent)
{
}

QRectF  BaseItem::rect() const
{
    return _rect;
}

void  BaseItem::setRect(const QRectF &rect)
{
    _rect = rect;
}

QBrush  BaseItem::brush() const
{
    return _brush;
}

void  BaseItem::setBrush(const QBrush &brush)
{
    _brush = brush;
}

QColor  BaseItem::color() const
{
    return _color;
}

void  BaseItem::setColor(const QColor &color)
{
    _color = color;
}
