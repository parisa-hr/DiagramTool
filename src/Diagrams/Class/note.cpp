#include "note.h"

#include <QPainter>
#include <QPen>

Note::Note()
{
    setAcceptHoverEvents(true);
    setZValue(101);
}

QRectF  Note::boundingRect() const
{
    return _rect;
}

QPainterPath  Note::shape() const
{
    QPainterPath  path;

    path.addRect(_rect);

    return path;
}

void  Note::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);
}

void  Note::setRect(const QRectF &rect)
{
    _rect = rect;
}
