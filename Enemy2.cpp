#include <Enemy2.h>
#include <Projectile2.h>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QRandomGenerator>
#include "Game.h"

extern Game * game;

Enemy2::Enemy2(int dataitem [20][35], QString x,QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    e = x;
 if (x == "soldier"){
        row = 9;
        column = 4;
        QPixmap e3("/Users/omar_bahgat/Documents/Game/soldierR.png");
        e3=e3.scaledToWidth(40);
        e3=e3.scaledToHeight(40);
        setPixmap(e3);
        setPos(0+40*column,40+40*row);

        for(int i=0;i<20;i++)
            for (int j=0;j<35;j++)
                data[i][j]=dataitem[i][j];
}
 else if (x == "police"){
        row = 8;
        column = 3;
        QPixmap e3("/Users/omar_bahgat/Documents/Game/policeR.png");
        e3=e3.scaledToWidth(40);
        e3=e3.scaledToHeight(40);
        setPixmap(e3);
        setPos(0+40*column,40+40*row);

        for(int i=0;i<20;i++)
            for (int j=0;j<35;j++)
                data[i][j]=dataitem[i][j];
}

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(500);
}

void Enemy2::move(){
    int rand = QRandomGenerator::global()->generate() % 4;
    int rand2 = QRandomGenerator::global()->generate() % 4;

        if (rand == 0 && data[row-1][column]!=-11 && data[row-1][column]!=99 && data[row-1][column]!=-15&& data[row-1][column]!=-16 && data[row-1][column]!=-17&& data[row-1][column]!=-18 && data[row][column]!=-12 && (data[row-1][column]==-12 || data[row-1][column]==-14)){
        row--;
        setPos(40+40*column,40+40*row);
        if (e == "soldier") {
                    QPixmap e3("/Users/omar_bahgat/Documents/Game/lava.png");
                    e3=e3.scaledToWidth(30);
                    e3=e3.scaledToHeight(30);
                    setPixmap(e3);
                }
        else if (e == "police") {
                    QPixmap e4("/Users/omar_bahgat/Documents/Game/lava.png");
                    e4=e4.scaledToWidth(30);
                    e4=e4.scaledToHeight(30);
                    setPixmap(e4);
                }
    }

    else if (rand == 0 && data[row-1][column]!=-11 && data[row-1][column]!=99 &&  data[row-1][column]!=-15&& data[row-1][column]!=-16 && data[row-1][column]!=-17&& data[row-1][column]!=-18 && data[row][column]!=-12){
        row--;
        if (e == "soldier") {
                    QPixmap e3("/Users/omar_bahgat/Documents/Game/SoldierL.png");
                    e3=e3.scaledToWidth(40);
                    e3=e3.scaledToHeight(40);
                    setPixmap(e3);
                }
        else if (e == "police") {
                    QPixmap e4("/Users/omar_bahgat/Documents/Game/policeL.png");
                    e4=e4.scaledToWidth(40);
                    e4=e4.scaledToHeight(40);
                    setPixmap(e4);
                }
        setPos(40+40*column,40+40*row);
    }


    else if (rand == 1 && data[row+1][column]!=-11 && data[row+1][column]!=99 && data[row+1][column]!=-15&& data[row+1][column]!=-16 && data[row+1][column]!=-17&& data[row+1][column]!=-18 && data[row][column]!=-13 && (data[row+1][column]==-13 || data[row+1][column]==-14 )){
        row++;
        if (e == "soldier") {
                    QPixmap e3("/Users/omar_bahgat/Documents/Game/lava.png");
                    e3=e3.scaledToWidth(30);
                    e3=e3.scaledToHeight(30);
                    setPixmap(e3);
                }
        else if (e == "police") {
                    QPixmap e4("/Users/omar_bahgat/Documents/Game/lava.png");
                    e4=e4.scaledToWidth(30);
                    e4=e4.scaledToHeight(30);
                    setPixmap(e4);
                }
        setPos(40+40*column,40+40*row);
    }

    else if (rand == 1 && data[row+1][column]!=-11 && data[row+1][column]!=99 && data[row+1][column]!=-15&& data[row+1][column]!=-16 && data[row+1][column]!=-17&& data[row+1][column]!=-18 && data[row][column]!=-13){
        row++;
        if (e == "soldier") {
                    QPixmap e3("/Users/omar_bahgat/Documents/Game/SoldierL.png");
                    e3=e3.scaledToWidth(40);
                    e3=e3.scaledToHeight(40);
                    setPixmap(e3);
                }
        else if (e == "police") {
                    QPixmap e3("/Users/omar_bahgat/Documents/Game/policeL.png");
                    e3=e3.scaledToWidth(40);
                    e3=e3.scaledToHeight(40);
                    setPixmap(e3);
                }
        setPos(40+40*column,40+40*row);
    }


    else if (rand == 2 && data[row][column-1]!=-11 && data[row][column-1]!=99 & data[row-1][column]!=-15&& data[row][column-1]!=-16 && data[row][column-1]!=-17&& data[row][column-1]!=-18 && (data[row][column-1]==-12 || data[row][column-1]==-13)){
        last = 5;
        column--;
        if (e == "soldier") {
                    QPixmap e3("/Users/omar_bahgat/Documents/Game/lava.png");
                    e3=e3.scaledToWidth(30);
                    e3=e3.scaledToHeight(30);
                    setPixmap(e3);
                }
        else if (e == "police") {
                    QPixmap e4("/Users/omar_bahgat/Documents/Game/lava.png");
                    e4=e4.scaledToWidth(30);
                    e4=e4.scaledToHeight(30);
                    setPixmap(e4);
                }
        setPos(40+40*column,40+40*row);
    }

    else if (rand == 2 && data[row][column-1]!=-11 && data[row][column-1]!=99 && data[row][column-1]!=-15&& data[row][column-1]!=-16 && data[row][column-1]!=-17&& data[row][column-1]!=-18 ){
        last = 5;
        column--;
        if (e == "soldier") {
                    QPixmap e3("/Users/omar_bahgat/Documents/Game/SoldierL.png");
                    e3=e3.scaledToWidth(40);
                    e3=e3.scaledToHeight(40);
                    setPixmap(e3);
                }
        else if (e == "police") {
                    QPixmap e4("/Users/omar_bahgat/Documents/Game/policeL.png");
                    e4=e4.scaledToWidth(40);
                    e4=e4.scaledToHeight(40);
                    setPixmap(e4);
                }
        setPos(40+40*column,40+40*row);
    }


    else if (rand == 3 && data[row][column+1]!=-11 && data[row][column+1]!=99 && data[row][column+1]!=-15&& data[row][column+1]!=-16 && data[row][column+1]!=-17&& data[row][column+1]!=-18 && data[row][column]!=-14 && (data[row][column+1]==-12 || data[row][column+1]==-13 || data[row][column+1]==-14)){
        last = 15;
        column++;
       if (e == "soldier") {
            QPixmap e3("/Users/omar_bahgat/Documents/Game/lava.png");
            e3=e3.scaledToWidth(30);
            e3=e3.scaledToHeight(30);
            setPixmap(e3);
        }
       else if (e == "police") {
            QPixmap e4("/Users/omar_bahgat/Documents/Game/lava.png");
            e4=e4.scaledToWidth(30);
            e4=e4.scaledToHeight(30);
            setPixmap(e4);
        }
        setPos(40+40*column,40+40*row);
    }
     else if (rand == 3 && data[row][column+1]!=-11 && data[row][column+1]!=99 && data[row][column +1]!=-15&& data[row][column+1]!=-16 && data[row][column+1]!=-17&& data[row][column+1]!=-18 && data[row][column]!=-14){
         last = 15;
         column++;
        if (e == "soldier") {
             QPixmap e3("/Users/omar_bahgat/Documents/Game/soldierR.png");
             e3=e3.scaledToWidth(40);
             e3=e3.scaledToHeight(40);
             setPixmap(e3);
         }
        else if (e == "police") {
             QPixmap e4("/Users/omar_bahgat/Documents/Game/policeR.png");
             e4=e4.scaledToWidth(40);
             e4=e4.scaledToHeight(40);
             setPixmap(e4);
         }
         setPos(40+40*column,40+40*row);
     }
      if (rand2 == 0 || rand2 == 1 || rand2 == 3)
      shoot();

}

void Enemy2::shoot(){
    Projectile2 * proj = new Projectile2(last);
    proj->setPos(x()+30,y()+10);
    scene()->addItem(proj);
}
