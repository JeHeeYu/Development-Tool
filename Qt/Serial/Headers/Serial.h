#ifndef SERIAL_H
#define SERIAL_H

#include <QQuickView>
#include <QObject>


class Serial: public QObject
{
public:
    Q_OBJECT

public:
    Serial();
    ~Serial();

public:


private:
    void GetPortList();
};

#endif // SERIAL_H
