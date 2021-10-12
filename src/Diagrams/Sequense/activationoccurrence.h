#ifndef ACTIVATIONOCCURRENCE_H
#define ACTIVATIONOCCURRENCE_H

#include <QObject>

class ActivationOccurrence : public QObject
{
    Q_OBJECT
public:
    explicit ActivationOccurrence(QObject *parent = nullptr);

signals:

};

#endif // ACTIVATIONOCCURRENCE_H
