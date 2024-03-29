#ifndef DIRECTASSOSIATION_H
#define DIRECTASSOSIATION_H

#include <QObject>

#include "src/Base/baseitem.h"

class DirectAssosiation: public BaseItem
{
public:
    explicit DirectAssosiation(QPointF startItem, QPointF endItem,
                               QGraphicsItem *parent = nullptr);

    QRectF        boundingRect() const;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void          setMyColor(const QColor &value);

private:
    QPointF    myStartItem;
    QPointF    myEndItem;
    QPolygonF  arrowHead;
    QColor     myColor = Qt::black;
};

#endif // DIRECTASSOSIATION_H
