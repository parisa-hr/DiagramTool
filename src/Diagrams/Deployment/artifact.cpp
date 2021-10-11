#include "artifact.h"

#include <QPainter>

Artifact::Artifact(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 150, 200));
    setBrush(QColor(240, 255, 255));
}

QRectF  Artifact::boundingRect() const
{
    return rect();
}

QPainterPath  Artifact::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  Artifact::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(brush());
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    QPointF  points[5] = {
        QPointF(0.0,                                                           0.0),
        QPointF((rect().width() - (rect().width() / 5.0)),                     0.0),
        QPointF(rect().width(),                            (rect().height() / 5.0)),
        QPointF(rect().width(),                            rect().height()),
        QPointF(0.0,                                       rect().height())
    };

    painter->drawConvexPolygon(points, 5);

    QPointF  _points[3] = {
        QPointF((rect().width() - rect().width() / 5.0),                   0.0),
        QPointF(rect().width(),                          rect().height() / 5.0),
        QPointF((rect().width() - rect().width() / 5.0), rect().height() / 5.0)
    };
    painter->drawConvexPolygon(_points, 3);
}
