#include <Enemy.h>
#include <Projectile2.h>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QRandomGenerator>
#include "Game.h"

extern Game * game;

Enemy::Enemy(int dataitem [20][35], QString x,QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    e = x;

    if (x == "gunman"){
    row=2;
    column=14;

    QPixmap e1("/Users/omar_bahgat/Documents/Game/gunmanL.png");
    e1=e1.scaledToWidth(40);
    e1=e1.scaledToHeight(40);
    setPixmap(e1);
    setPos(0+40*column,40+40*row);
    for(int i=0;i<20;i++)
        for (int j=0;j<35;j++)
            data[i][j]=dataitem[i][j];
    }
else if (x == "archer"){
    row = 3;
    column = 16;
    QPixmap e2("/Users/omar_bahgat/Documents/Game/archerL.png");
    e2=e2.scaledToWidth(40);
    e2=e2.scaledToHeight(40);
    setPixmap(e2);
    setPos(0+40*column,40+40*row);

    for(int i=0;i<20;i++)
        for (int j=0;j<35;j++)
            data[i][j]=dataitem[i][j];
    }

   //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(500);
}

void Enemy::move(){
    int rand = QRandomGenerator::global()->generate() % 4;
    int rand2 = QRandomGenerator::global()->generate() % 4;

    if (rand == 0 && data[row-1][column]!=-11 && data[row-1][column]!=99 && data[row][column]!=-12){
        row--;
        setPos(40+40*column,40+40*row);
    }
    else if(rand == 1 && data[row+1][column]!=-11 && data[row+1][column]!=99 && data[row][column]!=-13){
        row++;
        setPos(40+40*column,40+40*row);
    }
    else if (rand == 2 && data[row][column-1]!=-11 && data[row][column-1]!=99){
        last = 5;
        column--;


        if (e == "gunman"){
        QPixmap e1("/Users/omar_bahgat/Documents/Game/gunmanL.png");
        e1=e1.scaledToWidth(40);
        e1=e1.scaledToHeight(40);
        setPixmap(e1);
        }
        else if (e == "archer"){
            QPixmap e2("/Users/omar_bahgat/Documents/Game/archerL.png");
            e2=e2.scaledToWidth(40);
            e2=e2.scaledToHeight(40);
            setPixmap(e2);
        }

        setPos(40+40*column,40+40*row);
    }
    else if (rand == 3 && data[row][column+1]!=-11 && data[row][column+1]!=99 && data[row][column]!=-14){
        last = 15;
        column++;

        if (e == "gunman"){
        QPixmap e1("/Users/omar_bahgat/Documents/Game/gunmanR.png");
        e1=e1.scaledToWidth(40);
        e1=e1.scaledToHeight(40);
        setPixmap(e1);
        }
        else if (e == "archer") {
            QPixmap e2("/Users/omar_bahgat/Documents/Game/archerR.png");
            e2=e2.scaledToWidth(40);
            e2=e2.scaledToHeight(40);
            setPixmap(e2);
        }
        setPos(40+40*column,40+40*row);
    }
      if (rand2 == 0 || rand2 == 1 || rand2 == 3)
      shoot();

}

void Enemy::shoot(){
    Projectile2 * proj = new Projectile2(last);
    proj->setPos(x()+30,y()+10);
    scene()->addItem(proj);
}

