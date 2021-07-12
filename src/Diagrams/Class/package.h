#ifndef PACKAGE_H
#define PACKAGE_H

#include <QGraphicsItem>

class Package: public QGraphicsItem
{
public:
    Package();

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void          setRect(const QRectF &rect);

private:
    QRectF  _rect = QRectF(0, 0, 200, 100);
};

#endif // PACKAGE_H
