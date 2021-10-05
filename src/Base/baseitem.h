#ifndef BASEITEM_H
#define BASEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QBrush>

class BaseItem: public QGraphicsItem
{
public:
    explicit BaseItem(QObject *parent = nullptr);

    QRectF  rect() const;

    void    setRect(const QRectF &rect);

    QBrush  brush() const;

    void    setBrush(const QBrush &brush);

    QColor  color() const;

    void    setColor(const QColor &color);

private:
    QRectF  _rect  = QRectF(0, 0, 100, 100);
    QBrush  _brush = Qt::yellow;
    QColor  _color;
};

#endif // BASEITEM_H
