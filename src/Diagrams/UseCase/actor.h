#ifndef ACTOR_H
#define ACTOR_H

#include <QObject>
#include <QGraphicsItem>

class Actor: public QGraphicsItem
{
public:
    explicit Actor(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void          setRect(const QRectF &rect);

private:
    QRectF  _rect = QRectF(0, 0, 100, 200);
};

#endif // ACTOR_H
