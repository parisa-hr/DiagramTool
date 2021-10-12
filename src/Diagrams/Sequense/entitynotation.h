#ifndef ENTITYNOTATION_H
#define ENTITYNOTATION_H

#include <src/Base/baseitem.h>


class EntityNotation: public BaseItem
{
public:
    explicit EntityNotation(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ENTITYNOTATION_H
