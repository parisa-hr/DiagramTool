#include "diagrambase.h"
#include "ui_diagrambase.h"

#if defined (QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printer)
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif
#include <QPrinter>
#if QT_CONFIG(printpreviewdialog)
#include <QPrintPreviewDialog>
#endif
#endif
#endif
#include <QSvgGenerator>
#include <QStandardPaths>
#include <QMessageBox>
#include <QResizeEvent>
#include <QGraphicsScene>
#include <QMenuBar>
#include <QDebug>
#include <qmath.h>
#include <QFileInfo>
#include <QDir>
#include <QFileDialog>

#include <QGraphicsRectItem>
#include <QColorDialog>
#include <qpushbutton.h>

#include "mainmenu.h"
#include "diagramview.h"
#include "exportdialog.h"
#include "diagramtextitem.h"
#include "objectkeeper.h"

DiagramBase::DiagramBase(QWidget *parent):
    ui(new Ui::DiagramBase)
{
    ui->setupUi(this);

    {
        myContextMenu = QSharedPointer<QMenu>::create(this);
        // myContextMenu;


        QAction *bringToFront = new QAction("BringToFront");
        bringToFront->setIcon(QIcon(":/icons/Tools/mouseMenu/mActionMoveItemsToTop.svg"));

        connect(bringToFront, &QAction::triggered, this, [this]()
        {
            if (!scene->selectedItems().isEmpty())
            {
              const QList<QGraphicsItem *> overlapItems = scene->selectedItems().first()->collidingItems();
              qreal zValue                              = 101;

              for (const QGraphicsItem *item : overlapItems)
              {
                if ((item->zValue() >= zValue))
                {
                  zValue = item->zValue() + 0.001;
                    }
                }

              if (zValue > 102.0)
              {
                zValue = 102.0;
                }

              scene->selectedItems().first()->setZValue(zValue);
            }
        });

        QAction *sendToBack = new QAction("SendToBack");
        sendToBack->setIcon(QIcon(":/icons/Tools/mouseMenu/mActionMoveItemsToBottom.svg"));
        connect(sendToBack, &QAction::triggered, this, [this]()
        {
            if (!scene->selectedItems().isEmpty())
            {
              const QList<QGraphicsItem *> overlapItems = scene->selectedItems().first()->collidingItems();
              qreal zValue                              = 101;

              for (const QGraphicsItem *item : overlapItems)
              {
                if ((item->zValue() <= zValue))
                {
                  zValue = item->zValue() - 0.001;
                    }
                }

              if (zValue < 100.1)
              {
                zValue = 100.1;
                }

              scene->selectedItems().first()->setZValue(zValue);
            }
        });

        QAction *deleteItem = new QAction("Delete");
        deleteItem->setIcon(QIcon(":/icons/Tools/mouseMenu/mTaskCancel.svg"));
        connect(deleteItem, &QAction::triggered, this, [this]()
        {
            if (!scene->selectedItems().isEmpty())
            {
              scene->removeItem(scene->selectedItems().first());
              scene->update();
            }
        });


        myContextMenu->addAction(bringToFront);

        myContextMenu->addAction(sendToBack);
        myContextMenu->addSeparator();

        myContextMenu->addAction(deleteItem);
    }


    setAutoFillBackground(true);
    setBackgroundRole(QPalette::Base);

    {
        scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setAlignment(Qt::AlignHCenter);
        ui->graphicsView->setRenderHints(QPainter::Antialiasing);

        new ObjectKeeper(ui->graphicsView);

        cmd = new ShapeCommand();


        undoAction = ObjectKeeper::instance()->getUndoStack()->createUndoAction(ui->graphicsView, tr("&Undo"));
        undoAction->setShortcuts(QKeySequence::Undo);
        addAction(undoAction);

        redoAction = ObjectKeeper::instance()->getUndoStack()->createRedoAction(ui->graphicsView, tr("&Redo"));
        redoAction->setShortcuts(QKeySequence::Redo);
        addAction(redoAction);


        QPushButton *button = new QPushButton("Test Add For Undo/Redo", ui->graphicsView);
        button->setGeometry(100, 100, 200, 50);

        connect(button, &QPushButton::clicked, this, [this]()
        {
            QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0, 0, 150, 100));

            item->setPos(10, 10);
            item->setFlag(QGraphicsItem::ItemIsMovable);
            item->setFlag(QGraphicsItem::ItemIsSelectable);
            item->setFlag(QGraphicsItem::ItemIsFocusable);
            item->setZValue(101);

            item->setPen(QColor(102, 102, 102));
            item->setBrush(QColor(158, 204, 255));

            cmd->setItem(item);

            ObjectKeeper::instance()->createCommand(cmd);
            scene->addItem(item);
        });
    }

    updateZoomLabel();

    {
        _menuBar = new MenuBar(this);
        font     = _menuBar->getFont();


        _pal = new QPalette();

        /// all connections

        connect(this, &DiagramBase::zoomChanged, this, &DiagramBase::updateZoomLabel);

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

        connect(_menuBar->getMainMenu(), &MainMenu::ExportAsPNG, this, &DiagramBase::ExportPNG);

        connect(_menuBar->getMainMenu(), &MainMenu::doPrint, this, &DiagramBase::PrintPreview);

        connect(_menuBar, &MenuBar::addText, this, &DiagramBase::InsertDiagramText);

        connect(_menuBar, &MenuBar::doPrint, this, &DiagramBase::PrintPreview);

        connect(_menuBar, &MenuBar::boldText, this, [this]()
        {
            if (!scene->selectedItems().isEmpty())
            {
              DiagramTextItem *item = qgraphicsitem_cast<DiagramTextItem *>(scene->selectedItems().first());

              if (item)
              {
                if (font.bold() == true)
                {
                  font.setBold(false);
                  item->setFont(font);
                    }
                else
                {
                  font.setBold(true);
                  item->setFont(font);
                    }
                }
            }
        });

        connect(_menuBar, &MenuBar::changeFont, this, [this](QFont f)
        {
            if (!scene->selectedItems().isEmpty())
            {
              DiagramTextItem *item = qgraphicsitem_cast<DiagramTextItem *>(scene->selectedItems().first());

              if (item)
              {
                if (font.bold() == true)
                {
                  f.setBold(true);
                    }
                else
                {
                  f.setBold(false);
                    }

                if (font.italic() == true)
                {
                  f.setItalic(true);
                    }
                else
                {
                  f.setItalic(false);
                    }

                if (font.underline() == true)
                {
                  f.setUnderline(true);
                    }
                else
                {
                  f.setUnderline(false);
                    }

                f.setPixelSize(font.pointSize());

                item->setFont(f);
                font = f;
                }
            }
        });

        connect(_menuBar, &MenuBar::italicText, this, [this]()
        {
            if (!scene->selectedItems().isEmpty())
            {
              DiagramTextItem *item = qgraphicsitem_cast<DiagramTextItem *>(scene->selectedItems().first());

              if (item)
              {
                if (font.italic() == true)
                {
                  font.setItalic(false);
                  item->setFont(font);
                    }
                else
                {
                  font.setItalic(true);
                  item->setFont(font);
                    }
                }
            }
        });

        connect(_menuBar, &MenuBar::addUnderLine, this, [this]()
        {
            if (!scene->selectedItems().isEmpty())
            {
              DiagramTextItem *item = qgraphicsitem_cast<DiagramTextItem *>(scene->selectedItems().first());

              if (item)
              {
                if (font.underline() == true)
                {
                  font.setUnderline(false);
                  item->setFont(font);
                    }
                else
                {
                  font.setUnderline(true);
                  item->setFont(font);
                    }
                }
            }
        });

        connect(_menuBar, &MenuBar::changeFontSize, this, [this](QString size)
        {
            font.setPointSize(size.toInt());

            if (!scene->selectedItems().isEmpty())
            {
              DiagramTextItem *item = qgraphicsitem_cast<DiagramTextItem *>(scene->selectedItems().first());

              if (item)
              {
                item->setFont(font);
                }
            }
        });

        connect(_menuBar, &MenuBar::changedColor, this, [this]()
        {
            if (!scene->selectedItems().isEmpty())
            {
              DiagramTextItem *item = qgraphicsitem_cast<DiagramTextItem *>(scene->selectedItems().first());

              if (item)
              {
                QColor color = QColorDialog::getColor(Qt::black, this);
                item->setDefaultTextColor(color);
                }
            }
        });
    }
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

