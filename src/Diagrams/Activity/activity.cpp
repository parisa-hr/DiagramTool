#include "activity.h"

#include <QCoreApplication>
#include <QGraphicsScene>
#include <src/Base/objectkeeper.h>

#include "activityitem.h"
#include "decisionnode.h"
#include "finalnode.h"
#include "startnode.h"
#include "swimlane.h"

#include "../../Base/resizer/graphicsitemresizer.h"

Activity::Activity()
{
    setWindowTitle("Activity Diagram");

    QAction *act1 = new QAction("Initial Node");
    act1->setIcon(QIcon(":/icons/Tools/Activity/Start.svg"));
    act1->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Initial Node</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act1);

    connect(act1, &QAction::triggered, this, &Activity::addStartNode);


    QAction *act2 = new QAction("Final Node");
    act2->setIcon(QIcon(":/icons/Tools/Activity/final.svg"));
    act2->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Final Node</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act2);

    connect(act2, &QAction::triggered, this, &Activity::addFinalNode);

    QAction *act3 = new QAction("Activity");
    act3->setIcon(QIcon(":/icons/Tools/Activity/Activity.svg"));
    act3->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Activity</font></p></body></html>",
                                                 nullptr));


    menuBar()->addToolButton(act3);


    connect(act3, &QAction::triggered, this, &Activity::addActivityItem);


    QAction *act4 = new QAction("Decision Node");
    act4->setIcon(QIcon(":/icons/Tools/Activity/Decision.svg"));
    act4->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Decision Node</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act4);

    connect(act4, &QAction::triggered, this, &Activity::addDecisionNode);


    QAction *act5 = new QAction("Fork&Join");
    act5->setIcon(QIcon(":/icons/Tools/Activity/fork-join.svg"));
    act5->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Fork and Join </font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act5);

    QAction *act6 = new QAction("Arrow");
    act6->setIcon(QIcon(":/icons/Tools/usecase/arrow .svg"));
    act6->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Arrow</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act6);


    QAction *act7 = new QAction("Dasharrow");
    act7->setIcon(QIcon(":/icons/Tools/usecase/dashArrow.svg"));
    act7->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">DashArrow</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act7);


    QAction *act8 = new QAction("Swimlane");
    act8->setIcon(QIcon(":/icons/Tools/Activity/multilane-horizontal.svg"));
    act8->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Swimlane</font></p></body></html>",
                                                 nullptr));

    connect(act8, &QAction::triggered, this, &Activity::addSwimLane);

    menuBar()->addToolButton(act8);

    cmd = new ShapeCommand();
}

Activity::~Activity()
{
    delete cmd;
}

void  Activity::addActivityItem()
{
    ActivityItem *_activityItem = new ActivityItem(this);

    _activityItem->setFlag(QGraphicsItem::ItemIsMovable);
    _activityItem->setFlag(QGraphicsItem::ItemIsSelectable);
    _activityItem->setFlag(QGraphicsItem::ItemIsFocusable);

    DiagramScene::instance()->addText("New Activity", _activityItem, _activityItem->rect().width() / 6, _activityItem->rect().height() / 4);

    cmd->setItem(_activityItem);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_activityItem);
}

void  Activity::addStartNode()
{
    StartNode *_start = new StartNode(this);

    _start->setFlag(QGraphicsItem::ItemIsMovable);
    _start->setFlag(QGraphicsItem::ItemIsSelectable);
    _start->setFlag(QGraphicsItem::ItemIsFocusable);

    cmd->setItem(_start);

    ObjectKeeper::instance()->createCommand(cmd);

    getScene()->addItem(_start);
}

void  Activity::addFinalNode()
{
    FinalNode *_finalNode = new FinalNode(this);

    _finalNode->setFlag(QGraphicsItem::ItemIsMovable);
    _finalNode->setFlag(QGraphicsItem::ItemIsSelectable);
    _finalNode->setFlag(QGraphicsItem::ItemIsFocusable);

    cmd->setItem(_finalNode);

    ObjectKeeper::instance()->createCommand(cmd);

    getScene()->addItem(_finalNode);
}

void  Activity::addDecisionNode()
{
    DecisionNode *_decisionNode = new DecisionNode(this);

    _decisionNode->setFlag(QGraphicsItem::ItemIsMovable);
    _decisionNode->setFlag(QGraphicsItem::ItemIsSelectable);
    _decisionNode->setFlag(QGraphicsItem::ItemIsFocusable);

    cmd->setItem(_decisionNode);

    ObjectKeeper::instance()->createCommand(cmd);

    getScene()->addItem(_decisionNode);
}

void  Activity::addSwimLane()
{
    Swimlane *_swimLane = new Swimlane(this);

    _swimLane->setFlag(QGraphicsItem::ItemIsMovable);
    _swimLane->setFlag(QGraphicsItem::ItemIsSelectable);
    _swimLane->setFlag(QGraphicsItem::ItemIsFocusable);

    cmd->setItem(_swimLane);

    ObjectKeeper::instance()->createCommand(cmd);

    getScene()->addItem(_swimLane);
}
