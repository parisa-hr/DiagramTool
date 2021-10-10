#ifndef ARTIFACT_H
#define ARTIFACT_H

#include <QObject>

class Artifact : public QObject
{
    Q_OBJECT
public:
    explicit Artifact(QObject *parent = nullptr);

signals:

};

#endif // ARTIFACT_H
