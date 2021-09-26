#include "diagramcommand.h"
#include "objectkeeper.h"

DiagramCommand::DiagramCommand()
{
}

QGraphicsItem * DiagramCommand::item()
{
    return _item;
}

void  DiagramCommand::setItem(QGraphicsItem *item)
{
    _item = item;
}

AddCommand::AddCommand(DiagramCommand *cmd, QUndoCommand *parent):
    QUndoCommand(parent)
{
    auto  shape = dynamic_cast<ShapeCommand *>(cmd);

    if (shape)
    {
        diagramItem = shape->item();


        return;
    }
}

void  AddCommand::undo()
{
    ObjectKeeper::instance()->getMapCanvas()->scene()->removeItem(diagramItem);
    ObjectKeeper::instance()->getMapCanvas()->update();
}

void  AddCommand::redo()
{
    ObjectKeeper::instance()->getMapCanvas()->scene()->addItem(diagramItem);
    ObjectKeeper::instance()->getMapCanvas()->update();
}
