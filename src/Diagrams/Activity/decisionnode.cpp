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
    return _rect;
}

QPainterPath  DecisionNode::shape() const
{
    QPainterPath  path;

    path.addRect(_rect);

    return path;
}

void  DecisionNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    QPointF  points[4] = {
        QPointF(_rect.width() / 2.0,                    0.0),
        QPointF(0.0,                   _rect.height() / 2.0),
        QPointF((_rect.width() / 2.0), _rect.height()),
        QPointF(_rect.width(),         (_rect.height() / 2.0))
    };
    painter->drawConvexPolygon(points, 4);
}

void  DecisionNode::setRect(const QRectF &rect)
{
    _rect = rect;
}
