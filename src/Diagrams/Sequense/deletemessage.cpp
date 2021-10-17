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

    auto  _rect1 = QRect(-rect().width() / 10, rect().height() / 5, rect().width() / 5, rect().height());

    painter->save();
    painter->rotate(-45);
    painter->setBrush(Qt::black);
    painter->drawRect(_rect1);
    painter->restore();

    auto  _rect2 = QRect(rect().width() - (2 * (rect().width() / 5)), -(2 * rect().height() / 5) - (rect().height() / 10), rect().width() / 5, rect().height());

    painter->save();
    painter->rotate(45);
    painter->setBrush(Qt::black);
    painter->drawRect(_rect2);
    painter->restore();
}
