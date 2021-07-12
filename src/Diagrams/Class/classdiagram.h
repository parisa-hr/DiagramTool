#ifndef CLASSDIAGRAM_H
#define CLASSDIAGRAM_H

#include <QObject>
#include "../../Base/diagrambase.h"

class ClassDiagram: public DiagramBase
{
    Q_OBJECT

public:
    explicit ClassDiagram();

    void  addClass();

    void  addBoundry();

    void  addEntity();

    void  addController();

    void  addNote();

    void  addPackage();

signals:
public slots:
};

#endif // CLASSDIAGRAM_H
