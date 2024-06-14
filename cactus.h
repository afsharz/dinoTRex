#ifndef CACTUS_H
#define CACTUS_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QElapsedTimer>

#define length_of_move 5
class Game;
class Cactus
        :public QObject,public QGraphicsPixmapItem
{
      Q_OBJECT
public:
    Cactus(QGraphicsItem *parent = 0);
    Cactus(Game *g,QGraphicsScene *scene);
    ~Cactus();
    void stopTimer();
private:
    Game *g;
QTimer *timer;
private slots:
    void move();
};

#endif // CACTUS_H
