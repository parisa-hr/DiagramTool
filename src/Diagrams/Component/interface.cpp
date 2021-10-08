#include "interface.h"

#include <QPainter>

Interface::Interface(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
    setBrush(QColor(240, 255, 255));
}

QRectF  Interface::boundingRect() const
{
    return rect();
}

QPainterPath  Interface::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  Interface::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setPen(pen);
    painter->setBrush(brush());
    painter->drawRect(rect());
}
