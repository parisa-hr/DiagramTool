#ifndef DASHARROW_H
#define DASHARROW_H

#include <QGraphicsItem>
#include <QObject>

class DashArrow: public QGraphicsItem
{
public:
    explicit DashArrow(QPointF startItem, QPointF endItem,
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


#endif // DASHARROW_H
