#ifndef REQUIREDINTERFACE_H
#define REQUIREDINTERFACE_H

#include <QObject>
#include <src/Base/baseitem.h>

class RequiredInterface: public BaseItem
{
public:
    explicit RequiredInterface(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // REQUIREDINTERFACE_H
