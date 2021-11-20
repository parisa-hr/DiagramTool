#include "activationoccurrence.h"
#include "actornotation.h"
#include "alternative.h"
#include "deletemessage.h"
#include "lifeline.h"
#include "optionloop.h"
#include "sequence.h"

#include <QCoreApplication>
#include "../../Base/objectkeeper.h"

Sequence::Sequence()
{
    setWindowTitle("Sequence Diagram");
    setFocus();
    QAction *act1 = new QAction("Actor");
    act1->setIcon(QIcon(":/icons/Tools/usecase/Actor.svg"));
    act1->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Actor</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act1);


    connect(act1, &QAction::triggered, this, &Sequence::addActor);

    QAction *act2 = new QAction("Object");
    act2->setIcon(QIcon(":/icons/Tools/Sequence/object.svg"));
    act2->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Object</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act2);


    connect(act2, &QAction::triggered, this, &Sequence::addLifeLine);

    QAction *act3 = new QAction("ActivationOccurrence");
    act3->setIcon(QIcon(":/icons/Tools/Sequence/Activation.svg"));
    act3->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">ActivationOccurrence</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act3);
    connect(act3, &QAction::triggered, this, &Sequence::addActivationOccurrence);


    QAction *act4 = new QAction("Delete");
    act4->setIcon(QIcon(":/icons/Tools/Sequence/Delete.svg"));
    act4->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Actor</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act4);

    connect(act4, &QAction::triggered, this, &Sequence::addDeleteMessage);

    QAction *act5 = new QAction("OptionLoop");
    act5->setIcon(QIcon(":/icons/Tools/Sequence/OptionLoop.svg"));
    act5->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">OptionLoop</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act5);

    connect(act5, &QAction::triggered, this, &Sequence::addOptionLoop);


    QAction *act6 = new QAction("Alternative");
    act6->setIcon(QIcon(":/icons/Tools/Sequence/Alternative.svg"));
    act6->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Alternative</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act6);

    connect(act6, &QAction::triggered, this, &Sequence::addAlternative);


    QAction *act7 = new QAction("Arrow");
    act7->setIcon(QIcon(":/icons/Tools/usecase/arrow .svg"));
    act7->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Arrow</font></p></body></html>",
                                                 nullptr));


    connect(act7, &QAction::triggered, this, []()
    {
        DiagramScene::instance()->setRelation(DiagramScene::_Arow);
    });

    menuBar()->addToolButton(act7);

    QAction *act8 = new QAction("DashArrow");
    act8->setIcon(QIcon(":/icons/Tools/usecase/dashArrow.svg"));
    act8->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">DashArrow</font></p></body></html>",
                                                 nullptr));


    connect(act4, &QAction::triggered, this, []()
    {
        DiagramScene::instance()->setRelation(DiagramScene::_DashArow);
    });
    menuBar()->addToolButton(act8);


    cmd = new ShapeCommand();
}

Sequence::~Sequence()
{
    delete cmd;
}

void  Sequence::addLifeLine()
{
    Lifeline *_lifeLine = new Lifeline(this);

    _lifeLine->setFlag(QGraphicsItem::ItemIsMovable);
    _lifeLine->setFlag(QGraphicsItem::ItemIsSelectable);
    _lifeLine->setFlag(QGraphicsItem::ItemIsFocusable);

    DiagramScene::instance()->addText("New Object", _lifeLine, 0.0, 0.0);

    cmd->setItem(_lifeLine);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_lifeLine);
}

void  Sequence::addActor()
{
    ActorNotation *_act = new ActorNotation(this);

    _act->setFlag(QGraphicsItem::ItemIsMovable);
    _act->setFlag(QGraphicsItem::ItemIsSelectable);
    _act->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_act);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_act);
}

void  Sequence::addActivationOccurrence()
{
    ActivationOccurrence *_item = new ActivationOccurrence(this);

    _item->setFlag(QGraphicsItem::ItemIsMovable);
    _item->setFlag(QGraphicsItem::ItemIsSelectable);
    _item->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_item);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_item);
}

void  Sequence::addDeleteMessage()
{
    DeleteMessage *_item = new DeleteMessage(this);

    _item->setFlag(QGraphicsItem::ItemIsMovable);
    _item->setFlag(QGraphicsItem::ItemIsSelectable);
    _item->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_item);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_item);
}

void  Sequence::addOptionLoop()
{
    OptionLoop *_item = new OptionLoop(this);

    _item->setFlag(QGraphicsItem::ItemIsMovable);
    _item->setFlag(QGraphicsItem::ItemIsSelectable);
    _item->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_item);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_item);
}

void  Sequence::addAlternative()
{
    Alternative *_item = new Alternative(this);

    _item->setFlag(QGraphicsItem::ItemIsMovable);
    _item->setFlag(QGraphicsItem::ItemIsSelectable);
    _item->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_item);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_item);
}
