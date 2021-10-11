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


    connect(act1, &QAction::triggered, this, &Sequence::addLifeLine);

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
