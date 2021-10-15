#include "actornotation.h"

#include <QPainter>

ActorNotation::ActorNotation(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 100, 600));
    setBrush(QColor(240, 255, 255));
}

QRectF  ActorNotation::boundingRect() const
{
    return rect();
}

QPainterPath  ActorNotation::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  ActorNotation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setStyle(Qt::DashLine);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    painter->save();
    auto  pen2 = QPen(Qt::black, 2);
    pen2.setCosmetic(true);
    painter->setBrush(brush());

    painter->setPen(pen2);

    auto  newRect  = QRect(0, 0, rect().width(), rect().height() / 3);
    auto  headRect = QRect(newRect.width() / 4.0, newRect.height() / 6.0, newRect.width() / 2.0, newRect.width() / 2.0);

    painter->save();
    painter->setBrush(brush());
    painter->drawEllipse(headRect);
    painter->restore();

    painter->drawLine(headRect.width(), headRect.height() + headRect.y(), headRect.width(),
                      (headRect.height() + headRect.y() + (newRect.height() / 4.0)));

    painter->drawLine(headRect.width() / 3.0, headRect.height() + headRect.y() * 2, newRect.width() - (headRect.width() / 3.0),
                      headRect.height() + headRect.y() * 2);

    painter->drawLine(headRect.width(), (headRect.height() + headRect.y() + (newRect.height() / 4.0)), headRect.width() / 3.0,
                      (newRect.height() - headRect.height() / 5.0));
    painter->drawLine(headRect.width(), (headRect.height() + headRect.y() + (newRect.height() / 4.0)), newRect.width() - (headRect.width() / 3.0),
                      (newRect.height() - headRect.height() / 5.0));

// painter->drawRect(0.0, 0.0, rect().width(), rect().height() / 8);

    painter->restore();

    painter->drawLine(rect().width() / 2.0, rect().height() / 3, rect().width() / 2.0, rect().height());
}
