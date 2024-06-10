#ifndef TREX_H
#define TREX_H
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QElapsedTimer>
#define height_of_jump 200
#define dinoX 114
#define dinoY 450

class Game;
class TRex : public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
     Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    explicit TRex(QObject *parent = nullptr);
    TRex(Game *game);
    void move();
    void keyPressEvent(QKeyEvent *event)override;
    void stoptiemr1();
    private:
    QTimer *timer;
    QTimer *timer1;
    Game *g;
    QList<QTimer*> singleShotTimers;
    signals:
private slots:
 void land();
 void jump();
void makeCactus();
    void spawn();
};

#endif // TREX_H
