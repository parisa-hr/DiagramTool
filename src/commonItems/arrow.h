#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsItem>
#include <QObject>


class Arrow: public QGraphicsItem
{
public:
    explicit Arrow(QPointF startItem, QPointF endItem,
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

#endif // ARROW_H
