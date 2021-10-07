#ifndef NOTE_H
#define NOTE_H

#include <QObject>
#include "src/Base/baseitem.h"

class Note: public BaseItem
{
public:
    Note(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // NOTE_H
