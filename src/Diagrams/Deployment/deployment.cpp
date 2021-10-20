#include "artifact.h"
#include "database.h"
#include "deployment.h"
#include "node.h"

#include <QAction>
#include <QCoreApplication>

#include "../../Base/objectkeeper.h"

#include <src/Diagrams/Component/componentitem.h>

Deployment::Deployment()
{
    setWindowTitle("Deployment Diagram");
    setFocus();


    /// Node  Button in menuBar Class
    QAction *act1 = new QAction("Node");
    act1->setIcon(QIcon(":/icons/Tools/Deployment/Node.svg"));
    act1->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Node</font></p></body></html>",
                                                 nullptr));

    connect(act1, &QAction::triggered, this, &Deployment::addNode);

    menuBar()->addToolButton(act1);

    /// Component  Button in menuBar Class
    QAction *act2 = new QAction("Component");
    act2->setIcon(QIcon(":/icons/Tools/Component/Component.svg"));
    act2->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Component</font></p></body></html>",
                                                 nullptr));

    connect(act2, &QAction::triggered, this, &Deployment::addComponent);

    menuBar()->addToolButton(act2);

    /// Artifact  Button in menuBar Class

    QAction *act3 = new QAction("Artifact");
    act3->setIcon(QIcon(":/icons/Tools/class/Note.svg"));
    act3->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Artifact</font></p></body></html>",
                                                 nullptr));

    connect(act3, &QAction::triggered, this, &Deployment::addArtifact);

    menuBar()->addToolButton(act3);


    /// Instance  Button in menuBar Class

    QAction *act4 = new QAction("Instance");
    act4->setIcon(QIcon(":/icons/Tools/Deployment/Instance.svg"));
    act4->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Instance</font></p></body></html>",
                                                 nullptr));
// connect(act4, &QAction::triggered, this, &Deployment::addInstance);

    menuBar()->addToolButton(act4);

    QAction *act5 = new QAction("Database");
    act5->setIcon(QIcon(":/icons/Tools/Deployment/Database.svg"));
    act5->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Instance</font></p></body></html>",
                                                 nullptr));
    connect(act5, &QAction::triggered, this, &Deployment::addDataBase);

    menuBar()->addToolButton(act5);


    cmd = new ShapeCommand();
}

void  Deployment::addNode()
{
    Node *_node = new Node(this);

    _node->setFlag(QGraphicsItem::ItemIsMovable);
    _node->setFlag(QGraphicsItem::ItemIsSelectable);
    _node->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_node);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_node);
}

void  Deployment::addArtifact()
{
    Artifact *_artifact = new Artifact(this);

    _artifact->setFlag(QGraphicsItem::ItemIsMovable);
    _artifact->setFlag(QGraphicsItem::ItemIsSelectable);
    _artifact->setFlag(QGraphicsItem::ItemIsFocusable);

    DiagramScene::instance()->addText("New Artifact", _artifact, 0.0, 0.0);

    cmd->setItem(_artifact);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_artifact);
}

void  Deployment::addDataBase()
{
    Database *_db = new Database(this);

    _db->setFlag(QGraphicsItem::ItemIsMovable);
    _db->setFlag(QGraphicsItem::ItemIsSelectable);
    _db->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_db);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_db);
}

void  Deployment::addComponent()
{
    ComponentItem *_cmpItem = new ComponentItem(this);

    _cmpItem->setFlag(QGraphicsItem::ItemIsMovable);
    _cmpItem->setFlag(QGraphicsItem::ItemIsSelectable);
    _cmpItem->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_cmpItem);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_cmpItem);
}
