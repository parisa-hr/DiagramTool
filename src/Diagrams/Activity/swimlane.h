#ifndef SWIMLANE_H
#define SWIMLANE_H

#include <QMenu>
#include <QObject>
#include "src/Base/baseitem.h"


class Swimlane: public BaseItem
{
public:
    explicit Swimlane(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void          insert();
};

#endif // SWIMLANE_H
