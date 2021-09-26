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

    void  addActor();

    void  addUsecase();

    void  addSystemBoundry();

public slots:
    void  showw();

private:
    ShapeCommand *cmd;
};

#endif // USECASE_H
