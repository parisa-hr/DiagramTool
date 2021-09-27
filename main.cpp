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

    QQmlApplicationEngine  engine;
    UseCase                m_useCase;
    Activity               m_activity;
    ClassDiagram           m_ClassDiagram;
    Component              m_Component;
    Deployment             m_Deployment;
    Sequence               m_Sequence;
    auto                   root_context = engine.rootContext();

    root_context->setContextProperty("UseCase", &m_useCase);
    root_context->setContextProperty("Activity", &m_activity);
    root_context->setContextProperty("ClassDiagram", &m_ClassDiagram);
    root_context->setContextProperty("ComponentDiagram", &m_Component);
    root_context->setContextProperty("Deployment", &m_Deployment);
    root_context->setContextProperty("Sequence", &m_Sequence);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }

    app.setWindowIcon(QIcon(":/icons/diagramTool.svg"));

    return app.exec();
}
