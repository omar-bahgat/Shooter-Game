#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Projectile: public QObject, public QGraphicsPixmapItem  {
    Q_OBJECT;   // add macro
private:
    int lastMove;
    int data[20][35];
public:
    Projectile(int last, int [20][35], QGraphicsItem * parent = 0);
    int static health;

public slots:
    void move();
};

#endif // PROJECTILE_H
