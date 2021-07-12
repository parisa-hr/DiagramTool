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
    return _rect;
}

QPainterPath  ControlItem::shape() const
{
    QPainterPath  path;

    path.addRect(_rect);

    return path;
}

void  ControlItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    auto  r = QRectF(_rect.width() / 10.0, _rect.height() / 10.0, _rect.width() - (_rect.width() / 10.0) * 2, _rect.height() - (_rect.height() / 10.0) * 2.0);
    painter->drawEllipse(r);

    static const QPointF  _points[3] = {
        QPointF((_rect.width() / 2.0 + _rect.width() / 10.0),                  0.0),
        QPointF(_rect.width() / 2.0,                          _rect.width() / 10.0),
        QPointF((_rect.width() / 2.0 + _rect.width() / 10.0), (_rect.width() / 10.0 + _rect.width() / 10.0))
    };
    painter->drawPolyline(_points, 3);
}

void  ControlItem::setRect(const QRectF &rect)
{
    _rect = rect;
}
