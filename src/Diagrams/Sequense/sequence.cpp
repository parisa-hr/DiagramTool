#include "activationoccurrence.h"
#include "actornotation.h"
#include "deletemessage.h"
#include "lifeline.h"
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
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Actor</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act2);


    connect(act2, &QAction::triggered, this, &Sequence::addLifeLine);

    QAction *act3 = new QAction("ActivationOccurrence");
    act3->setIcon(QIcon(":/icons/Tools/Sequence/Activation.svg"));
    act3->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Actor</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act3);
    connect(act3, &QAction::triggered, this, &Sequence::addActivationOccurrence);


    QAction *act4 = new QAction("Actor");
    act4->setIcon(QIcon(":/icons/Tools/Sequence/Delete.svg"));
    act4->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Actor</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act4);


    connect(act4, &QAction::triggered, this, &Sequence::addDeleteMessage);

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
    DeleteMessage *_item = new DeleteMessage();

    _item->setFlag(QGraphicsItem::ItemIsMovable);
    _item->setFlag(QGraphicsItem::ItemIsSelectable);
    _item->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_item);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_item);
}
