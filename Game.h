#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include <Enemy.h>
#include <Enemy2.h>
#include <room3.h>
//#include <Health.h>


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    player * p;
    Enemy * e1;
    Enemy * e2;
    Enemy2 * e3;
    Enemy2 * e4;
    room3 * e5;
    room3 * e6;
    room3 * e7;
    room3 * e8;
    //Health * health;
    QGraphicsPixmapItem dataimage[20][35];





};

#endif // GAME_H
