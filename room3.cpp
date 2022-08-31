#include <room3.h>
#include <Projectile2.h>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QRandomGenerator>
#include "Game.h"

extern Game * game;

room3::room3(int dataitem [20][35], QString x,QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    e = x;

    if (x == "gunman"){
    row=17;
    column=3;

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
    row = 17;
    column = 5;
    QPixmap e2("/Users/omar_bahgat/Documents/Game/archerL.png");
    e2=e2.scaledToWidth(40);
    e2=e2.scaledToHeight(40);
    setPixmap(e2);
    setPos(0+40*column,40+40*row);

    for(int i=0;i<20;i++)
        for (int j=0;j<35;j++)
            data[i][j]=dataitem[i][j];
    }
else if (x == "soldier"){
        row = 17;
        column = 7;
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
            row = 17;
            column = 9;
            QPixmap e3("/Users/omar_bahgat/Documents/Game/soldierR.png");
            e3=e3.scaledToWidth(40);
            e3=e3.scaledToHeight(40);
            setPixmap(e3);
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

void room3::move(){
    int rand = QRandomGenerator::global()->generate() % 4;
    int rand2 = QRandomGenerator::global()->generate() % 4;

    if (rand == 0 && data[row-1][column]!=-11 && data[row-1][column]!=99 && data[row-1][column]!=-13 && data[row-1][column]!=-14){
        row--;
        setPos(40+40*column,40+40*row);
    }
    else if(rand == 1 && data[row+1][column]!=-11 && data[row+1][column]!=99 ){
        row++;
        setPos(40+40*column,40+40*row);
    }
    else if (rand == 2 && data[row][column-1]!=-11 && data[row][column-1]!=99 && data[row][column]!=-12 && data[row][column]!=-13){
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
        else if (e == "soldier") {
            QPixmap e3("/Users/omar_bahgat/Documents/Game/soldierL.png");
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
        else if (e == "soldier") {
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

void room3::shoot(){
    Projectile2 * proj = new Projectile2(last);
    proj->setPos(x()+30,y()+10);
    scene()->addItem(proj);
}
