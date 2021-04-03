#ifndef DIAGRAMVIEW_H
#define DIAGRAMVIEW_H

#include <QFrame>
#include <QGraphicsView>

class DiagramView;

class GraphicsView: public QGraphicsView
{
  Q_OBJECT

public:
  GraphicsView(DiagramView *v):
    QGraphicsView(), view(v)
  {
  }

protected:
  void  wheelEvent(QWheelEvent *e) override;

  void  scaleView(qreal scaleFactor);

  void  zoomIn();

  void  zoomOut();

private:
  DiagramView *view;
};

class DiagramView: public QFrame
{
  Q_OBJECT

public:
  explicit DiagramView(QWidget *parent = nullptr);

signals:
public slots:
private:
  GraphicsView *graphicsView;
};

#endif // DIAGRAMVIEW_H
