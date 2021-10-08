#include "component.h"
#include "interface.h"
#include "port.h"
#include "providedinterface.h"
#include "requiredinterface.h"

#include <QCoreApplication>
#include <QIcon>

#include "componentitem.h"
#include "../../Base/objectkeeper.h"

#include <src/commonItems/note.h>
#include <src/commonItems/package.h>

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
    act3->setIcon(QIcon(":/icons/Tools/Component/Interface.svg"));
    act3->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Interface</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act3);

    connect(act3, &QAction::triggered, this, &Component::addInterface);


    QAction *act4 = new QAction("ProvidedInterface");
    act4->setIcon(QIcon(":/icons/Tools/Component/ProvidedInterface.svg"));
    act4->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">ProvidedInterface</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act4);

    connect(act4, &QAction::triggered, this, &Component::addProvidedinterfaces);

    QAction *act5 = new QAction("Requiredinterface");
    act5->setIcon(QIcon(":/icons/Tools/Component/Requiredinterface.svg"));
    act5->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Requiredinterface</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act5);

    connect(act5, &QAction::triggered, this, &Component::addRequiredinterfaces);


    QAction *act6 = new QAction("Pakage");
    act6->setIcon(QIcon(":/icons/Tools/class/package.svg"));
    act6->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Pakage</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act6);
    connect(act6, &QAction::triggered, this, &Component::addRequiredinterfaces);

    QAction *act7 = new QAction("Note");
    act7->setIcon(QIcon(":/icons/Tools/class/Note.svg"));
    act7->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Note</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act7);


    connect(act7, &QAction::triggered, this, &Component::addRequiredinterfaces);


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
    Note *_note = new Note(this);

    _note->setFlag(QGraphicsItem::ItemIsMovable);
    _note->setFlag(QGraphicsItem::ItemIsSelectable);
    _note->setFlag(QGraphicsItem::ItemIsFocusable);

    cmd->setItem(_note);
    ObjectKeeper::instance()->createCommand(cmd);

    getScene()->addItem(_note);
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
    Package *_package = new Package(this);

    _package->setFlag(QGraphicsItem::ItemIsMovable);
    _package->setFlag(QGraphicsItem::ItemIsSelectable);
    _package->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_package);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_package);
}

void  Component::addInterface()
{
    Interface *_interface = new Interface(this);

    _interface->setFlag(QGraphicsItem::ItemIsMovable);
    _interface->setFlag(QGraphicsItem::ItemIsSelectable);
    _interface->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_interface);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_interface);
}

void  Component::addProvidedinterfaces()
{
    ProvidedInterface *_pInterface = new ProvidedInterface(this);
}

void  Component::addRequiredinterfaces()
{
// RequiredInterface *_rInterface = new RequiredInterface(this);
}
