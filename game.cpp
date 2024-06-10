#include "game.h"
#include <QApplication>
#include <QGraphicsView>
#include <QBrush>
#include <QImage>
#include <QDialogButtonBox>
#include <QWidget>
#include <QButtonGroup>
Game::Game()
{
    isRunning=true;
    scene = new QGraphicsScene();
       scene->setSceneRect(0,0,800,600);
       scene->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    player=new TRex(this);
   scene->addItem(player);
   player->setFlag(QGraphicsItem::ItemIsFocusable);
   player->setFocus();
     score=new Score(this);
    scene->addItem(score);
    QGraphicsView * view = new QGraphicsView(scene);
      view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
         view->setFixedSize(800,600);
         scene->setSceneRect(0,0,800,600);
         view->show();
}

//void Game::collison(/*QString mess*/)
//{
//QDialogButtonBox felan(QDialogButtonBox::Ok);
//}


