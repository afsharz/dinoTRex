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
#include "game.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
Game *game=new Game;
    return a.exec();
}
