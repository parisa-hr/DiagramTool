#ifndef DIAGRAMCOMMAND_H
#define DIAGRAMCOMMAND_H

#include <QGraphicsItem>
#include <QUndoStack>


class DiagramCommand
{
public:
    DiagramCommand();

    virtual ~DiagramCommand() = default;

    QGraphicsItem* item();

    void           setItem(QGraphicsItem *item);

private:
    QGraphicsItem *_item;
};


class ShapeCommand: public DiagramCommand
{
public:
    ShapeCommand()
    {
    }

private:
};

class AddCommand: public QUndoCommand
{
public:
    AddCommand(DiagramCommand *cmd, QUndoCommand *parent = 0);

    ~AddCommand()
    {
    }

    void  undo() override;

    void  redo() override;

private:
    QGraphicsItem *diagramItem;
};

#endif // DIAGRAMCOMMAND_H
