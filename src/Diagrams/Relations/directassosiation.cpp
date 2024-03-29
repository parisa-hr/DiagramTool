#include "directassosiation.h"

#include <QPainter>
#include <QPen>
#include <QtMath>

DirectAssosiation::DirectAssosiation(QPointF startItem, QPointF endItem, QGraphicsItem *parent):
    myStartItem(startItem), myEndItem(endItem)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF  DirectAssosiation::boundingRect() const
{
    return QRectF(myStartItem, myEndItem);
}

QPainterPath  DirectAssosiation::shape() const
{
    QPainterPath  path;

    path.addRect(boundingRect());

    return path;
}

void  DirectAssosiation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
    arrowHead << myStartItem << arrowP1 << arrowP2;
    painter->drawPolygon(arrowHead);
}

void  DirectAssosiation::setMyColor(const QColor &value)
{
    myColor = value;
}
