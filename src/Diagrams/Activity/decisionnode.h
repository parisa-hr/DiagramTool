#ifndef DECISIONNODE_H
#define DECISIONNODE_H

#include <QObject>
#include "src/Base/baseitem.h"


class DecisionNode: public BaseItem
{
public:
    explicit DecisionNode(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // DECISIONNODE_H
