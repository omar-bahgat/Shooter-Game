#include "player.h"
#include "Projectile.h"
#include <QGraphicsScene>
#include <QKeyEvent>
player::player(int dataitem [20][35])
{
   row=2;
   column=1;
   QPixmap p("/Users/omar_bahgat/Documents/Game/amongR.png");
   p=p.scaledToWidth(40);
   p=p.scaledToHeight(40);
   setPixmap(p);
   setPos(0+40*column,40+40*row);
   for(int i=0;i<20;i++)
       for (int j=0;j<35;j++)
           data[i][j]=dataitem[i][j];
}

void player::keyPressEvent(QKeyEvent* event)
{
    if(event->key()==Qt::Key_Up && data[row-1][column]!=-11 && data[row-1][column]!=-12 && data[row-1][column]!=-13 && data[row-1][column]!=-14)
    {
        QPixmap p("/Users/omar_bahgat/Documents/Game/amongU.png");
        p=p.scaledToWidth(40);
        p=p.scaledToHeight(40);
        setPixmap(p);
        row--;
        setPos(40+40*column,40+40*row);
        last = 10;
    }
    else if(event->key()==Qt::Key_Down && data[row+1][column]!=-11 && data[row+1][column]!=-12 && data[row+1][column]!=-13 && data[row+1][column]!=-14)
    {
        QPixmap p("/Users/omar_bahgat/Documents/Game/amongdown.png");
        p=p.scaledToWidth(40);
        p=p.scaledToHeight(40);
        setPixmap(p);
        row++;
        setPos(40+40*column,40+40*row);
        last = 20;
    }
    else if(event->key()==Qt::Key_Left && data[row][column-1]!=-11 && data[row][column-1]!=-12 && data[row][column-1]!=-13 && data[row][column-1]!=-14)
    {
        QPixmap p("/Users/omar_bahgat/Documents/Game/amongL.png");
        p=p.scaledToWidth(40);
        p=p.scaledToHeight(40);
        setPixmap(p);
        column--;
         setPos(40+40*column,40+40*row);
         last = 5;
    }
    else if(event->key()==Qt::Key_Right && data[row][column+1]!=-11 && data[row][column+1]!=-12 && data[row][column+1]!=-13 && data[row][column+1]!=-14)
    {
        QPixmap p("/Users/omar_bahgat/Documents/Game/amongR.png");
        p=p.scaledToWidth(40);
        p=p.scaledToHeight(40);
        setPixmap(p);
        column++;
         setPos(40+40*column,40+40*row);
         last = 15;
    }
    else if(event->key()==Qt::Key_Space){
        Projectile * proj = new Projectile(last,data);
        proj->setPos(x()+30,y()+10);
        scene()->addItem(proj);
    }

}
