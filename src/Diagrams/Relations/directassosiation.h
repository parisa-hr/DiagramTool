#ifndef DIRECTASSOSIATION_H
#define DIRECTASSOSIATION_H

#include <QObject>

#include "src/Base/baseitem.h"

class DirectAssosiation: public QGraphicsLineItem
{
public:
    explicit DirectAssosiation(BaseItem *startItem, BaseItem *endItem,
                               QGraphicsItem *parent = nullptr);

    QRectF        boundingRect() const;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    BaseItem    * getMyStartItem() const;

    BaseItem    * getMyEndItem() const;

    void          updatePosition();

    void          setMyColor(const QColor &value);

private:
    BaseItem  *myStartItem;
    BaseItem  *myEndItem;
    QPolygonF  arrowHead;
    QColor     myColor = Qt::black;
};

#endif // DIRECTASSOSIATION_H
