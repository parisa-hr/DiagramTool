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
    explicit ObjectKeeper(QGraphicsView *canvas = nullptr, QObject *parent = nullptr);

    ~ObjectKeeper();

    static ObjectKeeper* instance()
    {
        return sInstance;
    }

    QUndoStack   * getUndoStack() const;

    void           createCommand(DiagramCommand *cmd);

    QGraphicsView* getCanvas() const;

private:
    static ObjectKeeper *sInstance;
    QGraphicsView       *_mCanvas;
    QUndoStack          *undoStack;
};

#endif // OBJECTKEEPER_H
