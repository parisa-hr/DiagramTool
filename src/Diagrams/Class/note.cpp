#include "note.h"

#include <QPainter>
#include <QPen>

Note::Note(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
}

QRectF  Note::boundingRect() const
{
    return _rect;
}

QPainterPath  Note::shape() const
{
    QPainterPath  path;

    path.addRect(_rect);

    return path;
}

void  Note::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    static const QPointF  points[5] = {
        QPointF(0.0,                                                    0.0),
        QPointF((_rect.width() - _rect.width() / 5.0),                  0.0),
        QPointF(_rect.width(),                         _rect.height() / 5.0),
        QPointF(_rect.width(),                         _rect.height()),
        QPointF(0.0,                                   _rect.height())
    };

    painter->drawConvexPolygon(points, 5);

    static const QPointF  _points[3] = {
        QPointF((_rect.width() - _rect.width() / 5.0),                  0.0),
        QPointF(_rect.width(),                         _rect.height() / 5.0),
        QPointF((_rect.width() - _rect.width() / 5.0), _rect.height() / 5.0)
    };
    painter->drawConvexPolygon(_points, 3);
}

void  Note::setRect(const QRectF &rect)
{
    _rect = rect;
}
