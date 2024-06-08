#include "widget.h"
#include "trex.h"
#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsView>
#include <QBrush>
#include <QImage>
#include <QWidget>
#include "cactus.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene;
    scene = new QGraphicsScene();
       scene->setSceneRect(0,0,800,600);
       scene->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    TRex *player;
    player=new TRex;
   scene->addItem(player);
   player->setFlag(QGraphicsItem::ItemIsFocusable);
   player->setFocus();
   //QTimer *tim= new QTimer;
   Cactus *cac=new Cactus;
   scene->addItem(cac);
    QGraphicsView * view = new QGraphicsView(scene);
      view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

         view->setFixedSize(800,600);
         scene->setSceneRect(0,0,800,600);
       //  player->setOffset(100,100);
   //  player->setPos(view->width()/7,view->height() - 150);
    // qDebug(" x=%d      y=%d",view->width()/7,view->height() - 150);
       view->show();
    return a.exec();
}
