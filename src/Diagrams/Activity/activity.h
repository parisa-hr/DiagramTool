#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QObject>
#include "../../Base/diagrambase.h"
#include "../../Base/diagramcommand.h"


class Activity: public DiagramBase
{
    Q_OBJECT

public:
    Activity();

    ~Activity();

    void  addActivityItem();

    void  addStartNode();

    void  addFinalNode();

    void  addDecisionNode();

    void  addSwimLane();

private:
    ShapeCommand *cmd;
};

#endif // ACTIVITY_H
