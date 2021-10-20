#include "diagramscene.h"

#include <QGraphicsSceneMouseEvent>

DiagramScene *DiagramScene::sInstance = nullptr;

DiagramScene::DiagramScene(QObject *parent):
    QGraphicsScene(parent)
{
    sInstance = this;

    connect(this, &QGraphicsScene::selectionChanged, this, [this]()
    {
        if (!selectedItems().isEmpty())
        {
          item = qgraphicsitem_cast<BaseItem *>(selectedItems().first());

          resizer = QSharedPointer<GraphicsItemResizer>::create(item);

          if (item)
          {
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

void  DiagramScene::addText(QString txt, BaseItem *item)
{
    QGraphicsTextItem *_useCaseText = new QGraphicsTextItem(txt, item);

    _useCaseText->setTextInteractionFlags(Qt::TextEditorInteraction);
    _useCaseText->setFlag(QGraphicsItem::ItemIsMovable);
    _useCaseText->setFlag(QGraphicsItem::ItemIsSelectable);
    _useCaseText->setZValue(101);
    _useCaseText->moveBy(item->rect().width() / 4, item->rect().height() / 3);
}
