#include "lifeline.h"

#include <QPainter>

Lifeline::Lifeline(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 600));
}

QRectF  Lifeline::boundingRect() const
{
    return rect();
}

QPainterPath  Lifeline::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  Lifeline::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

    painter->drawRect(0.0, 0.0, rect().width(), rect().height() / 10);

    painter->restore();

    painter->drawLine(rect().width() / 2.0, rect().height() / 10, rect().width() / 2.0, rect().height());
}
