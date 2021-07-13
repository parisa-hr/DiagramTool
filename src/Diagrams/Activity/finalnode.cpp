#include "finalnode.h"
#include <QPainter>
#include <QPen>

FinalNode::FinalNode(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
}

QRectF  FinalNode::boundingRect() const
{
    return _rect;
}

QPainterPath  FinalNode::shape() const
{
    QPainterPath  path;

    path.addRect(_rect);

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

// painter->drawRect(_rect);

    painter->drawEllipse(_rect);
    painter->save();
    painter->setBrush(Qt::white);
    painter->drawEllipse(_rect.width() / 10.0, _rect.height() / 10.0, _rect.width() - (_rect.width() / 10.0) * 2, _rect.height() - (_rect.height() / 10.0) * 2);
    painter->restore();

    painter->drawEllipse((_rect.width() / 10.0) * 2, (_rect.height() / 10.0) * 2, _rect.width() - (_rect.width() / 10.0) * 4,
                         _rect.height() - (_rect.height() / 10.0) * 4);
}

void  FinalNode::setRect(const QRectF &rect)
{
    _rect = rect;
}
