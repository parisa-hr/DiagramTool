#include "decisionnode.h"
#include <QPainter>
#include <QPen>

DecisionNode::DecisionNode(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
}

QRectF  DecisionNode::boundingRect() const
{
    return rect();
}

QPainterPath  DecisionNode::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  DecisionNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(brush());
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    QPointF  points[4] = {
        QPointF(rect().width() / 2.0,                     0.0),
        QPointF(0.0,                    rect().height() / 2.0),
        QPointF((rect().width() / 2.0), rect().height()),
        QPointF(rect().width(),         (rect().height() / 2.0))
    };
    painter->drawConvexPolygon(points, 4);
}
