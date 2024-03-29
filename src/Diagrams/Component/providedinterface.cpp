#include "providedinterface.h"

#include <QPainter>

ProvidedInterface::ProvidedInterface(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 50, 50));
    setBrush(QColor(240, 255, 255));
}

QRectF  ProvidedInterface::boundingRect() const
{
    return rect();
}

QPainterPath  ProvidedInterface::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  ProvidedInterface::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);

    painter->setPen(pen);
    painter->save();
    painter->setBrush(brush());
    painter->drawEllipse(rect());
    painter->restore();
}
