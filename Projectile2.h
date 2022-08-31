#ifndef PROJECTILE2_H
#define PROJECTILE2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Projectile2: public QObject, public QGraphicsPixmapItem  {
    Q_OBJECT;
private:
    int lastMove;
public:
    Projectile2(int last, QGraphicsItem * parent = 0);
public slots:
    void move();
};

#endif // PROJECTILE2_H
