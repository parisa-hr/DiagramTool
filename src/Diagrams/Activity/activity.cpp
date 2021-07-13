#include "activity.h"

#include <QCoreApplication>
#include <QGraphicsScene>

#include "decisionnode.h"

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

    menuBar()->addToolButton(act8);
}

void  Activity::addActivityItem()
{
    QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0, 0, 150, 100));

    item->setPos(10, 10);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    item->setZValue(101);

    item->setPen(QColor(102, 102, 102));
    item->setBrush(QColor(158, 204, 255));
    getScene()->addItem(item);

    GraphicsItemResizer *resizer = new GraphicsItemResizer(item);
    resizer->setBrush(QColor(64, 64, 64));
    resizer->setMinSize(QSizeF(30, 30));
    resizer->setTargetSize(item->boundingRect().size());
    connect(resizer, &GraphicsItemResizer::targetRectChanged, [item, this](const QRectF &rect)
    {
        QPointF pos = item->pos();
        item->setPos(pos + rect.topLeft());
        QRectF old = item->rect();
        item->setRect(QRectF(old.topLeft(), rect.size()));
        getScene()->update(getScene()->sceneRect());
    });
}

void  Activity::addStartNode()
{
    QGraphicsEllipseItem *start = new QGraphicsEllipseItem(0, 0, 32, 32);

    start->setPos(10, 10);
    start->setFlag(QGraphicsItem::ItemIsMovable);
    start->setFlag(QGraphicsItem::ItemIsSelectable);
    start->setFlag(QGraphicsItem::ItemIsFocusable);
    start->setZValue(101);

    start->setPen(QColor(102, 102, 102));
    start->setBrush(QColor(158, 204, 255));
    getScene()->addItem(start);

    GraphicsItemResizer *resizer = new GraphicsItemResizer(start);
    resizer->setBrush(QColor(64, 64, 64));
    resizer->setMinSize(QSizeF(30, 30));
    resizer->setTargetSize(start->boundingRect().size());
    connect(resizer, &GraphicsItemResizer::targetRectChanged, [start, this](const QRectF &rect)
    {
        QPointF pos = start->pos();
        start->setPos(pos + rect.topLeft());
        QRectF old = start->rect();
        start->setRect(QRectF(old.topLeft(), rect.size()));
        getScene()->update(getScene()->sceneRect());
    });
}

void  Activity::addFinalNode()
{
}

void  Activity::addDecisionNode()
{
    DecisionNode *_decisionNode = new DecisionNode(this);

    _decisionNode->setFlag(QGraphicsItem::ItemIsMovable);
    _decisionNode->setFlag(QGraphicsItem::ItemIsSelectable);
    _decisionNode->setFlag(QGraphicsItem::ItemIsFocusable);

    getScene()->addItem(_decisionNode);

    GraphicsItemResizer *resizer = new GraphicsItemResizer(_decisionNode);
    resizer->setBrush(QColor(64, 64, 64));
    resizer->setMinSize(QSizeF(30, 30));
    resizer->setTargetSize(_decisionNode->boundingRect().size());
    connect(resizer, &GraphicsItemResizer::targetRectChanged, [_decisionNode, this](const QRectF &rect)
    {
        QPointF pos = _decisionNode->pos();
        _decisionNode->setPos(pos + rect.topLeft());
        QRectF old = _decisionNode->boundingRect();
        _decisionNode->setRect(QRectF(old.topLeft(), rect.size()));
        getScene()->update(getScene()->sceneRect());
    });
}
