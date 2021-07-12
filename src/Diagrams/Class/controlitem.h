#ifndef CONTROLITEM_H
#define CONTROLITEM_H

#include <QObject>
#include <QGraphicsItem>


class ControlItem: public QGraphicsItem
{
public:
    explicit ControlItem(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void          setRect(const QRectF &rect);

private:
    QRectF  _rect = QRectF(0, 0, 200, 100);
};

#endif // CONTROLITEM_H
