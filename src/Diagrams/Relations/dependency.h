#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include <QObject>

class Dependency : public QObject
{
    Q_OBJECT
public:
    explicit Dependency(QObject *parent = nullptr);

signals:

};

#endif // DEPENDENCY_H
