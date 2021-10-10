#ifndef ARTIFACT_H
#define ARTIFACT_H

#include <QObject>
#include "src/Base/baseitem.h"

class Artifact: public BaseItem
{
public:
    explicit Artifact(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ARTIFACT_H
