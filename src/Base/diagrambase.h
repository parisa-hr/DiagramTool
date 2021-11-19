#ifndef DIAGRAMBASE_H
#define DIAGRAMBASE_H

#include <QWidget>
#include <QMenu>
#include <QPrinter>
#include <QContextMenuEvent>
#include "diagramcommand.h"
#include "diagramscene.h"
#include "baseitem.h"

#include "menubar.h"

class QGraphicsScene;
// class DiagramTextItem;


namespace Ui
{
class DiagramBase;
}

class DiagramBase: public QWidget
{
    Q_OBJECT

public:
    DiagramBase(QWidget *parent = nullptr);

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

    void            wheelEvent(QWheelEvent *) override;

    void            contextMenuEvent(QContextMenuEvent *event);

    void            closeEvent(QCloseEvent *event);

private:
    void            zoomBy(qreal factor);

private slots:
    void            ExportPdf();

    void            ExportSvg();

    void            ExportPNG();

    void            PrintPreview();

    void            print(QPrinter *printer);

    void            updateZoomLabel();

    void            InsertDiagramText();

signals:
    void            zoomChanged();

private:
    Ui::DiagramBase       *ui;
    DiagramScene          *scene;
    MenuBar               *_menuBar;
    QPalette              *_pal;
    QString                path;
    QString                m_currentPath;
    QFont                  font;
    QSharedPointer<QMenu>  myContextMenu;
    QAction               *undoAction;
    QAction               *redoAction;
};

#endif // DIAGRAMBASE_H
