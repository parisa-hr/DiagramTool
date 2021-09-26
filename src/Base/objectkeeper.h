#ifndef OBJECTKEEPER_H
#define OBJECTKEEPER_H

#include <QObject>
#include <QUndoStack>
#include <QGraphicsView>
#include "diagramcommand.h"

class ObjectKeeper: public QObject
{
    Q_OBJECT

public:
    explicit ObjectKeeper(QGraphicsView *canvas, QObject *parent = nullptr);

    ~ObjectKeeper();

    static ObjectKeeper* instance()
    {
        return sInstance;
    }

    QUndoStack   * getUndoStack() const;

    void           createCommand(DiagramCommand *cmd);

    QGraphicsView* getMapCanvas() const;

private:
    static ObjectKeeper *sInstance;
    QGraphicsView       *_mapCanvas;
    QUndoStack          *undoStack;
};

#endif // OBJECTKEEPER_H
