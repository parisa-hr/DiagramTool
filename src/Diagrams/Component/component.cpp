#include "component.h"
#include "port.h"

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
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Component</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act1);

    connect(act1, &QAction::triggered, this, &Component::addComponent);

    QAction *act2 = new QAction("Port");
    act2->setIcon(QIcon(":/icons/Tools/Component/Port.svg"));
    act2->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Port</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act2);

    connect(act2, &QAction::triggered, this, &Component::addPort);

    QAction *act3 = new QAction("Interface");
    act3->setIcon(QIcon(":/icons/Tools/Component/Node.svg"));
    act3->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Interface</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act3);

    connect(act3, &QAction::triggered, this, &Component::addInterface);

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

void  Component::addPort()
{
    Port *_node = new Port(this);

    _node->setFlag(QGraphicsItem::ItemIsMovable);
    _node->setFlag(QGraphicsItem::ItemIsSelectable);
    _node->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_node);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_node);
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
