#ifndef COMPOSITION_H
#define COMPOSITION_H

#include <QObject>

class Composition : public QObject
{
    Q_OBJECT
public:
    explicit Composition(QObject *parent = nullptr);

signals:

};

#endif // COMPOSITION_H
