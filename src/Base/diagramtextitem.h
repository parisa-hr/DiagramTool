#ifndef DIAGRAMTEXTITEM_H
#define DIAGRAMTEXTITEM_H

#include <QGraphicsTextItem>

class QGraphicsSceneMouseEvent;


class DiagramTextItem: public QGraphicsTextItem
{
    Q_OBJECT

public:
    enum
    {
        Type = UserType + 3
    };

    DiagramTextItem(QGraphicsItem *parent = nullptr);

    int  type() const override
    {
        return Type;
    }

signals:
    void      lostFocus(DiagramTextItem *item);

    void      selectedChange(QGraphicsItem *item);

protected:
    QVariant  itemChange(GraphicsItemChange change, const QVariant &value) override;

    void      focusOutEvent(QFocusEvent *event) override;

    void      mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};


#endif // DIAGRAMTEXTITEM_H
