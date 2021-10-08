#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>

#include "../../Base/diagrambase.h"
#include "../../Base/diagramcommand.h"


class Component: public DiagramBase
{
    Q_OBJECT

public:
    Component();

    ~Component();

private slots:
    void  addComponent();

    void  addNote();

    void  addNode();

    void  addPackage();

    void  addInterface();

    void  addProvidedinterfaces();

    void  addRequiredinterfaces();

private:
    ShapeCommand *cmd;
};

#endif // COMPONENT_H
