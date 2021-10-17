#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <QObject>
#include "../../Base/diagrambase.h"
#include "../../Base/diagramcommand.h"

class Sequence: public DiagramBase
{
    Q_OBJECT

public:
    Sequence();

    ~Sequence();

private slots:
    void  addLifeLine();

    void  addActor();

    void  addActivationOccurrence();

    void  addDeleteMessage();

private:
    ShapeCommand *cmd;
};

#endif // SEQUENCE_H
