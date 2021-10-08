#ifndef COMPONENTITEM_H
#define COMPONENTITEM_H

#include <QObject>
#include "src/Base/baseitem.h"

class ComponentItem: public BaseItem
{
public:
    explicit ComponentItem(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // COMPONENTITEM_H
