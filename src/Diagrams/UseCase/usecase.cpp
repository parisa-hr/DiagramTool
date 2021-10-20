#include "usecase.h"
#include <QCoreApplication>
#include <QDebug>
#include <QIcon>
#include "actor.h"
#include "usecaseitem.h"
#include "../../Base/objectkeeper.h"
#include <src/commonItems/package.h>
#include <src/commonItems/systemboundry.h>

UseCase::UseCase()
{
    setWindowTitle("UseCase Diagram");
    setFocus();


    QAction *act1 = new QAction("Actor");
    act1->setIcon(QIcon(":/icons/Tools/usecase/Actor.svg"));
    act1->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Actor</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act1);


    connect(act1, &QAction::triggered, this, &UseCase::addActor);


    QAction *act2 = new QAction("Usecase");
    act2->setIcon(QIcon(":/icons/Tools/usecase/UseCase.svg"));
    act2->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Usecase</font></p></body></html>",
                                                 nullptr));

    connect(act2, &QAction::triggered, this, &UseCase::addUsecase);

    menuBar()->addToolButton(act2);

    QAction *act3 = new QAction("Arrow");
    act3->setIcon(QIcon(":/icons/Tools/usecase/arrow .svg"));
    act3->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Arrow</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act3);

    QAction *act4 = new QAction("Dasharrow");
    act4->setIcon(QIcon(":/icons/Tools/usecase/dashArrow.svg"));
    act4->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">DashArrow</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act4);


    QAction *act5 = new QAction("System Boundry");
    act5->setIcon(QIcon(":/icons/Tools/usecase/System Boundry.svg"));
    act5->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">System Boundry</font></p></body></html>",
                                                 nullptr));

    connect(act5, &QAction::triggered, this, &UseCase::addSystemBoundry);


    menuBar()->addToolButton(act5);


    QAction *act6 = new QAction("Package");
    act6->setIcon(QIcon(":/icons/Tools/class/package.svg"));
    act6->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Package</font></p></body></html>",
                                                 nullptr));

    connect(act6, &QAction::triggered, this, &UseCase::addPackage);


    menuBar()->addToolButton(act6);


    cmd = new ShapeCommand();
}

UseCase::~UseCase()
{
    delete cmd;
}

void  UseCase::addActor()
{
    Actor *_actor = new Actor(this);

    _actor->setFlag(QGraphicsItem::ItemIsMovable);
    _actor->setFlag(QGraphicsItem::ItemIsSelectable);
    _actor->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_actor);

    ObjectKeeper::instance()->createCommand(cmd);
    getScene()->addItem(_actor);
}

void  UseCase::addUsecase()
{
    UseCaseItem *_useCase = new UseCaseItem(this);

    _useCase->setFlag(QGraphicsItem::ItemIsMovable);
    _useCase->setFlag(QGraphicsItem::ItemIsSelectable);
    _useCase->setFlag(QGraphicsItem::ItemIsFocusable);

    DiagramScene::instance()->addText("New UseCase", _useCase);

    cmd->setItem(_useCase);
    ObjectKeeper::instance()->createCommand(cmd);

    getScene()->addItem(_useCase);
}

void  UseCase::addSystemBoundry()
{
    SystemBoundry *_systemBoundry = new SystemBoundry(this);

    _systemBoundry->setFlag(QGraphicsItem::ItemIsMovable);
    _systemBoundry->setFlag(QGraphicsItem::ItemIsSelectable);
    _systemBoundry->setFlag(QGraphicsItem::ItemIsFocusable);
    cmd->setItem(_systemBoundry);
    ObjectKeeper::instance()->createCommand(cmd);

    getScene()->addItem(_systemBoundry);
}

void  UseCase::addPackage()
{
    Package *_package = new Package(this);

    _package->setFlag(QGraphicsItem::ItemIsMovable);
    _package->setFlag(QGraphicsItem::ItemIsSelectable);
    _package->setFlag(QGraphicsItem::ItemIsFocusable);

    cmd->setItem(_package);
    ObjectKeeper::instance()->createCommand(cmd);

    getScene()->addItem(_package);
}
