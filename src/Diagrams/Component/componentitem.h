#ifndef COMPONENTITEM_H
#define COMPONENTITEM_H

#include <QObject>

class ComponentItem : public QObject
{
    Q_OBJECT
public:
    explicit ComponentItem(QObject *parent = nullptr);

signals:

};

#endif // COMPONENTITEM_H
