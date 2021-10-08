#ifndef PROVIDEDINTERFACE_H
#define PROVIDEDINTERFACE_H

#include <src/Base/baseitem.h>


class ProvidedInterface: public BaseItem
{
public:
    explicit ProvidedInterface(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif // PROVIDEDINTERFACE_H
