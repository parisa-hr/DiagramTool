#ifndef ACTOR_H
#define ACTOR_H

#include <QObject>

#include "src/Base/baseitem.h"

class Actor: public BaseItem
{
public:
    explicit Actor(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ACTOR_H
