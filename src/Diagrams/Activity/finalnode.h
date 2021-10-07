#ifndef FINALNODE_H
#define FINALNODE_H

#include <QObject>
#include "src/Base/baseitem.h"

class FinalNode: public BaseItem
{
public:
    explicit FinalNode(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // FINALNODE_H
