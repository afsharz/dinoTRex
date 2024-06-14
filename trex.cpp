#include "trex.h"
#include "cactus.h"
#include <QTimer>
#include <qelapsedtimer.h>
#include <QPropertyAnimation>
#include <QUrl>
#include <QAudioOutput>
#include "game.h"
#define  duration 5
#define min_dalay 2500  //minimum delay between showing up two Cactus on screen
#define jumpDuration 650

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
    jumpsound=new QMediaPlayer(this);
    jumpsound->setSource(QUrl("qrc:/sounds/cartoon-jump-6462.mp3"));
    QAudioOutput* audioOutput = new QAudioOutput(this);
    audioOutput->setVolume(1.0); // Set volume to maximum (1.0 corresponds to 100%)
    jumpsound->setAudioOutput(audioOutput);
}

void TRex::jump()
{

    if(pos().y()==dinoY){

        QPropertyAnimation *anim = new QPropertyAnimation(this, "pos");
        anim->setDuration(jumpDuration);
        anim->setStartValue(pos());
        anim->setEndValue(QPointF(pos().x(), pos().y() - height_of_jump));
        connect(anim,SIGNAL(finished()),this,SLOT(land()));
        anim->start(QAbstractAnimation::DeleteWhenStopped);
        if (jumpsound->playbackState() == QMediaPlayer::PlayingState){
            jumpsound->setPosition(0);
        }
        else if (jumpsound->playbackState() == QMediaPlayer::StoppedState){

            jumpsound->play();
        }
    }
}


void TRex::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Up)
        jump();
}

void TRex::stoptiemr1()
{
    timer1->stop();
      for (QTimer *timer : qAsConst(singleShotTimers))
        timer->stop();
        delete timer;
}


void TRex::land()
{
    QPropertyAnimation *anim = new QPropertyAnimation(this, "pos");
            anim->setDuration(jumpDuration);
            anim->setStartValue(pos());
            anim->setEndValue(QPointF(pos().x(), pos().y() + height_of_jump));
            anim->start(QAbstractAnimation::DeleteWhenStopped);
}
void TRex::spawn()
{
    int delay = (rand() % 20 + 10) * 200;
QTimer *timer = new QTimer;
connect(timer, &QTimer::timeout, this, &TRex::makeCactus);
singleShotTimers.append(timer);
timer->setSingleShot(true);
timer->start(delay);
}

void TRex::makeCactus(){
    Cactus *Barrier=new Cactus(g,g->scene);
    scene()->addItem(Barrier);}
