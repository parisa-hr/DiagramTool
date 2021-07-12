#ifndef CLASSITEM_H
#define CLASSITEM_H

#include <QObject>
#include <QGraphicsItem>

class classItem: public QGraphicsItem
{
public:
    explicit classItem(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void          setRect(const QRectF &rect);

private:
    QRectF  _rect = QRectF(0, 0, 200, 100);
};

#endif // CLASSITEM_H
