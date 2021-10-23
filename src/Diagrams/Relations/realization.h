#ifndef REALIZATION_H
#define REALIZATION_H

#include <QObject>

class Realization : public QObject
{
    Q_OBJECT
public:
    explicit Realization(QObject *parent = nullptr);

signals:

};

#endif // REALIZATION_H
