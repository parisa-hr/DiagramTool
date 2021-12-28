#include "diagramscene.h"
#include "objectkeeper.h"

#include <QGraphicsSceneMouseEvent>
#include <QPolygonF>
#include <QPointF>
#include <src/Diagrams/Relations/aggregation.h>
#include <src/Diagrams/Relations/composition.h>
#include <src/Diagrams/Relations/directassosiation.h>
#include <src/commonItems/arrow.h>
#include <src/commonItems/communicationpath.h>
#include <src/commonItems/dasharrow.h>
#include <QDebug>

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
            qDebug() << "Item Type " << item->type();
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

    cmd = new ShapeCommand();
}

DiagramScene::~DiagramScene()
{
    clear();
}

void  DiagramScene::addText(QString txt, QGraphicsItem *item, qreal Px, qreal Py)
{
    QGraphicsTextItem *_useCaseText = new QGraphicsTextItem(txt, item);

    _useCaseText->setTextInteractionFlags(Qt::TextEditorInteraction);
    _useCaseText->setFlag(QGraphicsItem::ItemIsSelectable);
    _useCaseText->setZValue(101);
    _useCaseText->moveBy(Px, Py);
}

void  DiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
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
    else
    {
        _relation = none;
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
        _p1 = line->line().p1();
        _p2 = line->line().p2();

        switch (_relation)
        {
        case _Arow:
        {
            Arrow *arrow = new Arrow(_p2, _p1);
            cmd->setItem(arrow);

            ObjectKeeper::instance()->createCommand(cmd);
            addItem(arrow);
            update();
        }

        break;

        case _DashArow:
        {
            DashArrow *_dashArrow = new DashArrow(_p2, _p1);
            cmd->setItem(_dashArrow);

            ObjectKeeper::instance()->createCommand(cmd);
            addItem(_dashArrow);
            update();
        }

        break;

        case _Communication_path:
        {
            CommunicationPath *_communicationPath = new CommunicationPath(_p2, _p1);
            cmd->setItem(_communicationPath);

            ObjectKeeper::instance()->createCommand(cmd);
            addItem(_communicationPath);
            update();
        }

        break;
        case _Aggregation:
        {
            Aggregation *_aggregation = new Aggregation(_p2, _p1);
            cmd->setItem(_aggregation);

            ObjectKeeper::instance()->createCommand(cmd);
            addItem(_aggregation);
            update();
        }

        break;
        case _Assosiation:

            break;
        case _Composition:
        {
            Composition *_composition = new Composition(_p2, _p1);
            cmd->setItem(_composition);

            ObjectKeeper::instance()->createCommand(cmd);
            addItem(_composition);
            update();
        }

        break;
        case _Dependency:

            break;
        case _DirectAssosiation:

            break;
        case _Generalization:

            break;
        case _Inheritance:

            break;
        case _Realization:

            break;
        }
    }

    removeItem(line);
    delete line;
    line = nullptr;
    QGraphicsScene::mouseReleaseEvent(event);
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
