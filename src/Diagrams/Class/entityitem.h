#ifndef ENTITYITEM_H
#define ENTITYITEM_H

#include <QObject>

class EntityItem : public QObject
{
    Q_OBJECT
public:
    explicit EntityItem(QObject *parent = nullptr);

signals:

};

#endif // ENTITYITEM_H
