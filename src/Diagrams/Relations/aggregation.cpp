#include "aggregation.h"

#include <QPainter>
#include <QPen>
#include <QtMath>
#include <QDebug>

Aggregation::Aggregation(QPointF startItem, QPointF endItem, QGraphicsItem *parent):
    myStartItem(startItem), myEndItem(endItem)
{
    setAcceptHoverEvents(true);
    setZValue(105);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF  Aggregation::boundingRect() const
{
    return QRectF(myStartItem, myEndItem);
}

QPainterPath  Aggregation::shape() const
{
    QPainterPath  path;

    path.addRect(boundingRect());

    return path;
}

void  Aggregation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QPen  myPen;

    myPen.setColor(myColor);
    myPen.setWidth(2);
    myPen.setCosmetic(true);
    painter->setPen(myPen);
    painter->setBrush(myColor);

    painter->save();

    painter->setRenderHints(QPainter::Antialiasing);

    painter->setBrush(Qt::NoBrush);

    painter->drawLine(myStartItem, myEndItem);
    painter->restore();

    double   angle   = std::atan2(-(myEndItem.y() - myStartItem.y()), (myEndItem.x() - myStartItem.x()));
    QPointF  arrowP1 = myStartItem + QPointF(sin(angle + M_PI / 3) * 20,
                                             cos(angle + M_PI / 3) * 20);
    QPointF  arrowP2 = myStartItem + QPointF(sin(angle + M_PI - M_PI / 3) * 20,
                                             cos(angle + M_PI - M_PI / 3) * 20);

    arrowHead.clear();

    painter->save();
    painter->setBrush(Qt::white);
    QLineF  tmp(myStartItem, myEndItem);
    tmp.setLength(35);
    auto  test_point = tmp.p2();

    arrowHead << myStartItem << arrowP1 << test_point << arrowP2;
    painter->drawPolygon(arrowHead);
    painter->restore();
}

void  Aggregation::setMyColor(const QColor &value)
{
    myColor = value;
}
