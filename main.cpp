#include <QApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QIcon>
#include <QQuickView>
#include <QtQuick>
#include <QDebug>

#include "src/Diagrams/UseCase/usecase.h"
#include "src/Diagrams/Class/classdiagram.h"
#include "src/Diagrams/Activity/activity.h"
#include "src/Diagrams/Component/component.h"
#include "src/Diagrams/Deployment/deployment.h"
#include "src/Diagrams/Sequense/sequence.h"

int  main(int argc, char *argv[])
{
    QApplication  app(argc, argv);

    //! [icons]
    QIcon::setThemeName(QStringLiteral("DiagramTool"));
    //! [icons]

    QQuickView    view(QUrl(QLatin1String("qrc:/qml/LauncherPage.qml")));
    QObject      *item           = view.rootObject();
    UseCase      *m_useCase      = new UseCase;
    ClassDiagram *m_ClassDiagram = new ClassDiagram;
    Sequence     *m_Sequence     = new Sequence;
    Component    *m_Component    = new Component;
    Activity     *m_activity     = new Activity;
    Deployment   *m_Deployment   = new Deployment;

    QObject::connect(item, SIGNAL(showUseCase()),
                     m_useCase, SLOT(showFullScreen()));

    QObject::connect(item, SIGNAL(showClass()),
                     m_ClassDiagram, SLOT(showFullScreen()));

    QObject::connect(item, SIGNAL(showSequence()),
                     m_Sequence, SLOT(showFullScreen()));

    QObject::connect(item, SIGNAL(showComponent()),
                     m_Component, SLOT(showFullScreen()));

    QObject::connect(item, SIGNAL(showActivity()),
                     m_activity, SLOT(showFullScreen()));

    QObject::connect(item, SIGNAL(showDeployment()),
                     m_Deployment, SLOT(showFullScreen()));

    view.showFullScreen();

    app.setWindowIcon(QIcon(":/icons/diagramTool.svg"));

    return app.exec();
}
