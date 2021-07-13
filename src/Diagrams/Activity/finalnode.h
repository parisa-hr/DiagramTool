#ifndef FINALNODE_H
#define FINALNODE_H

#include <QObject>
#include <QGraphicsItem>

class FinalNode: public QGraphicsItem
{
public:
    explicit FinalNode(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void          setRect(const QRectF &rect);

private:
    QRectF  _rect = QRectF(0, 0, 100, 100);
};

#endif // FINALNODE_H
