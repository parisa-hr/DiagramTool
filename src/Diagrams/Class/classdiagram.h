#ifndef CLASSDIAGRAM_H
#define CLASSDIAGRAM_H

#include <QObject>
#include "../../Base/diagrambase.h"
#include "../../Base/diagramcommand.h"

class ClassDiagram: public DiagramBase
{
    Q_OBJECT

public:
    ClassDiagram();

    void  addClass();

    void  addBoundry();

    void  addEntity();

    void  addController();

    void  addNote();

    void  addPackage();

private:
    ShapeCommand *cmd;
};

#endif // CLASSDIAGRAM_H
