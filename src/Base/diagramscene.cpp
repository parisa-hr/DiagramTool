#include "diagramscene.h"

DiagramScene *DiagramScene::sInstance = nullptr;

DiagramScene::DiagramScene(QObject *parent) : QGraphicsScene(parent)
{
    sInstance = this;

}

DiagramScene::~DiagramScene()
{

}
