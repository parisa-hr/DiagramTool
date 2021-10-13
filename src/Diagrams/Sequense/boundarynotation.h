#ifndef BOUNDARYNOTATION_H
#define BOUNDARYNOTATION_H

#include <QObject>

#include <src/Base/baseitem.h>

class BoundaryNotation: public BaseItem
{
public:
    explicit BoundaryNotation(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif // BOUNDARYNOTATION_H
