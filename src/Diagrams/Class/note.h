#ifndef NOTE_H
#define NOTE_H

#include <QObject>
#include <QGraphicsItem>

class Note: public QGraphicsItem
{
public:
    Note(QObject *parent = nullptr);

    QRectF        boundingRect() const override;

    QPainterPath  shape() const override;

    void          paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void          setRect(const QRectF &rect);

private:
    QRectF  _rect = QRectF(0, 0, 200, 150);
};

#endif // NOTE_H
