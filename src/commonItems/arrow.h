#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>

class QGraphicsItem;

//! [0]
class Arrow: public QGraphicsLineItem
{
public:
    Arrow(QGraphicsItem *startItem, QGraphicsItem *endItem,
          QGraphicsItem *parent = nullptr);

    int  type() const override
    {
        return Type;
    }

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          setColor(const QColor &color)
    {
        myColor = color;
    }

    QGraphicsItem* startItem() const
    {
        return myStartItem;
    }

    QGraphicsItem* endItem() const
    {
        return myEndItem;
    }

    void  updatePosition();

protected:
    void  paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget = nullptr) override;

private:
    QGraphicsItem *myStartItem;
    QGraphicsItem *myEndItem;
    QPolygonF      arrowHead;
    QColor         myColor = Qt::black;
};

//! [0]

#endif // ARROW_H
