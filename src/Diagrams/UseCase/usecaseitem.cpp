#include "usecaseitem.h"

#include <QColor>
#include <QPen>
#include <QPainter>

UseCaseItem::UseCaseItem(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
    setBrush(Qt::cyan);
}

QRectF  UseCaseItem::boundingRect() const
{
    return rect();
}

QPainterPath  UseCaseItem::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  UseCaseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setPen(pen);

    painter->setBrush(brush());

    painter->drawEllipse(rect());
}
