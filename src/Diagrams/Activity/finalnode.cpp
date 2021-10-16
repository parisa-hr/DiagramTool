#include "finalnode.h"
#include <QPainter>
#include <QPen>

FinalNode::FinalNode(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 50, 50));
}

QRectF  FinalNode::boundingRect() const
{
    return rect();
}

QPainterPath  FinalNode::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  FinalNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::black);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    painter->drawEllipse(rect());
    painter->save();
    painter->setBrush(Qt::white);
    painter->drawEllipse(rect().width() / 10.0, rect().height() / 10.0, rect().width() - (rect().width() / 10.0) * 2,
                         rect().height() - (rect().height() / 10.0) * 2);
    painter->restore();

    painter->drawEllipse((rect().width() / 10.0) * 2, (rect().height() / 10.0) * 2, rect().width() - (rect().width() / 10.0) * 4,
                         rect().height() - (rect().height() / 10.0) * 4);
}
