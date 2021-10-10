#include "database.h"

#include <QPainter>

Database::Database(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 200, 100));
    setBrush(QColor(240, 255, 255));
}

QRectF  Database::boundingRect() const
{
    return rect();
}

QPainterPath  Database::shape() const
{
    QPainterPath  path;

    path.addRect(rect());

    return path;
}

void  Database::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing);
    auto  pen = QPen(Qt::black, 2);
    pen.setCosmetic(true);
    painter->setBrush(Qt::NoBrush);
}
