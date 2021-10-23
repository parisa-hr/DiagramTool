#ifndef AGGREGATION_H
#define AGGREGATION_H

#include <QObject>

class Aggregation : public QObject
{
    Q_OBJECT
public:
    explicit Aggregation(QObject *parent = nullptr);

signals:

};

#endif // AGGREGATION_H
