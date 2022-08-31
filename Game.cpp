#include <Game.h>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QFont>
#include "player.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Score.h"
#include "Projectile2.h"
#include <room3.h>
#include <QMediaPlayer>
#include <QAudioOutput>


Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(40,40,1400,800);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1400,800);


    QFile file("/Users/omar_bahgat/Documents/Game/board3.txt");
    file.open(QIODevice::ReadOnly);

    QTextStream stream(&file);
    int boarddata[20][35];

    QString temp;
    for (int i=0;i<20;i++)
        for (int j=0;j<35;j++){
         stream>>temp;
         boarddata[i][j]=temp.toInt();
        }


    QPixmap lava("/Users/omar_bahgat/Documents/Game/lava.png");
    QPixmap bricks("/Users/omar_bahgat/Documents/Game/bricks.png");
    QPixmap v1("/Users/omar_bahgat/Documents/Game/v1.png");
    QPixmap v2("/Users/omar_bahgat/Documents/Game/v2.png");
    QPixmap v3("/Users/omar_bahgat/Documents/Game/v3.png");
    QPixmap v4("/Users/omar_bahgat/Documents/Game/v4.png");

    lava=lava.scaledToWidth(40);
    lava=lava.scaledToHeight(40);
    bricks=bricks.scaledToWidth(40);
    bricks=bricks.scaledToHeight(40);
    v1=v1.scaledToWidth(45);
    v1=v1.scaledToHeight(45);
    v2=v2.scaledToWidth(45);
    v2=v2.scaledToHeight(45);
    v3=v3.scaledToWidth(45);
    v3=v3.scaledToHeight(45);
    v4=v4.scaledToWidth(45);
    v4=v4.scaledToHeight(45);



    for (int i=0;i<20;i++)
       for (int j=0;j<35;j++)
       {
           if(boarddata[i][j]== -11 || boarddata[i][j]== -12 || boarddata[i][j]== -13 || boarddata[i][j]== -14)
               dataimage[i][j].setPixmap(lava);
           else if(boarddata[i][j] == -01 ||boarddata[i][j] == 99)
               dataimage[i][j].setPixmap(bricks);
           else if(boarddata[i][j] == -15)
                   dataimage[i][j].setPixmap(v1);
           else if(boarddata[i][j] == -16)
               dataimage[i][j].setPixmap(v2);
           else if(boarddata[i][j] == -17)
               dataimage[i][j].setPixmap(v3);
           else if(boarddata[i][j] == -18)
               dataimage[i][j].setPixmap(v4);

           dataimage[i][j].setPos(40+40*j,40+40*i);
           scene->addItem(&dataimage[i][j]);
       }

    p = new player(boarddata);
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
    scene->addItem(p);

    QString x = "gunman";
    QString y = "archer";
    QString z = "soldier";
    QString h = "police";

    QString x2 = "gunman";
    QString y2 = "archer";
    QString z2 = "soldier";
    QString h2 = "police";

    e1 = new Enemy(boarddata,x);
    scene->addItem(e1);
    e2 = new Enemy(boarddata,y);
    scene->addItem(e2);
    e3 = new Enemy2(boarddata,z);
    scene->addItem(e3);
    e4 = new Enemy2(boarddata,h);
    scene->addItem(e4);
    e5 = new room3(boarddata,x2);
    scene->addItem(e5);
    e6 = new room3(boarddata,y2);
    scene->addItem(e6);
    e7 = new room3(boarddata,z2);
    scene->addItem(e7);
    e8 = new room3(boarddata,h2);
    scene->addItem(e8);

//     health = new Health();
//     health->setPos(40,40);
//     scene->addItem(health);



    scene->setStickyFocus(true);


    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * audioOutput = new QAudioOutput();
    music->setAudioOutput(audioOutput);
    music->setSource(QUrl::fromLocalFile("/Users/omar_bahgat/Documents/Game/background2.mp3"));
    audioOutput->setVolume(1);
    music->play();


    show();
}
