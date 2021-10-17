#ifndef ALTERNATIVE_H
#define ALTERNATIVE_H

#include <QObject>
#include <src/Base/baseitem.h>

class Alternative: public BaseItem
{
public:
    explicit Alternative(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif // ALTERNATIVE_H
