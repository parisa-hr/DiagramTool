#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QObject>
#include "../../Base/diagrambase.h"


class Activity: public DiagramBase
{
  Q_OBJECT

public:
  explicit Activity();

   void addActivityItem();
   void addStartNode();
   void addFinalNode();


signals:
public slots:
};

#endif // ACTIVITY_H
