#ifndef ENTITYITEM_H
#define ENTITYITEM_H

#include <QObject>
#include <QGraphicsItem>


class EntityItem: public QGraphicsItem
{
public:
    explicit EntityItem(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void          setRect(const QRectF &rect);

private:
    QRectF  _rect = QRectF(0, 0, 100, 100);
};

#endif // ENTITYITEM_H
