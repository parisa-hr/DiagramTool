#ifndef CLASSITEM_H
#define CLASSITEM_H

#include <QObject>
#include "src/Base/baseitem.h"

class classItem: public BaseItem
{
public:
    explicit classItem(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // CLASSITEM_H
