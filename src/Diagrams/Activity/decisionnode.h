#ifndef DECISIONNODE_H
#define DECISIONNODE_H

#include <QObject>
#include <QGraphicsItem>


class DecisionNode: public QGraphicsItem
{
public:
    explicit DecisionNode(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void          setRect(const QRectF &rect);

private:
    QRectF  _rect = QRectF(0, 0, 100, 100);
};

#endif // DECISIONNODE_H
