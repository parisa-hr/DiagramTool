#include "diagramview.h"
#include <QtWidgets>
#include <math.h>

void  GraphicsView::wheelEvent(QWheelEvent *e)
{
// if (e->modifiers() & Qt::ControlModifier)
// {
// if (e->delta() > 0)
// {
// zoomIn();
// }
// else
// {
// zoomOut();
// }

// e->accept();
// }
// else
// {
// QGraphicsView::wheelEvent(e);
// }
  scaleView(pow((double)2, -e->delta() / 240.0));
}

void  GraphicsView::scaleView(qreal scaleFactor)
{
  qreal  factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();

  if ((factor < 0.07) || (factor > 100))
  {
    return;
  }

  scale(scaleFactor, scaleFactor);
}

void  GraphicsView::zoomIn()
{
  scaleView(qreal(1.2));
}

void  GraphicsView::zoomOut()
{
  scaleView(1 / qreal(1.2));
}

DiagramView::DiagramView(QWidget *parent):
  QFrame(parent)
{
  setFrameStyle(Sunken | StyledPanel);
  graphicsView = new GraphicsView(this);
  graphicsView->setRenderHint(QPainter::Antialiasing, false);
  graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
  graphicsView->setOptimizationFlags(QGraphicsView::DontSavePainterState);
  graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
  graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
}
