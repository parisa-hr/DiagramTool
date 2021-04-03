#include "diagrambase.h"
#include "ui_diagrambase.h"

#if defined (QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QSvgGenerator>
#endif
#endif

#include <QResizeEvent>
#include <QGraphicsScene>
#include <QMenuBar>
#include <QDebug>
#include <qmath.h>

#include <QGraphicsRectItem>
#include "mainmenu.h"
#include "diagramview.h"

#include "diagramtextitem.h"

DiagramBase::DiagramBase(QWidget *parent):
    ui(new Ui::DiagramBase)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    setBackgroundRole(QPalette::Base);

    {
        scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setAlignment(Qt::AlignHCenter);
    }

    updateZoomLabel();

    connect(this, &DiagramBase::zoomChanged, this, &DiagramBase::updateZoomLabel);


    _menuBar = new MenuBar(this);

    _pal = new QPalette();

    connect(_menuBar->getMainMenu(), &MainMenu::showGrideView, this, [this]()
    {
        _pal->setBrush(QPalette::Base, QPixmap(":/icons/base/background.png"));
        _pal->setColor(QPalette::HighlightedText, Qt::blue);
        setPalette(*_pal);
    });
    connect(_menuBar->getMainMenu(), &MainMenu::HideGrideView, this, [this]()
    {
        _pal = new QPalette();
        _pal->setBrush(QPalette::Base, Qt::white);
        setPalette(*_pal);
        this->update();
    });


    connect(_menuBar, &MenuBar::SetCursorPan, this, [this]()
    {
        setCursor(Qt::OpenHandCursor);
        ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        ui->graphicsView->setInteractive(false);
    });
    connect(_menuBar, &MenuBar::SetCursorSelect, this, [this]()
    {
        setCursor(Qt::ArrowCursor);
        ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
        ui->graphicsView->setInteractive(true);
    });
    connect(_menuBar, &MenuBar::CloseWindow, this, &DiagramBase::close);

    connect(_menuBar->getMainMenu(), &MainMenu::ExportAsPDF, this, &DiagramBase::ExportPdf);

    connect(_menuBar->getMainMenu(), &MainMenu::ExportAsSVG, this, &DiagramBase::ExportSvg);

    connect(_menuBar, &MenuBar::addText, this, &DiagramBase::InsertDiagramText);
}

DiagramBase::~DiagramBase()
{
    delete ui;
}

void  DiagramBase::scaleView(qreal scaleFactor)
{
    qreal  factor = ui->graphicsView->transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();

    if ((factor < 0.07) || (factor > 100))
    {
        return;
    }

    ui->graphicsView->scale(scaleFactor, scaleFactor);
}

void  DiagramBase::zoomIn()
{
    zoomBy(2);
}

void  DiagramBase::zoomOut()
{
    zoomBy(0.5);
}

void  DiagramBase::zoomReset()
{
    if (!qFuzzyCompare(zoomFactor(), qreal(1)))
    {
        ui->graphicsView->resetTransform();
        emit  zoomChanged();
    }
}

void  DiagramBase::resizeEvent(QResizeEvent *event)
{
    auto  w = event->size().width();

    _menuBar->resize(w, 60);
}

void  DiagramBase::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;

    default:
        ;
    }
}

void  DiagramBase::mousePressEvent(QMouseEvent *)
{
}

void  DiagramBase::mouseMoveEvent(QMouseEvent *)
{
}

void  DiagramBase::wheelEvent(QWheelEvent *event)
{
    zoomBy(qPow(1.2, event->angleDelta().y() / 240.0));
}

void  DiagramBase::ExportPdf()
{
#if QT_CONFIG(printdialog)
    QPrinter  printer(QPrinter::HighResolution);
    printer.setOrientation(QPrinter::Landscape);

    QPrintDialog  dialog(&printer, this);

    if (dialog.exec() == QDialog::Accepted)
    {
        QPainter  painter(&printer);

        scene->render(&painter);
    }

#endif
}

void  DiagramBase::ExportSvg()
{
    QString  newPath = QFileDialog::getSaveFileName(this, tr("Save SVG"),
                                                    path, tr("SVG files (*.svg)"));

    if (newPath.isEmpty())
    {
        return;
    }

    path = newPath;

//! [configure SVG generator]
    QSvgGenerator  generator;
    generator.setFileName(path);
    generator.setSize(QSize(200, 200));
    generator.setViewBox(QRect(0, 0, 200, 200));
    generator.setDescription(tr("An SVG drawing created by the SVG Generator "
                                "Example provided with Qt."));
//! [configure SVG generator]
//! [begin painting]
    QPainter  painter;
    painter.begin(&generator);
    scene->render(&painter);

    painter.end();
//! [end painting]
}

void  DiagramBase::updateZoomLabel()
{
    const int  percent = qRound(zoomFactor() * qreal(100));

    ui->lbl_Zoom->setText(QString::number(percent) + QLatin1Char('%'));
}

void  DiagramBase::InsertDiagramText()
{
    _textItem = new DiagramTextItem();

    _textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
    _textItem->setZValue(1000.0);
}

void  DiagramBase::zoomBy(qreal factor)
{
    const qreal  currentZoom = zoomFactor();

    if (((factor < 1) && (currentZoom < 0.1)) || ((factor > 1) && (currentZoom > 10)))
    {
        return;
    }

    ui->graphicsView->scale(factor, factor);
    emit  zoomChanged();
}

QGraphicsScene * DiagramBase::getScene()
{
    return scene;
}

qreal  DiagramBase::zoomFactor() const
{
    return ui->graphicsView->transform().m11();
}

MenuBar * DiagramBase::menuBar() const
{
    return _menuBar;
}
