#ifndef OPTIONLOOP_H
#define OPTIONLOOP_H

#include <QObject>

#include <src/Base/baseitem.h>

class OptionLoop: public BaseItem
{
public:
    explicit OptionLoop(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // OPTIONLOOP_H
