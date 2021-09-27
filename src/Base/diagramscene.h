#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QGraphicsScene>
#include <QObject>

class DiagramScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit DiagramScene(QObject *parent = nullptr);

    ~DiagramScene();
    static DiagramScene* instance()
    {
        return sInstance;
    }

private:
    static DiagramScene *sInstance;
};

#endif // DIAGRAMSCENE_H
