#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent):
  QWidget(parent),
  ui(new Ui::MainMenu)
{
  ui->setupUi(this);
  setWindowFlags(Qt::Popup);
  setAttribute(Qt::WA_TranslucentBackground, true);
  setAttribute(Qt::WA_X11NetWmWindowTypeMenu, true);
  setAttribute(Qt::WA_AlwaysStackOnTop, true);
  setAutoFillBackground(true);
  _aboutDialog = new AboutDialog();
}

MainMenu::~MainMenu()
{
  delete ui;
}

void  MainMenu::on_pb_GridView_clicked(bool checked)
{
  if (checked)
  {
    emit  showGrideView();
  }
  else
  {
    emit  HideGrideView();
  }
}

void  MainMenu::on_pb_about_clicked()
{
  _aboutDialog->exec();
}

void  MainMenu::on_pb_ExportPDF_clicked()
{
  emit  ExportAsPDF();
}


void  MainMenu::on_pb_New_clicked()
{
  emit  NewFile();
}

void MainMenu::on_pb_ExportPng_clicked()
{

    emit ExportAsPNG();

}

void MainMenu::on_pb_ExportSvg_clicked()
{
    emit ExportAsSVG();

}

void MainMenu::on_pb_print_clicked()
{
   emit doPrint();
}
