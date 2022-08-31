#include <Projectile.h>
#include <Enemy.h>
#include <Enemy2.h>
#include <room3.h>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QList>
#include <Score.h>
#include <Game.h>


//extern Game * game;

Projectile::Projectile(int last,int dataitem [20][35], QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent){
    lastMove = last;

    //draw bullet
    QPixmap bullet("/Users/omar_bahgat/Documents/Game/bullet2.png");
    bullet=bullet.scaledToWidth(12);
    bullet=bullet.scaledToHeight(12);
    setPixmap(bullet);

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));     //move function will be called periodically every 15ms
    timer->start(10);
    for(int i=0;i<20;i++)
        for (int j=0;j<35;j++)
            data[i][j]=dataitem[i][j];

}

void Projectile::move(){

    QList <QGraphicsItem *> collidingObjects = collidingItems();
    for (int i = 0, n = collidingObjects.size(); i < n; ++i){
        if(typeid(*(collidingObjects[i])) == typeid(Enemy) || typeid(*(collidingObjects[i])) == typeid(Enemy2) || typeid(*(collidingObjects[i])) == typeid(room3) ){
            scene()->removeItem(collidingObjects[i]);
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
    else if (lastMove == 10)
        setPos(x(),y()-5);
    else if (lastMove == 20)
        setPos(x(),y()+5);

//if (data[int(y()-60)/40][int(x())/40] == -11 || data[int(y()-60)/40][int(x())/40] == -12 || data[int(y()-60)/40][int(x()/40)] == -13 || data[int(y()-60)/40][int(x()/40)] == -14){
 if (pos().x() > 800 || (pos().x() > 0 && pos().x() < 720 && pos().y() ==240) || (pos().x() > 40 && pos().x() < 800 && pos().y() ==485) ) {
    //scene()->removeItem(this);
delete this;
 }

}
