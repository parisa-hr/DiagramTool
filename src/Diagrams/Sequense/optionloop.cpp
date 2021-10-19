#include "optionloop.h"

#include <QPainter>

OptionLoop::OptionLoop(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
}

QRectF  OptionLoop::boundingRect() const
{
    return rect();
}

QPainterPath  OptionLoop::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  OptionLoop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    painter->drawRect(rect());

    painter->save();
    painter->setBrush(brush());

    QPointF  points[6] = {
        QPointF(0.0,                                    0.0),
        QPointF(rect().width() / 3,                     0.0),
        QPointF(rect().width() / 3, (rect().height() / 5.0)),
        QPointF(rect().width() / 4, rect().height() / 3),
        QPointF(0.0,                rect().height() / 3),
        QPointF(0.0, 0.0)
    };
    painter->drawPolyline(points, 6);

    painter->restore();
}
