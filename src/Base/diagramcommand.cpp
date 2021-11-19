#include "diagramcommand.h"
#include "diagramscene.h"
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
    DiagramScene::instance()->removeItem(diagramItem);
    DiagramScene::instance()->update();
}

void  AddCommand::redo()
{
    DiagramScene::instance()->addItem(diagramItem);
    DiagramScene::instance()->update();
}
