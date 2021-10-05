#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <src/Base/resizer/graphicsitemresizer.h>
#include "baseitem.h"

class DiagramScene: public QGraphicsScene
{
    Q_OBJECT

public:
    explicit DiagramScene(QObject *parent = nullptr);

    ~DiagramScene();

    static DiagramScene* instance()
    {
        return sInstance;
    }

private:
    static DiagramScene                 *sInstance;
    QSharedPointer<GraphicsItemResizer>  resizer;
    BaseItem                            *item = nullptr;
};

#endif // DIAGRAMSCENE_H
