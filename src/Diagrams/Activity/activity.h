#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QObject>
#include "../../Base/diagrambase.h"


class Activity: public DiagramBase
{
    Q_OBJECT

public:
    Activity();

    void  addActivityItem();

    void  addStartNode();

    void  addFinalNode();

    void  addDecisionNode();

signals:
public slots:
};

#endif // ACTIVITY_H
