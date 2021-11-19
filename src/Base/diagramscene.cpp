﻿#include "diagramscene.h"

#include <QGraphicsSceneMouseEvent>

#include <src/Diagrams/Relations/directassosiation.h>

DiagramScene *DiagramScene::sInstance = nullptr;

DiagramScene::DiagramScene(QObject *parent):
    QGraphicsScene(parent)
{
    sInstance = this;
// TODO : fixed This
    connect(this, &QGraphicsScene::selectionChanged, this, [this]()
    {
        if (!selectedItems().isEmpty())
        {
          item = qgraphicsitem_cast<BaseItem *>(selectedItems().first());

          if (item)
          {
            resizer = QSharedPointer<GraphicsItemResizer>::create(item);
            resizer->setBrush(QColor(64, 64, 64));
            resizer->setMinSize(QSizeF(30, 30));
            resizer->setTargetSize(item->rect().size());

            connect(resizer.data(), &GraphicsItemResizer::targetRectChanged, [this](const QRectF &rect)
                {
                    QPointF pos = item->pos();
                    item->setPos(pos + rect.topLeft());
                    QRectF old = item->boundingRect();
                    item->setRect(QRectF(old.topLeft(), rect.size()));
                    update(sceneRect());
                });
            }
        }
    });
}

DiagramScene::~DiagramScene()
{
    clear();
}

void  DiagramScene::addText(QString txt, BaseItem *item, qreal Px, qreal Py)
{
    QGraphicsTextItem *_useCaseText = new QGraphicsTextItem(txt, item);

    _useCaseText->setTextInteractionFlags(Qt::TextEditorInteraction);
    _useCaseText->setFlag(QGraphicsItem::ItemIsSelectable);
    _useCaseText->setZValue(101);
    _useCaseText->moveBy(Px, Py);
}

void  DiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
    {
        return;
    }

    if (!(_relation == none))
    {
        line = new QGraphicsLineItem(QLineF(event->scenePos(),
                                            event->scenePos()));
        line->setPen(QPen(Qt::black, 2));
        addItem(line);
    }
    else
    {
        QGraphicsScene::mousePressEvent(event);
    }
}

void  DiagramScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (!(_relation == none) && (line != nullptr))
    {
        QLineF  newLine(line->line().p1(), event->scenePos());
        line->setLine(newLine);
    }
    else
    {
        QGraphicsScene::mouseMoveEvent(event);
    }
}

void  DiagramScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (!(_relation == none) && (line != nullptr))
    {
        QList<QGraphicsItem *>  startItems = items(line->line().p1());

        if (startItems.count() && (startItems.first() == line))
        {
            startItems.removeFirst();
        }

        QList<QGraphicsItem *>  endItems = items(line->line().p2());

        if (endItems.count() && (endItems.first() == line))
        {
            endItems.removeFirst();
        }

        if ((startItems.count() > 0) && (endItems.count() > 0)
            && (startItems.first() != endItems.first()))
        {
            BaseItem          *startItem = qgraphicsitem_cast<BaseItem *>(startItems.first());
            BaseItem          *endItem   = qgraphicsitem_cast<BaseItem *>(endItems.first());
            DirectAssosiation *arrow     = new DirectAssosiation(startItem, endItem);
            arrow->setZValue(-1000.0);
            addItem(arrow);
            arrow->updatePosition();
        }
    }

    removeItem(line);
    delete line;
    line = nullptr;
    QGraphicsScene::mouseReleaseEvent(event);

// switch (_relation)
// {
// case _Arow:

// break;

// case _DashArow:

// break;
// case _Aggregation:

// break;
// case _Assosiation:

// break;
// case _Composition:

// break;
// case _Dependency:

// break;
// case _DirectAssosiation:

// break;
// case _Generalization:

// break;
// case _Inheritance:

// break;
// case _Realization:

// break;
// }
}

void  DiagramScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseDoubleClickEvent(event);

    _relation = none;
}

void  DiagramScene::setRelation(Relation relation)
{
    _relation = relation;
}
