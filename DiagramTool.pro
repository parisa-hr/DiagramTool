QT +=core gui quick printsupport svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    src/Base/baseitem.h \
    src/Base/diagrambase.h \
    src/Base/diagramcommand.h \
    src/Base/diagramscene.h \
    src/Base/diagramtextitem.h \
    src/Base/exportdialog.h \
    src/Base/menubar.h \
    src/Base/mainmenu.h \
    src/Base/aboutdialog.h \
    src/Base/objectkeeper.h \
    src/Base/resizer/graphicsitemresizer.h \
    src/Base/resizer/handlerstrategies.h \
    src/Base/resizer/resizehandleitem.h \
    src/Diagrams/Activity/activityitem.h \
    src/Diagrams/Activity/decisionnode.h \
    src/Diagrams/Activity/finalnode.h \
    src/Diagrams/Activity/fork_join.h \
    src/Diagrams/Activity/initialnode.h \
    src/Diagrams/Activity/startnode.h \
    src/Diagrams/Activity/swimlane.h \
    src/Diagrams/Class/boundaryitem.h \
    src/Diagrams/Class/classitem.h \
    src/Diagrams/Class/controlitem.h \
    src/Diagrams/Class/entityitem.h \
    src/Diagrams/Component/componentitem.h \
    src/Diagrams/Component/interface.h \
    src/Diagrams/Component/port.h \
    src/Diagrams/Component/providedinterface.h \
    src/Diagrams/Component/requiredinterface.h \
    src/Diagrams/Deployment/artifact.h \
    src/Diagrams/Deployment/node.h \
    src/Diagrams/UseCase/actor.h \
    src/Diagrams/UseCase/usecase.h \
    src/Diagrams/Activity/activity.h \
    src/Diagrams/Component/component.h \
    src/Diagrams/Sequense/sequence.h \
    src/Diagrams/Class/classdiagram.h \
    src/Diagrams/Deployment/deployment.h \ \
    src/Diagrams/UseCase/usecaseitem.h \
    src/commonItems/arrow.h \
    src/commonItems/note.h \
    src/commonItems/package.h \
    src/commonItems/systemboundry.h

SOURCES += \
        main.cpp \
    src/Base/baseitem.cpp \
    src/Base/diagrambase.cpp \
    src/Base/diagramcommand.cpp \
    src/Base/diagramscene.cpp \
    src/Base/diagramtextitem.cpp \
    src/Base/exportdialog.cpp \
    src/Base/menubar.cpp \
    src/Base/mainmenu.cpp \
    src/Base/aboutdialog.cpp \
    src/Base/objectkeeper.cpp \
    src/Base/resizer/graphicsitemresizer.cpp \
    src/Base/resizer/handlerstrategies.cpp \
    src/Base/resizer/resizehandleitem.cpp \
    src/Diagrams/Activity/activityitem.cpp \
    src/Diagrams/Activity/decisionnode.cpp \
    src/Diagrams/Activity/finalnode.cpp \
    src/Diagrams/Activity/fork_join.cpp \
    src/Diagrams/Activity/initialnode.cpp \
    src/Diagrams/Activity/startnode.cpp \
    src/Diagrams/Activity/swimlane.cpp \
    src/Diagrams/Class/boundaryitem.cpp \
    src/Diagrams/Class/classitem.cpp \
    src/Diagrams/Class/controlitem.cpp \
    src/Diagrams/Class/entityitem.cpp \
    src/Diagrams/Component/componentitem.cpp \
    src/Diagrams/Component/interface.cpp \
    src/Diagrams/Component/port.cpp \
    src/Diagrams/Component/providedinterface.cpp \
    src/Diagrams/Component/requiredinterface.cpp \
    src/Diagrams/Deployment/artifact.cpp \
    src/Diagrams/Deployment/node.cpp \
    src/Diagrams/UseCase/actor.cpp \
    src/Diagrams/UseCase/usecase.cpp \
    src/Diagrams/Activity/activity.cpp \
    src/Diagrams/Component/component.cpp \
    src/Diagrams/Sequense/sequence.cpp \
    src/Diagrams/Class/classdiagram.cpp \
    src/Diagrams/Deployment/deployment.cpp \
    src/Diagrams/UseCase/usecaseitem.cpp \
    src/commonItems/arrow.cpp \
    src/commonItems/note.cpp \
    src/commonItems/package.cpp \
    src/commonItems/systemboundry.cpp


FORMS += \
    src/Base/diagrambase.ui \
    src/Base/menubar.ui \
    src/Base/mainmenu.ui \
    src/Base/aboutdialog.ui \


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=


