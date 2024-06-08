#include "widget.h"
#include "trex.h"
#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsView>
#include <QBrush>
#include <QImage>
#include <QWidget>
#include "cactus.h"
#include "score.h"
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
   Cactus *cac =new Cactus(0,scene);
    scene->addItem(cac);
    Score score;
    scene->addItem(&score);
    QGraphicsView * view = new QGraphicsView(scene);
      view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
         view->setFixedSize(800,600);
         scene->setSceneRect(0,0,800,600);
       view->show();
    return a.exec();
}
