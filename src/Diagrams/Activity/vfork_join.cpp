#include "vfork_join.h"

#include <QPainter>

VFork_Join::VFork_Join(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 30, 200));
}

QRectF  VFork_Join::boundingRect() const
{
    return rect();
}

QPainterPath  VFork_Join::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  VFork_Join::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 10);
    pen.setCosmetic(true);
    painter->setPen(pen);

    painter->setBrush(Qt::NoBrush);
    auto  p1 = QPointF(rect().width() / 2.0, 10.0);
    auto  p2 = QPointF(rect().width() / 2.0, rect().height() - 10.0);

    painter->drawLine(p1, p2);
}
