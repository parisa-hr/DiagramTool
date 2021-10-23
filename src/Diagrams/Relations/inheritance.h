#ifndef INHERITANCE_H
#define INHERITANCE_H

#include <QObject>

class Inheritance : public QObject
{
    Q_OBJECT
public:
    explicit Inheritance(QObject *parent = nullptr);

signals:

};

#endif // INHERITANCE_H
