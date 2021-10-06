#ifndef INITIALNODE_H
#define INITIALNODE_H

#include <QObject>

class InitialNode : public QObject
{
    Q_OBJECT
public:
    explicit InitialNode(QObject *parent = nullptr);

signals:

};

#endif // INITIALNODE_H
