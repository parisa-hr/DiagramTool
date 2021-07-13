#ifndef DECISIONNODE_H
#define DECISIONNODE_H

#include <QObject>

class DecisionNode : public QObject
{
    Q_OBJECT
public:
    explicit DecisionNode(QObject *parent = nullptr);

signals:

};

#endif // DECISIONNODE_H
