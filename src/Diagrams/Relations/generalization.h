#ifndef GENERALIZATION_H
#define GENERALIZATION_H

#include <QObject>

class Generalization : public QObject
{
    Q_OBJECT
public:
    explicit Generalization(QObject *parent = nullptr);

signals:

};

#endif // GENERALIZATION_H
