#include "actor.h"

#include <QPainter>

Actor::Actor(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 100, 200));
}

QRectF  Actor::boundingRect() const
{
    return rect();
}

QPainterPath  Actor::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  Actor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    auto  headRect = QRect(rect().width() / 4.0, rect().height() / 6.0, rect().width() / 2.0, rect().width() / 2.0);

    painter->save();
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(headRect);
    painter->restore();

    painter->drawLine(headRect.width(), headRect.height() + headRect.y(), headRect.width(),
                      (headRect.height() + headRect.y() + (rect().height() / 4.0)));

    painter->drawLine(headRect.width() / 3.0, headRect.height() + headRect.y() * 2, rect().width() - (headRect.width() / 3.0),
                      headRect.height() + headRect.y() * 2);

    painter->drawLine(headRect.width(), (headRect.height() + headRect.y() + (rect().height() / 4.0)), headRect.width() / 3.0,
                      (rect().height() - headRect.height() / 5.0));
    painter->drawLine(headRect.width(), (headRect.height() + headRect.y() + (rect().height() / 4.0)), rect().width() - (headRect.width() / 3.0),
                      (rect().height() - headRect.height() / 5.0));
}
