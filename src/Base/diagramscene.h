#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QGraphicsLineItem>

#include <src/Base/resizer/graphicsitemresizer.h>
#include "baseitem.h"
#include "diagramcommand.h"

class DiagramScene: public QGraphicsScene
{
    Q_OBJECT

public:
    enum Relation
    {
        _Arow,
        _DashArow,
        _Aggregation,
        _Assosiation,
        _Composition,
        _Dependency,
        _DirectAssosiation,
        _Generalization,
        _Inheritance,
        _Realization,
        _Communication_path,
        none
    };

    explicit DiagramScene(QObject *parent = nullptr);

    ~DiagramScene();

    static DiagramScene* instance()
    {
        return sInstance;
    }

    void  addText(QString txt, QGraphicsItem *item, qreal Px, qreal Py);

    // QGraphicsScene interface

    void  setRelation(Relation relation);

protected:
    void  mousePressEvent(QGraphicsSceneMouseEvent *event);

    void  mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    void  mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void  mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    static DiagramScene                 *sInstance;
    QSharedPointer<GraphicsItemResizer>  resizer;
    BaseItem                            *item      = nullptr;
    QGraphicsLineItem                   *line      = nullptr;
    Relation                             _relation = none;
    ShapeCommand                        *cmd;
    QPointF                              _p1;
    QPointF                              _p2;
};

#endif // DIAGRAMSCENE_H
