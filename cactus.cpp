#include "cactus.h"
#include "qtimer.h"
#include "trex.h"
#include <QList>
#include <stdlib.h>
#include <QGraphicsScene>
#include "game.h"
#include <QMessageBox>
#include <QMainWindow>
#define CacX scene->width()
#define CacY dinoY+ g->player->sceneBoundingRect().height() - boundingRect().height()
Cactus::Cactus(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent)
{}
Cactus::Cactus(Game *g,QGraphicsScene *scene)
    :g(g)
{
int random=rand()%2;
switch (random)
{
    case 0:
    {
    setPixmap(QPixmap(":/images/cactus1.png"));
    break;
    }
    case 1:
    {
    setPixmap(QPixmap(":/images/cactus2.png"));
    break;
    }
}
    setPos(CacX,CacY+5);//+5 واسه اینکه کاکتوس یه ذره پایین تر از دایناسور باشه
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);
}

void Cactus::move()
{
    bool flag=false;
       QList<QGraphicsItem *> colliding_items = collidingItems();
       for(int i=0;i<colliding_items.size();i++)
       {
           if (typeid(*(colliding_items.at(i)))==typeid(TRex))
           {
                (g->player)->stoptiemr1();
               flag=true;
               QList<QGraphicsItem *> items=scene()->items();
               for(int i=0;i<items.size();i++)
               {
                   if(typeid(*items.at(i))==typeid(Cactus))
                      dynamic_cast<Cactus*>(items.at(i))->timer->stop();
           //  QMessageBox::information(nullptr, "Game Over", "You Failed the Game!");

               }

           }
       }
    if(x()+this->boundingRect().width()>0)
        this->setPos(x()-length_of_move,y());
    else if(x()+this->boundingRect().width()<=0)
    {
        g->score->increase();
        scene()->removeItem(this);
        delete this;
    }

}
