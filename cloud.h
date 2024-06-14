#ifndef CLOUD_H
#define CLOUD_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QElapsedTimer>

class cloud
:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    cloud();
    ~cloud();
    void stopTimer();

public slots:
    void move();

private:
    int delay;
    QTimer *timer;
};

#endif // CLOUD_H
