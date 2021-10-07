#include "classitem.h"
#include <QPainter>
#include <QPen>

classItem::classItem(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
}

QRectF  classItem::boundingRect() const
{
    return rect();
}

QPainterPath  classItem::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  classItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(brush());
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    painter->drawRect(rect());
    painter->drawLine(0, rect().height() / 3, rect().width(), rect().height() / 3);
    // TODO:parisa function ham khat dare?
// painter->drawLine();
}
