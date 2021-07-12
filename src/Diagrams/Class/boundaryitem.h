#ifndef BOUNDARYITEM_H
#define BOUNDARYITEM_H

#include <QObject>
#include <QGraphicsItem>

class BoundaryItem: public QGraphicsItem
{
    Q_OBJECT

public:
    explicit BoundaryItem(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void          setRect(const QRectF &rect);

private:
    QRectF  _rect = QRectF(0, 0, 200, 100);
};

#endif // BOUNDARYITEM_H
