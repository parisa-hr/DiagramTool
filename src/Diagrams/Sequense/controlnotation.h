#ifndef CONTROLNOTATION_H
#define CONTROLNOTATION_H

#include <QObject>

#include <src/Base/baseitem.h>

class ControlNotation: public BaseItem
{
public:
    explicit ControlNotation(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif // CONTROLNOTATION_H
