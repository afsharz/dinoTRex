#include "trex.h"
#include "cactus.h"
#include <QTimer>
//#include <QMediaPlayer>

TRex::TRex(QObject *parent)
    : QObject{parent}
{

    setPixmap(QPixmap(":/images/trex.png"));
    setPos(dinoX,dinoY);
//Cactus cac;

}

void TRex::jump()
{
    setPos(x(),y()-height_of_jump);
   timer= new QTimer;
    timer->singleShot(200,this,SLOT(land()));

}
void TRex::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Up)
        this->jump();
}

void TRex::land()
{
setPos(x(),y()+height_of_jump);
}
