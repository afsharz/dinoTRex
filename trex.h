#ifndef TREX_H
#define TREX_H
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#define height_of_jump 150
#define dinoX 114
#define dinoY 450

class TRex : public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit TRex(QObject *parent = nullptr);
   void jump();
   void move();

void keyPressEvent(QKeyEvent *event)override;
private:
QTimer *timer;
signals:

private slots:
 void land();
};

#endif // TREX_H
