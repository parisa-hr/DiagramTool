#include "communicationpath.h"
#include <QPainter>
#include <QPen>

CommunicationPath::CommunicationPath(QPointF startItem, QPointF endItem, QGraphicsItem *parent):
    myStartItem(startItem), myEndItem(endItem)
{
    setAcceptHoverEvents(true);
    setZValue(105);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF  CommunicationPath::boundingRect() const
{
    return QRectF(myStartItem, myEndItem);
}

QPainterPath  CommunicationPath::shape() const
{
    QPainterPath  path;

    path.addRect(boundingRect());

    return path;
}

void  CommunicationPath::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QPen  myPen;

    myPen.setColor(Qt::black);
    myPen.setWidth(2);
    myPen.setCosmetic(true);
    painter->setPen(myPen);
    painter->drawLine(myStartItem, myEndItem);
}
