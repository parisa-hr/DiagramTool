#ifndef USECASE_H
#define USECASE_H

#include <QObject>
#include "../../Base/diagrambase.h"
#include "../../Base/diagramcommand.h"

class UseCase: public DiagramBase
{
    Q_OBJECT

public:
    UseCase();

    ~UseCase();

private slots:
    void  addActor();

    void  addUsecase();

    void  addSystemBoundry();

private:
    ShapeCommand *cmd;
};

#endif // USECASE_H
