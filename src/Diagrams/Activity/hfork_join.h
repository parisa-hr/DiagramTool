#ifndef HFORK_JOIN_H
#define HFORK_JOIN_H

#include <QObject>
#include "src/Base/baseitem.h"


class HFork_Join: public BaseItem
{
public:
    explicit HFork_Join(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // HFORK_JOIN_H
