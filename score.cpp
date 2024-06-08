#include "score.h"
#include <QString>
#include <QFont>
//#include <QColor>
Score::Score()
{
    score=0;
    setPlainText(QString("SCORE : ")+QString::number(score));
    setFont(  QFont ("Berlin Sans FB",20,QFont::Bold));
    setDefaultTextColor(Qt::black);
}

int Score::getScore()
{

}
