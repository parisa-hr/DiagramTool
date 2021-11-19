#include "objectkeeper.h"

ObjectKeeper *ObjectKeeper::sInstance = nullptr;

ObjectKeeper::ObjectKeeper(QGraphicsView *canvas, QObject *parent):
    QObject(parent),
    _mCanvas(canvas)
{
    sInstance = this;
    undoStack = new QUndoStack;
}

ObjectKeeper::~ObjectKeeper()
{
}

QUndoStack * ObjectKeeper::getUndoStack() const
{
    return undoStack;
}

QGraphicsView * ObjectKeeper::getCanvas() const
{
    return _mCanvas;
}

void  ObjectKeeper::createCommand(DiagramCommand *cmd)
{
    undoStack->push(new AddCommand(cmd));
}
