#include "classitem.h"
#include <QPainter>
#include <QPen>

classItem::classItem(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
}

QRectF  classItem::boundingRect() const
{
    return _rect;
}

QPainterPath  classItem::shape() const
{
    QPainterPath  path;

    path.addRect(_rect);

    return path;
}

void  classItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    painter->drawRect(_rect);
    painter->drawLine(0, _rect.height() / 3, _rect.width(), _rect.height() / 3);
    // TODO:parisa function ham khat dare?
// painter->drawLine();
}

void  classItem::setRect(const QRectF &rect)
{
    _rect = rect;
}
