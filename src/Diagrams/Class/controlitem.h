#ifndef CONTROLITEM_H
#define CONTROLITEM_H

#include <QObject>

class ControlItem : public QObject
{
    Q_OBJECT
public:
    explicit ControlItem(QObject *parent = nullptr);

signals:

};

#endif // CONTROLITEM_H
