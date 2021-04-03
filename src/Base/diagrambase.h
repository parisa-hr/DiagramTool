#ifndef DIAGRAMBASE_H
#define DIAGRAMBASE_H

#include <QWidget>
#include <QMenu>
#include "menubar.h"

class QGraphicsScene;
class DiagramTextItem;


namespace Ui
{
class DiagramBase;
}

class DiagramBase: public QWidget
{
    Q_OBJECT

public:
    explicit DiagramBase(QWidget *parent = nullptr);

    ~DiagramBase();

    void            scaleView(qreal scaleFactor);

    void            zoomIn();

    void            zoomOut();

    void            zoomReset();

    MenuBar       * menuBar() const;

    QGraphicsScene* getScene();

    qreal           zoomFactor() const;

protected:
    void            resizeEvent(QResizeEvent *event) override;

    void            keyPressEvent(QKeyEvent *event) override;

    void            mousePressEvent(QMouseEvent *event) override;

    void            mouseMoveEvent(QMouseEvent *) override;

    void            wheelEvent(QWheelEvent *) override;

private:
    void            zoomBy(qreal factor);

private slots:
    void            ExportPdf();

    void            ExportSvg();

    void            ExportPNG();

    void            updateZoomLabel();

    void            InsertDiagramText();

signals:
    void            zoomChanged();

private:
    Ui::DiagramBase *ui;
    QGraphicsScene  *scene;
    MenuBar         *_menuBar;
    QPalette        *_pal;
    DiagramTextItem *_textItem;
    QString          path;
    QString          m_currentPath;
};

#endif // DIAGRAMBASE_H
