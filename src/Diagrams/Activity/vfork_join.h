#ifndef VFORK_JOIN_H
#define VFORK_JOIN_H

#include <QObject>
#include "src/Base/baseitem.h"


class VFork_Join: public BaseItem
{
public:
    explicit VFork_Join(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // VFORK_JOIN_H
