#include "database.h"

#include <QPainter>

Database::Database(QObject *parent)
{
    setAcceptHoverEvents(true);
    setZValue(101);
    setRect(QRect(0, 0, 130, 200));
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
    painter->setPen(pen);
    painter->setBrush(brush());

    painter->drawLine(0.0, rect().height() / 10.0, 0.0, (rect().height() - rect().height() / 10.0));
    painter->drawLine(rect().width(), rect().height() / 10.0, rect().width(), (rect().height() - rect().height() / 10.0));

    painter->drawArc(0.0, (rect().height() - rect().height() / 5.0), rect().width(), rect().height() / 5.0, -180 * 16, 180 * 16);

    painter->drawEllipse(0.0, 0.0, rect().width(), rect().height() / 5.0);
}
