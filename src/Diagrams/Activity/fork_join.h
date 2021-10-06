#ifndef FORK_JOIN_H
#define FORK_JOIN_H

#include <QObject>

class Fork_Join : public QObject
{
    Q_OBJECT
public:
    explicit Fork_Join(QObject *parent = nullptr);

signals:

};

#endif // FORK_JOIN_H
