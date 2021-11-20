#include "dasharrow.h"
#include <QPainter>
#include <QPen>
#include <QtMath>

DashArrow::DashArrow(QPointF startItem, QPointF endItem, QGraphicsItem *parent):
    myStartItem(startItem), myEndItem(endItem)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF  DashArrow::boundingRect() const
{
    return QRectF(myStartItem, myEndItem);
}

QPainterPath  DashArrow::shape() const
{
    QPainterPath  path;

    path.addRect(boundingRect());

    return path;
}

void  DashArrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
    painter->setPen(QPen(myColor, 1, Qt::DashLine));

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

void  DashArrow::setMyColor(const QColor &value)
{
    myColor = value;
}
