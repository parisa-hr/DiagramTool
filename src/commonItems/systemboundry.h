#ifndef SYSTEMBOUNDRY_H
#define SYSTEMBOUNDRY_H

#include <QObject>

class SystemBoundry : public QObject
{
    Q_OBJECT
public:
    explicit SystemBoundry(QObject *parent = nullptr);

signals:

};

#endif // SYSTEMBOUNDRY_H
