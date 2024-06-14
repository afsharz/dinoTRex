#include "cloud.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
cloud::cloud()
{
    delay=(rand()%10)*20;
    switch(rand()%2)
    {
    case 0:
    { setPixmap(QPixmap(":/images/cloud.png"));break;}

    case 1:
    {
        setPixmap(QPixmap(":/images/cloud2.png"));
        break;
    }
    }
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(delay);
}

cloud::~cloud()
{
    delete timer;
}

void cloud::stopTimer()
{
    timer->stop();
}

void cloud::move()
{
    if(x()+this->boundingRect().width()>0)
        this->setPos(x()-5,y());

    else if(x()+this->boundingRect().width()<=0)
    {
      //  scene()->removeItem(this);
        delete this;
    }
}
