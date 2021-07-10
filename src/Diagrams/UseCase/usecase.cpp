#include "usecase.h"
#include <QCoreApplication>
#include <QGraphicsScene>

#include <QIcon>
#include "actor.h"
#include "../../Base/resizer/graphicsitemresizer.h"

UseCase::UseCase()
{
    setWindowTitle("UseCase Diagram");


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

    QAction *act5 = new QAction("Include");
    act5->setIcon(QIcon(":/icons/Tools/usecase/include.svg"));
    act5->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Include</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act5);

    QAction *act6 = new QAction("Extend");
    act6->setIcon(QIcon(":/icons/Tools/usecase/Extend.svg"));
    act6->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Extend</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act6);

    QAction *act7 = new QAction("System Boundry");
    act7->setIcon(QIcon(":/icons/Tools/usecase/System Boundry.svg"));
    act7->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">System Boundry</font></p></body></html>",
                                                 nullptr));

    menuBar()->addToolButton(act7);
}

void  UseCase::addActor()
{
    Actor *_actor = new Actor(this);

    getScene()->addItem(_actor);

    GraphicsItemResizer *resizer = new GraphicsItemResizer(_actor);
    resizer->setBrush(QColor(64, 64, 64));
    resizer->setMinSize(QSizeF(30, 30));
    resizer->setTargetSize(_actor->boundingRect().size());
    connect(resizer, &GraphicsItemResizer::targetRectChanged, [_actor, this](const QRectF &rect)
    {
        QPointF pos = _actor->pos();
        _actor->setPos(pos + rect.topLeft());
        QRectF old = _actor->boundingRect();
        _actor->setRect(QRectF(old.topLeft(), rect.size()));
        getScene()->update(getScene()->sceneRect());
    });
}
