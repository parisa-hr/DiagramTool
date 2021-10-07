#include "controlitem.h"
#include <QPainter>
#include <QPen>

ControlItem::ControlItem(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
}

QRectF  ControlItem::boundingRect() const
{
    return rect();
}

QPainterPath  ControlItem::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  ControlItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(brush());
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    auto  r =
        QRectF(rect().width() / 10.0, rect().height() / 10.0, rect().width() - (rect().width() / 10.0) * 2, rect().height() - (rect().height() / 10.0) * 2.0);
    painter->drawEllipse(r);

    QPointF  _points[3] = {
        QPointF((rect().width() / 2.0 + rect().width() / 10.0),                                             0.0),
        QPointF(rect().width() / 2.0,                           rect().width() / 10.0),
        QPointF((rect().width() / 2.0 + rect().width() / 10.0), (rect().width() / 10.0 + rect().width() / 10.0))
    };
    painter->drawPolyline(_points, 3);
}
