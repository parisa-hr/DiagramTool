#include "handlerstrategies.h"

void HandlerStrategy::solveConstraints(QPointF offset, QSizeF minSize, QRectF &targetRect, PointPosition pos) const
{
    if (mNext != nullptr)
    {
        mNext->solveConstraints(offset, minSize, targetRect, pos);
    }
}

void HandlerStrategy::alignPosition(const QRectF &targetRect, QPointF &position)
{
    if (mNext != nullptr)
    {
        mNext->alignPosition(targetRect, position);
    }
}

HandlerStrategy::~HandlerStrategy()
{
    delete mNext;
    mNext = nullptr;
}

void TopHandlerStrategy::solveConstraints(QPointF offset, QSizeF minSize, QRectF &targetRect, PointPosition pos) const
{
    if (offset.y() >= 0 || !pos.yBelow())
    {
        qreal height = targetRect.height() - offset.y();
        if (minSize.height() > height)
        {
            offset.ry() -= minSize.height() - height;
        }
        targetRect.adjust(0, offset.y(), 0, 0);
    }

    HandlerStrategy::solveConstraints(offset, minSize, targetRect, pos);
}

void TopHandlerStrategy::alignPosition(const QRectF &targetRect, QPointF &position)
{
    position.setY(0);
    HandlerStrategy::alignPosition(targetRect, position);
}


void BottomHandlerStrategy::solveConstraints(QPointF offset, QSizeF minSize, QRectF &targetRect, PointPosition pos) const
{
    if (offset.y() < 0 || !pos.yAbove())
    {
        qreal height = targetRect.height() + offset.y();
        if (minSize.height() > height)
        {
            offset.ry() += minSize.height() - height;
        }
        targetRect.adjust(0, 0, 0, offset.y());
    }

    HandlerStrategy::solveConstraints(offset, minSize, targetRect, pos);
}

void BottomHandlerStrategy::alignPosition(const QRectF &targetRect, QPointF &position)
{
    position.setY(targetRect.bottom());
    HandlerStrategy::alignPosition(targetRect, position);
}


void LeftHandlerStrategy::solveConstraints(QPointF offset, QSizeF minSize, QRectF &targetRect, PointPosition pos) const
{
    if (offset.x() >= 0 || !pos.xToTheRight())
    {
        qreal width = targetRect.width() - offset.x();
        if (minSize.width() > width)
        {
            offset.rx() -= minSize.width() - width;
        }
        targetRect.adjust(offset.x(), 0, 0, 0);
    }

    HandlerStrategy::solveConstraints(offset, minSize, targetRect, pos);
}

void LeftHandlerStrategy::alignPosition(const QRectF &targetRect, QPointF &position)
{
    position.setX(0);
    HandlerStrategy::alignPosition(targetRect, position);
}


void RightHandlerStrategy::solveConstraints(QPointF offset, QSizeF minSize, QRectF &targetRect, PointPosition pos) const
{
    if (offset.x() < 0 || !pos.xToTheLeft())
    {
        qreal width = targetRect.width() + offset.x();
        if (minSize.width() > width)
        {
            offset.rx() += minSize.width() - width;
        }
        targetRect.adjust(0, 0, offset.x(), 0);
    }

    HandlerStrategy::solveConstraints(offset, minSize, targetRect, pos);
}

void RightHandlerStrategy::alignPosition(const QRectF &targetRect, QPointF &position)
{
    position.setX(targetRect.right());
    HandlerStrategy::alignPosition(targetRect, position);
}

HandlerStrategy::PointPosition::PointPosition(const QPointF &p, const QRectF &bounds)
    : mX(getRelation(p.x(), bounds.left(), bounds.right()))
    , mY(getRelation(p.y(), bounds.top(), bounds.bottom()))
{
}

bool HandlerStrategy::PointPosition::xToTheLeft() const
{
    return mX == OutsideBefore;
}

bool HandlerStrategy::PointPosition::xToTheRight() const
{
    return mX == OutsideAfter;
}

bool HandlerStrategy::PointPosition::yAbove() const
{
    return mY == OutsideBefore;
}

bool HandlerStrategy::PointPosition::yBelow() const
{
    return mY == OutsideAfter;
}

HandlerStrategy::PointPosition::Relation HandlerStrategy::PointPosition::getRelation(qreal x, qreal left, qreal right)
{
    if (x < left)
    {
        return OutsideBefore;
    }
    if (x > right)
    {
        return OutsideAfter;
    }
    return Inside;
}
