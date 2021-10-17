#ifndef DELETEMESSAGE_H
#define DELETEMESSAGE_H

#include <QObject>

class DeleteMessage : public QObject
{
    Q_OBJECT
public:
    explicit DeleteMessage(QObject *parent = nullptr);

signals:

};

#endif // DELETEMESSAGE_H
