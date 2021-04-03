#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent):
  QDialog(parent),
  ui(new Ui::AboutDialog)
{
  ui->setupUi(this);
  setWindowFlags(Qt::WindowStaysOnTopHint);
}

AboutDialog::~AboutDialog()
{
  delete ui;
}
