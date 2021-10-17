#ifndef DELETEMESSAGE_H
#define DELETEMESSAGE_H

#include <QObject>
#include "src/Base/baseitem.h"

class DeleteMessage: public BaseItem
{
public:
    explicit DeleteMessage(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // DELETEMESSAGE_H
