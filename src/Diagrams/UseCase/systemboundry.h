#ifndef SYSTEMBOUNDRY_H
#define SYSTEMBOUNDRY_H

#include <QObject>
#include "src/Base/baseitem.h"


class SystemBoundry: public BaseItem
{
public:
    explicit SystemBoundry(QObject *parent = nullptr);

public:
    QRectF        boundingRect() const;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SYSTEMBOUNDRY_H
