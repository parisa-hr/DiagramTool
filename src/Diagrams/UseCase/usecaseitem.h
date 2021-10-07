#ifndef USECASEOBJ_H
#define USECASEOBJ_H

#include <QObject>
#include "src/Base/baseitem.h"


class UseCaseItem: public BaseItem
{
public:
    explicit UseCaseItem(QObject *parent = nullptr);

public:
    QRectF        boundingRect() const;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // USECASEOBJ_H
