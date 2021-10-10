#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include "src/Base/baseitem.h"

class Database: public BaseItem
{
public:
    explicit Database(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // DATABASE_H
