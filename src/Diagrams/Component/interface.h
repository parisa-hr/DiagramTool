#ifndef INTERFACE_H
#define INTERFACE_H

#include <src/Base/baseitem.h>


class Interface: public BaseItem
{
public:
    explicit Interface(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif // INTERFACE_H
