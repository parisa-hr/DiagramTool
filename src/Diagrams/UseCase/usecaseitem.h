#ifndef USECASEOBJ_H
#define USECASEOBJ_H

#include <QObject>

class UseCaseItem: public QObject
{
    Q_OBJECT

public:
    explicit UseCaseItem(QObject *parent = nullptr);

signals:
};

#endif // USECASEOBJ_H
