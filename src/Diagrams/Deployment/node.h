#ifndef NODE_H
#define NODE_H

#include <QObject>

#include <src/Base/baseitem.h>

class Node: public BaseItem
{
public:
    explicit Node(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // NODE_H
