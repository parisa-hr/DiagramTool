#ifndef CLASSITEM_H
#define CLASSITEM_H

#include <QObject>

class classItem : public QObject
{
    Q_OBJECT
public:
    explicit classItem(QObject *parent = nullptr);

signals:

};

#endif // CLASSITEM_H
