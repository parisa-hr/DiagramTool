#ifndef BOUNDARYITEM_H
#define BOUNDARYITEM_H

#include <QObject>
#include "src/Base/baseitem.h"

class BoundaryItem: public BaseItem
{
public:
    explicit BoundaryItem(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // BOUNDARYITEM_H
