#ifndef ACTIVATIONOCCURRENCE_H
#define ACTIVATIONOCCURRENCE_H

#include <QObject>

#include <src/Base/baseitem.h>

class ActivationOccurrence: public BaseItem
{
public:
    explicit ActivationOccurrence(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ACTIVATIONOCCURRENCE_H
