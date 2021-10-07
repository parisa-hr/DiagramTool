#ifndef STARTNODE_H
#define STARTNODE_H

#include <QObject>
#include "src/Base/baseitem.h"

class StartNode: public BaseItem
{
public:
    explicit StartNode(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif // STARTNODE_H
