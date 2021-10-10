#ifndef DEPLOYMENT_H
#define DEPLOYMENT_H

#include <QObject>
#include "../../Base/diagrambase.h"
#include "../../Base/diagramcommand.h"

class Deployment: public DiagramBase
{
    Q_OBJECT

public:
    Deployment();

private slots:
    void  addNode();

    void  addArtifact();

    void  addDataBase();

    void  addComponent();

private:
    ShapeCommand *cmd;
};

#endif // DEPLOYMENT_H
