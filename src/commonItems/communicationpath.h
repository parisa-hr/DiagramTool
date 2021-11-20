#ifndef COMMUNICATIONPATH_H
#define COMMUNICATIONPATH_H

#include <QGraphicsItem>
#include <QObject>


class CommunicationPath: public QGraphicsItem
{
public:
    explicit CommunicationPath(QPointF startItem, QPointF endItem,
                               QGraphicsItem *parent = nullptr);

    QRectF        boundingRect() const;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPointF  myStartItem;
    QPointF  myEndItem;
};

#endif // COMMUNICATIONPATH_H
