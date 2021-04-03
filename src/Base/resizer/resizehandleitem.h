#ifndef RESIZEHANDLEITEM_H
#define RESIZEHANDLEITEM_H

#include "graphicsitemresizer.h"

#include <QGraphicsRectItem>

class HandlerStrategy;
class GraphicsItemResizer::HandleItem : public QGraphicsRectItem
{
    typedef QSharedPointer<HandlerStrategy> HandlerStrategyPointer;

public:
    enum AttachmentFlags
    {
        Left = 0x1,
        Top = 0x2,
        Bottom = 0x4,
        Right = 0x8
    };

    explicit HandleItem(int attachmentFlags, const QRectF &rect, GraphicsItemResizer *resizer);

    int attachmentFlags() const
    {
        return mAttachmentFlags;
    }

    void targetRectChanged(const QRectF &targetRect);

    // QGraphicsItem interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    GraphicsItemResizer *resizer() const;

    GraphicsItemResizer *mResizer;
    int mAttachmentFlags;
    bool mHandleMoveAsResize;
    HandlerStrategyPointer mStrategy;

    static int cleanAttachment(int attachment);
    static Qt::CursorShape getCursor(int attachment);
    static HandlerStrategyPointer getStrategy(int attachment);
    static QHash<int, QWeakPointer<HandlerStrategy>> Strategies;
};

#endif // RESIZEHANDLEITEM_H
