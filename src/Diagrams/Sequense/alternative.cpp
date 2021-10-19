#include "alternative.h"

#include <QPainter>

Alternative::Alternative(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
}

QRectF  Alternative::boundingRect() const
{
    return rect();
}

QPainterPath  Alternative::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  Alternative::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
        QPointF(0.0,                                      0.0),
        QPointF(rect().width() / 3.5,                     0.0),
        QPointF(rect().width() / 3.5, (rect().height() / 6.0)),
        QPointF(rect().width() / 4,   rect().height() / 4),
        QPointF(0.0,                  rect().height() / 4),
        QPointF(0.0, 0.0)
    };
    painter->drawPolyline(points, 6);

    painter->restore();

    painter->save();
    auto  pen2 = QPen(Qt::black, 2);
    pen2.setCosmetic(true);
    pen2.setStyle(Qt::DashLine);
    painter->setPen(pen2);

    painter->drawLine(0.0, rect().height() / 2, rect().width(), rect().height() / 2);

    painter->restore();
}
