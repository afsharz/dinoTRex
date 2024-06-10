#ifndef GAME_H
#define GAME_H
#include "trex.h"
#include "score.h"
#include "cactus.h"
#include <QGraphicsScene>

class Game
{
public:
    Game();
TRex *player;
Score *score;
QGraphicsScene *scene;
private:

bool isRunning;
};

#endif // GAME_H
