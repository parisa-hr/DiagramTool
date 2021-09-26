#include "menubar.h"
#include "ui_menubar.h"
#include "mainmenu.h"
#include <QAction>
#include <QToolButton>
#include <qfontdatabase.h>
#include <QDebug>

MenuBar::MenuBar(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MenuBar)
{
    ui->setupUi(this);
    _mainMenu = new MainMenu;
    _mainMenu->hide();

    /// add Font combobox

    ui->comboSize->setEditable(true);

    const QList<int>  standardSizes = QFontDatabase::standardSizes();

    for (int size : standardSizes)
    {
        ui->comboSize->addItem(QString::number(size));
    }

    ui->comboSize->setCurrentIndex(standardSizes.indexOf(QApplication::font().pointSize()));
}

MenuBar::~MenuBar()
{
    delete ui;
}

void  MenuBar::on_toolButton_clicked()
{
    emit  CloseWindow();
}

void  MenuBar::on_tb_Menu_clicked()
{
    if (_mainMenu->isVisible())
    {
        _mainMenu->hide();

        return;
    }

    auto  pos = mapToGlobal(QPoint(0, 60));

    _mainMenu->move(pos);
    _mainMenu->show();
}

MainMenu * MenuBar::getMainMenu() const
{
    return _mainMenu;
}

void  MenuBar::addToolButton(QAction *action)
{
    QToolButton *toolButton = new QToolButton;

    toolButton->setAutoRaise(true);
    toolButton->setIconSize(QSize(32, 32));

    toolButton->setDefaultAction(action);

    ui->DiagramMenu->addWidget(toolButton);
}

QFont  MenuBar::getFont()
{
    return ui->fontComboBox->currentFont();
}

void  MenuBar::on_tb_Pan_clicked(bool checked)
{
    if (checked)
    {
        emit  SetCursorPan();
        ui->tb_Select->setChecked(false);
    }
    else
    {
        emit  SetCursorSelect();
    }
}

void  MenuBar::on_tb_Select_clicked()
{
    emit  SetCursorSelect();

    ui->tb_Pan->setChecked(false);
}

void  MenuBar::on_tb_changeColor_clicked()
{
    emit  changedColor();
}

void  MenuBar::on_tb_addText_clicked()
{
    emit  addText();
}

void  MenuBar::on_tb_print_clicked()
{
    emit  doPrint();
}

void  MenuBar::on_tb_bold_clicked()
{
    emit  boldText();
}

void  MenuBar::on_fontComboBox_currentFontChanged(const QFont &f)
{
    qDebug() << "Parisa Font avaz kard";
    emit  changeFont(f);
}

void  MenuBar::on_tb_Italic_clicked()
{
    emit  italicText();
}

void  MenuBar::on_tb_under_clicked()
{
    emit  addUnderLine();
}

void  MenuBar::on_comboSize_currentTextChanged(const QString &arg1)
{
    emit  changeFontSize(arg1);
}

void  MenuBar::on_tb_undo_clicked()
{
    emit  doUndo();
}

void  MenuBar::on_tb_redo_clicked()
{
    emit  doRedo();
}
