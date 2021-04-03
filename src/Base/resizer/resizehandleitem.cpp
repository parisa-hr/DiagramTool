#include "resizehandleitem.h"
#include "handlerstrategies.h"

#include <QBrush>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>

QHash<int, QWeakPointer<HandlerStrategy>> GraphicsItemResizer::HandleItem::Strategies;

GraphicsItemResizer::HandleItem::HandleItem(int attachmentFlags, const QRectF &rect, GraphicsItemResizer *resizer)
    : QGraphicsRectItem(rect, resizer)
    , mResizer(resizer)
    , mHandleMoveAsResize(false)
{
    mAttachmentFlags = cleanAttachment(attachmentFlags);

    setFlag(ItemIsSelectable);
    setAcceptedMouseButtons(Qt::LeftButton);

    setBrush(QBrush(Qt::black));
    setCursor(getCursor(mAttachmentFlags));

    mStrategy = getStrategy(mAttachmentFlags);
}

void GraphicsItemResizer::HandleItem::targetRectChanged(const QRectF &targetRect)
{
    QSizeF halfSize = rect().size() / 2.0f;
    QPointF newPos = targetRect.center() - QPointF(halfSize.width(), halfSize.height());
    mStrategy->alignPosition(targetRect, newPos);
    setPos(newPos);
}

GraphicsItemResizer *GraphicsItemResizer::HandleItem::resizer() const
{
    return mResizer;
}

int GraphicsItemResizer::HandleItem::cleanAttachment(int attachment)
{
    Q_ASSERT(attachment != 0);
    int valid = 0;
    if (attachment & Left)
    {
        valid |= Left;
    }
    else if (attachment & Right)
    {
        valid |= Right;
    }

    // Vertical
    if (attachment & Top)
    {
        valid |= Top;
    }
    else if (attachment & Bottom)
    {
        valid |= Bottom;
    }
    Q_ASSERT(valid != 0);
    return valid;
}

Qt::CursorShape GraphicsItemResizer::HandleItem::getCursor(int attachment)
{
    static int HorizontalMask = Left | Right;
    static int VerticalMask = Top | Bottom;

    if ((attachment & VerticalMask) == 0)
    {
        return Qt::SizeHorCursor;
    }
    if ((attachment & HorizontalMask) == 0)
    {
        return Qt::SizeVerCursor;
    }

    if (attachment == (Left | Top) || attachment == (Right | Bottom))
    {
        return Qt::SizeFDiagCursor;
    }

    return Qt::SizeBDiagCursor;
}

QSharedPointer<HandlerStrategy> GraphicsItemResizer::HandleItem::getStrategy(int attachment)
{
    if (attachment == 0)
    {
        return HandlerStrategyPointer();
    }

    QWeakPointer<HandlerStrategy> &weak = Strategies[attachment];
    HandlerStrategyPointer strategy = weak.toStrongRef();
    if (strategy.isNull())
    {
        HandlerStrategy *s = nullptr;
        // Horizontal
        if (attachment & Left)
        {
            s = new LeftHandlerStrategy();
        }
        else if (attachment & Right)
        {
            s = new RightHandlerStrategy();
        }

        // Vertical
        if (attachment & Top)
        {
            s = new TopHandlerStrategy(s);
        }
        else if (attachment & Bottom)
        {
            s = new BottomHandlerStrategy(s);
        }
        Q_ASSERT(s != nullptr);
        strategy.reset(s);
        weak = strategy;
    }

    return strategy;
}


void GraphicsItemResizer::HandleItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    mHandleMoveAsResize = true;
    event->accept();
}

void GraphicsItemResizer::HandleItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (!mHandleMoveAsResize)
    {
        event->ignore();
        return;
    }
    QPointF mousePos = event->pos();
    QPointF offset = mousePos - event->lastPos();
    QRectF targetRect(QPointF(), resizer()->targetSize());
    QSizeF minSize = resizer()->minSize();
    QRectF bounds = boundingRect();
    HandlerStrategy::PointPosition p = HandlerStrategy::PointPosition(mousePos, bounds);

    mStrategy->solveConstraints(offset, minSize, targetRect, p);

    resizer()->updateTargetRect(targetRect);
}

void GraphicsItemResizer::HandleItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    event->setAccepted(mHandleMoveAsResize);
    mHandleMoveAsResize = false;
}
