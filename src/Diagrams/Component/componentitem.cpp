#include "componentitem.h"

#include <QPainter>

ComponentItem::ComponentItem(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
    setBrush(QColor(240, 255, 255));
}

QRectF  ComponentItem::boundingRect() const
{
    return rect();
}

QPainterPath  ComponentItem::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  ComponentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);

    painter->setPen(pen);

    auto  baseRect = QRect(rect().width() / 6.0, rect().height() / 4.8, rect().width() / 1.3, rect().height() / 1.6);

    painter->save();
    painter->setBrush(brush());
    painter->drawRect(baseRect);
    painter->restore();

    auto  rect1 = QRect(rect().width() / 10.0, rect().height() / 3.0, rect().width() / 6, rect().height() / 8.0);
    painter->save();
    painter->setBrush(brush());
    painter->drawRect(rect1);
    painter->restore();

    auto  rect2 = QRect(rect().width() / 10.0, rect().height() / 1.8, rect().width() / 6, rect().height() / 8.0);

    painter->save();
    painter->setBrush(brush());
    painter->drawRect(rect2);
    painter->restore();
}
