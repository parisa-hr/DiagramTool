#include "graphicsitemresizer.h"

#include "resizehandleitem.h"

#include <QPainter>


static QSizeF handleSize = QSizeF(6, 6);
static QMarginsF handleBounds = QMarginsF(handleSize.width(), handleSize.height(), handleSize.width(), handleSize.height());

GraphicsItemResizer::GraphicsItemResizer(QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , mTargetSize(0, 0)
    , mMinSize(0, 0)
{
    static QRectF handleRect(QPointF(), handleSize);

    setFlag(ItemHasNoContents);

    // sides
    mHandleItems.append(new HandleItem(HandleItem::Left, handleRect, this));
    mHandleItems.append(new HandleItem(HandleItem::Top, handleRect, this));
    mHandleItems.append(new HandleItem(HandleItem::Right, handleRect, this));
    mHandleItems.append(new HandleItem(HandleItem::Bottom, handleRect, this));
    // corners
    mHandleItems.append(new HandleItem(HandleItem::Top | HandleItem::Left, handleRect, this));
    mHandleItems.append(new HandleItem(HandleItem::Top | HandleItem::Right, handleRect, this));
    mHandleItems.append(new HandleItem(HandleItem::Bottom | HandleItem::Right, handleRect, this));
    mHandleItems.append(new HandleItem(HandleItem::Bottom | HandleItem::Left, handleRect, this));
}

GraphicsItemResizer::~GraphicsItemResizer()
{
}

QRectF GraphicsItemResizer::boundingRect() const
{
    return mBounds;
}

void GraphicsItemResizer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPen p(Qt::gray, 1, Qt::DashLine);
    painter->setPen(p);
    painter->drawRect(mBounds - handleBounds);
}

void GraphicsItemResizer::setPen(const QPen &pen)
{
    mPen = pen;
    for (HandleItem *i : mHandleItems)
    {
        i->setPen(pen);
    }
}

void GraphicsItemResizer::setBrush(const QBrush &brush)
{
    mBrush = brush;
    for (HandleItem *i : mHandleItems)
    {
        i->setBrush(brush);
    }
}

void GraphicsItemResizer::setTargetSize(const QSizeF &size)
{
    if (size == targetSize())
    {
        return;
    }
    updateDimensions(size);
}

void GraphicsItemResizer::setMinSize(const QSizeF &minSize)
{
    mMinSize = minSize;
}

void GraphicsItemResizer::updateHandleItemPositions()
{
    QRectF innerRect = mBounds - handleBounds;
    for (HandleItem *i : mHandleItems)
    {
        i->targetRectChanged(innerRect);
    }
}

void GraphicsItemResizer::updateTargetRect(const QRectF &rect)
{
    if (rect.size() == targetSize())
    {
        return;
    }
    updateDimensions(rect.size());
    emit targetRectChanged(rect);
}


void GraphicsItemResizer::updateDimensions(QSizeF newSize)
{
    prepareGeometryChange();
    mTargetSize = newSize;
    QRectF rect = QRectF(QPointF(), newSize) + handleBounds;
    setPos(rect.topLeft());
    mBounds = QRectF(QPointF(), rect.size());
    updateHandleItemPositions();
}
