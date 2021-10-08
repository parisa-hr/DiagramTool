#ifndef PORT_H
#define PORT_H

#include <src/Base/baseitem.h>


class Port: public BaseItem
{
public:
    explicit Port(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // PORT_H
