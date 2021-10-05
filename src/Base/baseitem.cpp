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
