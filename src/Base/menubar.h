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

signals:
    void      CloseWindow();

    void      SetCursorPan();

    void      SetCursorSelect();

    void      addText();

private slots:
    void      on_toolButton_clicked();

    void      on_tb_Menu_clicked();

    void      on_tb_Pan_clicked(bool checked);

    void      on_tb_Select_clicked();

    void      on_tb_changeColor_clicked();

    void      on_tb_addText_clicked();

private:
    Ui::MenuBar *ui;
    MainMenu    *_mainMenu;
};

#endif // MENUBAR_H
