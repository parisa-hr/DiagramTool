#ifndef NOTE_H
#define NOTE_H

#include <QGraphicsItem>

class Note: public QGraphicsItem
{
public:
    Note();

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void          setRect(const QRectF &rect);

private:
    QRectF  _rect = QRectF(0, 0, 200, 100);
};

#endif // NOTE_H
