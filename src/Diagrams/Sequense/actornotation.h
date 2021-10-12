#ifndef ACTORNOTATION_H
#define ACTORNOTATION_H

#include <QObject>

#include <src/Base/baseitem.h>

class ActorNotation: public BaseItem
{
public:
    explicit ActorNotation(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif // ACTORNOTATION_H
