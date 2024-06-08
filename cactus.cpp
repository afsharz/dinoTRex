#include "cactus.h"
#include "qtimer.h"
#include "trex.h"
#include <QList>
#include <stdlib.h>
#include <QGraphicsScene>
Cactus::Cactus(QGraphicsItem *parent,QGraphicsScene *scene)
    : QObject(), QGraphicsPixmapItem(parent)
{
int random=rand()%2;
QTimer *timer;
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

QList<QGraphicsItem *> scene_items;
   QGraphicsItem *item = nullptr;
   scene_items = scene->items(Qt::AscendingOrder);
   for (int i = 0; i < scene_items.size(); i++)
   {
       item = scene_items.at(i);
       if (qgraphicsitem_cast<TRex*>(item))
           break;
   }
    int x=scene->width();
    QRectF trexRect = item->sceneBoundingRect();
           int y = trexRect.bottom() - boundingRect().height();
    setPos(x,y+5);//+5 is for cactus to be a little downer
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
