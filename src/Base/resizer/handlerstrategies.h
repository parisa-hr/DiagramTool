#ifndef HANDLERSTRATEGIES_H
#define HANDLERSTRATEGIES_H

#include <QPointF>
#include <QRectF>
#include <QSizeF>

class HandlerStrategy
{
public:
    class PointPosition
    {
        enum Relation
        {
            Inside,
            OutsideBefore,
            OutsideAfter
        };
    public:
        PointPosition(const QPointF &p, const QRectF &bounds);
        bool xToTheLeft() const;
        bool xToTheRight() const;
        bool yAbove() const;
        bool yBelow() const;
    private:
        static Relation getRelation(qreal x, qreal left, qreal right);
        Relation mX;
        Relation mY;
    };

    explicit HandlerStrategy(HandlerStrategy *next = nullptr) : mNext(next) { }
    virtual ~HandlerStrategy();

    virtual void solveConstraints(QPointF offset, QSizeF minSize, QRectF &targetRect, PointPosition pos) const;
    virtual void alignPosition(const QRectF &targetRect, QPointF &position);

protected:
    HandlerStrategy *mNext;
};

class TopHandlerStrategy : public HandlerStrategy
{
public:
    explicit TopHandlerStrategy(HandlerStrategy *next = nullptr) : HandlerStrategy(next) { }

    virtual void solveConstraints(QPointF offset, QSizeF minSize, QRectF &targetRect, PointPosition pos) const override;
    virtual void alignPosition(const QRectF &targetRect, QPointF &position) override;
};

class BottomHandlerStrategy : public HandlerStrategy
{
public:
    explicit BottomHandlerStrategy(HandlerStrategy *next = nullptr) : HandlerStrategy(next) { }

    virtual void solveConstraints(QPointF offset, QSizeF minSize, QRectF &targetRect, PointPosition pos) const override;
    virtual void alignPosition(const QRectF &targetRect, QPointF &position) override;
};

class LeftHandlerStrategy : public HandlerStrategy
{
public:
    explicit LeftHandlerStrategy(HandlerStrategy *next = nullptr) : HandlerStrategy(next) { }

    virtual void solveConstraints(QPointF offset, QSizeF minSize, QRectF &targetRect, PointPosition pos) const override;
    virtual void alignPosition(const QRectF &targetRect, QPointF &position) override;
};

class RightHandlerStrategy : public HandlerStrategy
{
public:
    explicit RightHandlerStrategy(HandlerStrategy *next = nullptr) : HandlerStrategy(next) { }

    virtual void solveConstraints(QPointF offset, QSizeF minSize, QRectF &targetRect, PointPosition pos) const override;
    virtual void alignPosition(const QRectF &targetRect, QPointF &position) override;
};

#endif // HANDLERSTRATEGIES_H
