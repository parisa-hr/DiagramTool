#include "classdiagram.h"

#include <qcoreapplication.h>

ClassDiagram::ClassDiagram()
{
    setWindowTitle("Class Diagram");

    /// Class  Button in menuBar Class
    QAction *act1=new QAction("Class");
    act1->setIcon(QIcon(":/icons/Tools/class/class.svg"));
    act1->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Class</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act1);

    /// Boundry Button in menuBar Class
    QAction *act2=new QAction("Boundry");
    act2->setIcon(QIcon(":/icons/Tools/class/Boundry.svg"));
    act2->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Boundry</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act2);


    /// Entity Button in menuBar Class

    QAction *act3=new QAction("Entity");
    act3->setIcon(QIcon(":/icons/Tools/class/Entity.svg"));
    act3->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Entity</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act3);

    /// Controller  Button in menuBar Class

    QAction *act4=new QAction("Controller");
    act4->setIcon(QIcon(":/icons/Tools/class/Controller.svg"));
    act4->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Controller</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act4);

    /// Note  Button in menuBar Class

    QAction *act5=new QAction("Note");
    act5->setIcon(QIcon(":/icons/Tools/class/Note.svg"));
    act5->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Note</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act5);


    /// Package  Button in menuBar Class

    QAction *act6=new QAction("Package");
    act6->setIcon(QIcon(":/icons/Tools/class/package.svg"));
    act6->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Package</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act6);


    /// Arrow  Button in menuBar Class

    QAction *act9=new QAction("Arrow");
    act9->setIcon(QIcon(":/icons/Tools/usecase/arrow .svg"));
    act9->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Arrow</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act9);



    /// Dasharrow  Button in menuBar Class

    QAction *act10=new QAction("Dasharrow");
    act10->setIcon(QIcon(":/icons/Tools/usecase/dashArrow.svg"));
    act10->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">DashArrow</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act10);

    /// Composition  Button in menuBar Class

    QAction *act7=new QAction("Composition");
    act7->setIcon(QIcon(":/icons/Tools/class/Composition.svg"));
    act7->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Composition</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act7);



    /// Aggregation  Button in menuBar Class

    QAction *act8=new QAction("Aggregation");
    act8->setIcon(QIcon(":/icons/Tools/class/Aggregation.svg"));
    act8->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Aggregation</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act8);

}
