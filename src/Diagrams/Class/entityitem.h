#ifndef ENTITYITEM_H
#define ENTITYITEM_H

#include <QObject>
#include "src/Base/baseitem.h"


class EntityItem: public BaseItem
{
public:
    explicit EntityItem(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ENTITYITEM_H
