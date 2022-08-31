#include <Projectile2.h>
#include <Enemy.h>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QList>
#include "Game.h"
#include <mainwindow.h>
#include <QApplication>


extern Game * game;

Projectile2::Projectile2(int last, QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent){
    lastMove = last;

    //draw bullet
    QPixmap bullet("/Users/omar_bahgat/Documents/Game/bullet.png");
    bullet=bullet.scaledToWidth(15);
    bullet=bullet.scaledToHeight(15);
    setPixmap(bullet);

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));     //move function will be called periodically every 15ms
    timer->start(15);

}

void Projectile2::move(){
    int static health = 5;

    QList <QGraphicsItem *> collidingObjects = collidingItems();
    for (int i = 0, n = collidingObjects.size(); i < n; ++i){
        if(typeid(*(collidingObjects[i])) == typeid(player)){
            health--;
           if (health <=0){
            scene()->removeItem(collidingObjects[i]);
//            //QApplication::quit();
           }


            scene()->removeItem(this);
            //delete collidingObjects[i];
            //delete this;
            //return;
        }
    }
    if (lastMove == 5)
        setPos(x()-5,y());
    else if (lastMove == 15)
        setPos(x()+5,y());
    else
        setPos(x()+5,y());


 if (pos().x() > 800)
    delete this;

}
