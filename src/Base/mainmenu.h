#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QShortcut>
#include "aboutdialog.h"


namespace Ui
{
class MainMenu;
}

class MainMenu: public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);

    ~MainMenu();

private slots:
    void  on_pb_GridView_clicked(bool checked);

    void  on_pb_about_clicked();

    void  on_pb_ExportPDF_clicked();

    void  on_pb_Saveas_clicked();

    void  on_pb_Open_clicked();

    void  on_pb_New_clicked();

    void on_pb_ExportPng_clicked();

    void on_pb_ExportSvg_clicked();

    void on_pb_print_clicked();

signals:
    void  showGrideView();

    void  HideGrideView();

    void  ExportAsPDF();

    void  SaveAs();

    void  OpenFile();

    void  NewFile();

    void ExportAsPNG();
    void ExportAsSVG();
    void doPrint();

private:
    Ui::MainMenu *ui;
    AboutDialog  *_aboutDialog;
};

#endif // MAINMENU_H
