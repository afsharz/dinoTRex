#include "cactus.h"
#include "qgraphicsscene.h"
#include "qtimer.h"

Cactus::Cactus(QObject *parent)
{
int random=rand()%2;
QTimer *timer;
switch (random)
{
    case 1:
    {
    setPixmap(QPixmap(":/images/cactus1.png"));
    break;
    }
    case 0:
    {
    setPixmap(QPixmap(":/images/cactus2.png"));
    break;
    }
}
    setPos(500,500);
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);
}

void Cactus::move()
{
    if(x()>0)
        this->setPos(x()-length_of_move,y());
    else if(x()-20<=0)
    {
        scene()->removeItem(this);
        delete this;
    }

}
