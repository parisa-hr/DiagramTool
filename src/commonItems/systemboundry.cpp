#include "systemboundry.h"

#include <QGraphicsItem>
#include <QColor>
#include <QPen>
#include <QPainter>

SystemBoundry::SystemBoundry(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 500, 600));
    setBrush(Qt::lightGray);
}

QRectF  SystemBoundry::boundingRect() const
{
    return rect();
}

QPainterPath  SystemBoundry::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  SystemBoundry::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setPen(pen);

    painter->setBrush(brush());
    painter->setOpacity(0.50);

    painter->drawRect(rect());
}
