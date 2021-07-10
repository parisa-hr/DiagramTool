#ifndef USECASE_H
#define USECASE_H

#include <QObject>
#include "../../Base/diagrambase.h"

class UseCase: public DiagramBase
{
    Q_OBJECT

public:
    explicit UseCase();

    void  addActor();

    void  addUsecase();

    void  addSystemBoundry();

signals:
public slots:
};

#endif // USECASE_H
