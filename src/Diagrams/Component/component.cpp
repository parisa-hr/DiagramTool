#include "component.h"

#include <QCoreApplication>
#include <QIcon>

#include "componentitem.h"
#include "../../Base/objectkeeper.h"

Component::Component()
{
    setWindowTitle("Component Diagram");
    setFocus();

    QAction *act1 = new QAction("Component");
    act1->setIcon(QIcon(":/icons/Tools/Component/Component.svg"));
    act1->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Actor</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act1);

    connect(act1, &QAction::triggered, this, &Component::addComponent);

    cmd = new ShapeCommand();
}

Component::~Component()
{
    delete cmd;
}

void  Component::addComponent()
{
    ComponentItem *_cmpItem = new ComponentItem(this);

    _cmpItem->setFlag(QGraphicsItem::ItemIsMovable);
    _cmpItem->setFlag(QGraphicsItem::ItemIsSelectable);
    _cmpItem->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_cmpItem);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_cmpItem);
}

void  Component::addNote()
{
}

void  Component::addNode()
{
}

void  Component::addPackage()
{
}

void  Component::addInterface()
{
}

void  Component::addProvidedinterfaces()
{
}

void  Component::addRequiredinterfaces()
{
}
