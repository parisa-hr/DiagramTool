#include "hfork_join.h"
#include <QPainter>

HFork_Join::HFork_Join(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 30));
}

QRectF  HFork_Join::boundingRect() const
{
    return rect();
}

QPainterPath  HFork_Join::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  HFork_Join::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 10);
    pen.setCosmetic(true);
    painter->setPen(pen);

    painter->setBrush(Qt::NoBrush);

    auto  p1 = QPointF(10.0, rect().height() / 2.0);
    auto  p2 = QPointF(rect().width() - 10.0, rect().height() / 2.0);

    painter->drawLine(p1, p2);
}
