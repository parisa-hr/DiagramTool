#ifndef PACKAGE_H
#define PACKAGE_H

#include <QObject>
#include "src/Base/baseitem.h"

class Package: public BaseItem
{
public:
    explicit Package(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // PACKAGE_H
