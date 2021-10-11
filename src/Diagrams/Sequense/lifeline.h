#ifndef LIFELINE_H
#define LIFELINE_H

#include <QObject>
#include "src/Base/baseitem.h"

class Lifeline: public BaseItem
{
public:
    explicit Lifeline(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // LIFELINE_H
