#include "diagramtextitem.h"

DiagramTextItem::DiagramTextItem(QGraphicsItem *parent):
    QGraphicsTextItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

QVariant  DiagramTextItem::itemChange(GraphicsItemChange change,
                                      const QVariant    &value)
{
    if (change == QGraphicsItem::ItemSelectedHasChanged)
    {
        emit  selectedChange(this);
    }

    return value;
}

void  DiagramTextItem::focusOutEvent(QFocusEvent *event)
{
    setTextInteractionFlags(Qt::NoTextInteraction);
    emit  lostFocus(this);
    QGraphicsTextItem::focusOutEvent(event);
}

void  DiagramTextItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if (textInteractionFlags() == Qt::NoTextInteraction)
    {
        setTextInteractionFlags(Qt::TextEditorInteraction);
    }

    QGraphicsTextItem::mouseDoubleClickEvent(event);
}
