#ifndef CACTUS_H
#define CACTUS_H
#include <QGraphicsPixmapItem>
#include <QObject>
#define length_of_move 5
class Cactus
        :public QObject,public QGraphicsPixmapItem
{
      Q_OBJECT
public:
    Cactus(QGraphicsItem *parent = 0,QGraphicsScene *scene=0);
private slots:
    void move();
};

#endif // CACTUS_H
