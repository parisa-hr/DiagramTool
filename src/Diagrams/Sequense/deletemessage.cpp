#include "deletemessage.h"

#include <QPainter>

DeleteMessage::DeleteMessage(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 100, 100));
}

QRectF  DeleteMessage::boundingRect() const
{
    return rect();
}

QPainterPath  DeleteMessage::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  DeleteMessage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    painter->drawRect(rect());
}
