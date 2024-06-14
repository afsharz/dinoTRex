#ifndef GAME_H
#define GAME_H
#include "trex.h"
#include "score.h"
#include "cactus.h"
#include <QGraphicsScene>
#include <QObject>
class Game
    :public QObject
{
    Q_OBJECT
public:
    Game();
    ~Game();
    void stopCloudTimer();
    TRex *player;
    Score *score;
    QGraphicsScene *scene;
public slots:
    void generateCloud();
private:
    QTimer *cloudTimer;

bool isRunning;
};

#endif // GAME_H
