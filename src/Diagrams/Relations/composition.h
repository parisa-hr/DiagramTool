#ifndef COMPOSITION_H
#define COMPOSITION_H

#include <QObject>
#include <QGraphicsItem>

class Composition: public QGraphicsItem
{
public:
    explicit Composition(QPointF startItem, QPointF endItem,
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

#endif // COMPOSITION_H
