#include "score.h"
#include <QString>
#include <QFont>
#include "game.h"

Score::Score(Game *g)
    :g(g)
{
    score=0;
    setPlainText(QString("SCORE : ")+QString::number(score));
    setFont(  QFont ("Berlin Sans FB",20,QFont::Bold));
    setDefaultTextColor(Qt::black);
}

void Score::increase()
{
    score++;
    setPlainText(QString("SCORE : ")+QString::number(score));
}

int Score::getScore()
{
return score;
}
