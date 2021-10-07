#ifndef CONTROLITEM_H
#define CONTROLITEM_H

#include <QObject>
#include "src/Base/baseitem.h"


class ControlItem: public BaseItem
{
public:
    explicit ControlItem(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // CONTROLITEM_H