void  DiagramBase::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    { }
}

void  DiagramBase::mouseMoveEvent(QMouseEvent *event)
{
}

void  DiagramBase::wheelEvent(QWheelEvent *event)
{
    zoomBy(qPow(1.2, event->angleDelta().y() / 240.0));
}

void  DiagramBase::contextMenuEvent(QContextMenuEvent *event)
{
    // scene->clearSelection();
    // scene->selectedItems().first()->setSelected(true);

    myContextMenu->exec(event->pos());
}

void  DiagramBase::ExportPdf()
{
#ifndef QT_NO_PRINTER
    //! [0]
    QFileDialog  fileDialog(this, tr("Export PDF"));
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setMimeTypeFilters(QStringList("application/pdf"));
    fileDialog.setDefaultSuffix("pdf");

    if (fileDialog.exec() != QDialog::Accepted)
    {
        return;
    }

    QString   fileName = fileDialog.selectedFiles().first();
    QPrinter  printer(QPrinter::HighResolution);
    printer.setOrientation(QPrinter::Landscape);

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    QPainter  painter(&printer);

    scene->render(&painter);
    //! [0]
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

void  DiagramBase::ExportPNG()
{
    ExportDialog  exportDialog(this);

    exportDialog.setExportSize(ui->graphicsView->size());
    QString  fileName;
    QString  picLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).value(0, QDir::currentPath());

    if (m_currentPath.isEmpty())
    {
        fileName = picLocation + QLatin1String("/export.png");
    }
    else
    {
        const QFileInfo  fi(m_currentPath);
        fileName = fi.absolutePath() + QLatin1Char('/') + fi.baseName() + QLatin1String(".png");
    }

    exportDialog.setExportFileName(fileName);

    while (true)
    {
        if (exportDialog.exec() != QDialog::Accepted)
        {
            break;
        }

        const QSize  imageSize = exportDialog.exportSize();
        QImage       image(imageSize, QImage::Format_ARGB32);
        image.fill(Qt::transparent);
        QPainter  painter;
        painter.begin(&image);
        scene->render(&painter, QRectF(QPointF(), QSizeF(imageSize)));
        painter.end();

        const QString  fileName = exportDialog.exportFileName();

        if (image.save(fileName))
        {
            const QString  message = tr("Exported %1, %2x%3, %4 bytes")
                                     .arg(QDir::toNativeSeparators(fileName)).arg(imageSize.width()).arg(imageSize.height())
                                     .arg(QFileInfo(fileName).size());
            break;
        }
        else
        {
            QMessageBox::critical(this, tr("Export Image"),
                                  tr("Could not write file '%1'.").arg(QDir::toNativeSeparators(fileName)));
        }
    }
}

void  DiagramBase::PrintPreview()
{
#if QT_CONFIG(printpreviewdialog)
    scene->update();

    QPrinter  printer(QPrinter::HighResolution);
    printer.setOrientation(QPrinter::Landscape);

    QPrintPreviewDialog  preview(&printer, ui->graphicsView);
    connect(&preview, &QPrintPreviewDialog::paintRequested, this, &DiagramBase::print);
    preview.exec();
#endif
}

void  DiagramBase::print(QPrinter *printer)
{
#ifdef QT_NO_PRINTER
    Q_UNUSED(printer);
#else
    QPainter  painter(printer);
    scene->render(&painter);

#endif
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
    _textItem->setZValue(101);
    _textItem->setFont(font);

    scene->addItem(_textItem);
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
