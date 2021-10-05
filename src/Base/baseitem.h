#ifndef BASEITEM_H
#define BASEITEM_H

#include <QObject>
#include <QGraphicsItem>

class BaseItem: public QGraphicsItem
{
public:
    explicit BaseItem(QObject *parent = nullptr);

    QRectF  rect() const;

    void    setRect(const QRectF &rect);

private:
    QRectF  _rect = QRectF(0, 0, 100, 100);
};

#endif // BASEITEM_H
