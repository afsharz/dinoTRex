#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
class Game;
class Score
        :public QGraphicsTextItem
{
public:
    Score(Game *g);
    void increase();
    int getScore();
private:
    int score;
    Game *g;
};

#endif // SCORE_H
