#ifndef PACKAGE_H
#define PACKAGE_H

#include <QGraphicsItem>
#include "src/Base/baseitem.h"

class Package: public BaseItem
{
public:
    Package();

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // PACKAGE_H
