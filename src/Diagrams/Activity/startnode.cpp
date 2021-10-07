#include "startnode.h"

#include <QPainter>

StartNode::StartNode(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 100, 100));
}

QRectF  StartNode::boundingRect() const
{
    return rect();
}

QPainterPath  StartNode::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  StartNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setPen(pen);

    painter->setBrush(brush());

    painter->drawEllipse(rect());
}
