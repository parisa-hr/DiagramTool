#include "deployment.h"

#include <QCoreApplication>

Deployment::Deployment()
{
    setWindowTitle("Deployment Diagram");


    /// Node  Button in menuBar Class
    QAction *act1=new QAction("Node");
    act1->setIcon(QIcon(":/icons/Tools/Deployment/Node.svg"));
    act1->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Node</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act1);

    /// Component  Button in menuBar Class
    QAction *act2=new QAction("Component");
    act2->setIcon(QIcon(":/icons/Tools/Component/Component.svg"));
    act2->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Component</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act2);

    /// Artifact  Button in menuBar Class

    QAction *act3=new QAction("Artifact");
    act3->setIcon(QIcon(":/icons/Tools/class/Note.svg"));
    act3->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Artifact</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act3);


    /// Instance  Button in menuBar Class

    QAction *act4=new QAction("Instance");
    act4->setIcon(QIcon(":/icons/Tools/Deployment/Instance.svg"));
    act4->setToolTip(QCoreApplication::translate("MenuBar",
                                                 "<html><head/><body><p  style=\"background-color:white\"><font face=\"Times New Roman\" color=\"dark blue\">Instance</font></p></body></html>", nullptr));

    this->menuBar()->addToolButton(act4);
}
