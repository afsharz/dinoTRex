#include "game.h"
#include <QApplication>
#include <QGraphicsView>
#include <QBrush>
#include <QImage>
#include <QDialogButtonBox>
#include <QWidget>
#include <QButtonGroup>
#include "cloud.h"
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
    cloudTimer=new QTimer;
    connect(cloudTimer,SIGNAL(timeout()),this,SLOT(generateCloud()));
    cloudTimer->start(4000);
    view->show();
}

Game::~Game()
{
    delete player;
    delete score ;
    delete scene;
}

void Game::stopCloudTimer()
{
    cloudTimer->stop();
}

void Game::generateCloud()
{
    cloud *c=new cloud;
    c->setPos(scene->width(),200);
    scene->addItem(c);
}

//void Game::collison(/*QString mess*/)
//{
//QDialogButtonBox felan(QDialogButtonBox::Ok);
//}


