#ifndef MENUBAR_H
#define MENUBAR_H

#include <QWidget>

class MainMenu;
namespace Ui
{
class MenuBar;
}

class MenuBar: public QWidget
{
    Q_OBJECT

public:
    explicit MenuBar(QWidget *parent = nullptr);

    ~MenuBar();

    MainMenu* getMainMenu() const;

    void      addToolButton(QAction *action);

    QFont     getFont();

signals:
    void      CloseWindow();

    void      SetCursorPan();

    void      SetCursorSelect();

    void      addText();

    void      boldText();

    void      doPrint();

    void      changeFont(QFont f);

    void      italicText();

    void      addUnderLine();

    void      changeFontSize(QString size);

    void      changedColor();

private slots:
    void      on_toolButton_clicked();

    void      on_tb_Menu_clicked();

    void      on_tb_Pan_clicked(bool checked);

    void      on_tb_Select_clicked();

    void      on_tb_changeColor_clicked();

    void      on_tb_addText_clicked();

    void      on_tb_print_clicked();

    void      on_tb_bold_clicked();

    void      on_fontComboBox_currentFontChanged(const QFont &f);

    void      on_tb_Italic_clicked();

    void      on_tb_under_clicked();

    void      on_comboSize_currentTextChanged(const QString &arg1);

private:
    Ui::MenuBar *ui;
    MainMenu    *_mainMenu;
};

#endif // MENUBAR_H
