#include "trex.h"
#include "cactus.h"
#include <QTimer>
#include <qelapsedtimer.h>
#include <QPropertyAnimation>
#include "game.h"
#define  duration 5
#define min_dalay 3000  //minimum delay between showing up two Cactus on screen
//#include <QMediaPlayer>
TRex::TRex(QObject *parent)
    : QObject{parent}
{}

TRex::TRex(Game *game)
    :g(game)
{
    setPixmap(QPixmap(":/images/trex.png"));
    setPos(dinoX,dinoY);
    timer1=new QTimer;
    connect(timer1,SIGNAL(timeout()),this,SLOT(spawn()));
    timer1->start(min_dalay);
}

void TRex::jump()
{
   qDebug("try to jump1");
    if(y()==dinoY){
        QPropertyAnimation *anim = new QPropertyAnimation(this, "pos");

                anim->setDuration(1500);
                anim->setStartValue(pos());
                anim->setEndValue(QPointF(pos().x(), pos().y() - height_of_jump));
               //  qDebug("try to jump2");
                anim->start(QAbstractAnimation::DeleteWhenStopped);
              //   qDebug("try to jump3");
        timer= new QTimer;
        timer->singleShot(1500,this,SLOT(land()));
    }
}

void TRex::timeout()
{
    if(jumpTime->elapsed() <= duration )
    {
        setPos(x(),y()-height_of_jump);
    }
    else
        jumpD->stop();
}
void TRex::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Up)
        jump();
}

void TRex::stoptiemr1()
{
    timer1->stop();
}


void TRex::land()
{
    QPropertyAnimation *anim = new QPropertyAnimation(this, "pos");
            anim->setDuration(1500);
            anim->setStartValue(pos());
            anim->setEndValue(QPointF(pos().x(), pos().y() + height_of_jump));
            anim->start(QAbstractAnimation::DeleteWhenStopped);
}
void TRex::spawn()
{
    int delay=(rand()%20 +10)*200;
    QTimer *timer=new QTimer;
    timer->singleShot(delay,this,SLOT(makeCactus()));
}

void TRex::makeCactus()
{
    Cactus *Barrier=new Cactus(g,g->scene);
    scene()->addItem(Barrier);
}

